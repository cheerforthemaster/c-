#include "CompressBmp.h"

CompressBmp::CompressBmp()
{
	RGBArrary = NULL;
	m_data = NULL;
	rest = NULL;
	sum = NULL;
	bit = NULL;
	len = NULL;
	rest_size = 0;
	paragraph = 0;
}

CompressBmp::~CompressBmp()
{
	if (RGBArrary != NULL)
	{
		delete[]RGBArrary;
		RGBArrary = NULL;
	}
	if (m_data != NULL)
	{
		delete[]m_data;
		m_data = NULL;
	}
	if (rest != NULL)
	{
		delete[]rest;
		rest = NULL;
	}
	if (sum != NULL)
	{
		delete[]sum;
		sum = NULL;
	}
	if (bit != NULL)
	{
		delete[]bit;
		bit = NULL;
	}
	if (len != NULL)
	{
		delete[]len;
		len = NULL;
	}
}

bool CompressBmp::ReadBitmap(const char * filename)
{
	fstream file(filename, ios::in | ios::binary);
	file.read(reinterpret_cast<char*>(&fileHeader), sizeof(BITMAPFILEHEADER));//��λ���ļ�ͷ
	file.read(reinterpret_cast<char*>(&infoHeader), sizeof(BITMAPINFOHEADER));//��λ����Ϣͷ
	if (infoHeader.biBitCount <= 0)
		return false;
	int size = infoHeader.biHeight*infoHeader.biWidth;
	RGBArrary = new tagRGBQUAD[infoHeader.biClrUsed];
	file.read(reinterpret_cast<char*>(RGBArrary), infoHeader.biClrUsed*4);
	m_data = new unsigned char[size];
	file.read((char*)(m_data), size);
	stat(filename, &buf);
	rest_size = buf.st_size - file.tellg();
	if (rest_size != 0)
	{
		rest = new char[rest_size];
		file.read(rest, rest_size);
	}
	file.close();
	return false;
}

bool CompressBmp::WriteBitmap(const char * filename)
{
	fstream file(filename, ios::out | ios::binary);
	file.write(reinterpret_cast<char*>(&fileHeader), sizeof(BITMAPFILEHEADER));
	file.write(reinterpret_cast<char*>(&infoHeader), sizeof(BITMAPINFOHEADER));
	file.write(reinterpret_cast<char*>(RGBArrary), infoHeader.biClrUsed*4);
	int size = infoHeader.biHeight*infoHeader.biWidth;
	file.write((char*)(m_data), size);
	if (rest_size != 0 && rest != NULL)
	{
		file.write(rest, rest_size);
	}
	file.close();
	return false;
}

int CompressBmp::BitLength(unsigned char i)
{
	int k = 0;
	if (i == 0)
		return 1;
	while (i != 0)
	{
		i = i >> 1;
		k++;
	}
	return k;
}

void CompressBmp::Traceback(int n, int& i)
{
 	if (n == 0)
 		return;
 	Traceback(n - len[n], i);
 	sum[i++] = n - len[n];//����Ϊsum[]���鸳ֵ�������洢�ֶ�λ��  
	//vector<int> num;
	//while (n != 0)
	//{
	//	num.insert(num.begin(), n - len[n]);
	//	n = n - len[n];
	//	i++;
	//}
	//for (int j = 1; j < i; j++)
	//{
	//	sum[j] = num[j];
	//}
}

bool CompressBmp::deformation()
{
	int size = infoHeader.biHeight*infoHeader.biWidth;
	//ÿ���256������;ͷ��ϢΪ11λ
	unsigned char*temData = new unsigned char[size];
	bool down = false;//ֱ������
	for (int i = 0, j = 0; i < size; i++, j++)//��Ϊ����
	{
		if ((i / infoHeader.biWidth) % 2 != 0)//�ӵ�0�п�ʼ��������������ֱ�ӴӸ��к��濪ʼ��
			down = true;
		else
			down = false;
		if (down)
		{
			i = i + infoHeader.biWidth - 1;
			for (int k = 0; k < infoHeader.biWidth; k++, i--)
			{
				temData[j] = m_data[i];
				j++;
			}
			i = i + infoHeader.biWidth;
			j--;
		}
		else
		{
			temData[j] = m_data[i];
		}
	}
	delete[]m_data;
	m_data = NULL;
	m_data = temData;
	return false;
}

int CompressBmp::Compress()
{
	int size = infoHeader.biHeight*infoHeader.biWidth;
	deformation();//��Ϊ����
 	fstream datafile("real_data.txt", ios::out | ios::binary);///////���Բ���
	datafile.write((char*)(m_data), size);
 	datafile.close();

	sum = new int[size];
	bit = new unsigned short[size];
	len = new int[size];
	sum[0] = 0;
	len[0] = 0;
	bit[0]=0;
	int bitMax = 0;
	for (int i = 1; i < size; i++)
	{
		bit[i] = BitLength(m_data[i - 1]);//�������ص�p��Ҫ�Ĵ洢λ��
		bitMax = bit[i];
		sum[i] = sum[i - 1] + bitMax;
		len[i] = 1;

		for (int j = 2; j <= min(i, 256); j++)
		{
			if (bitMax < bit[i - j + 1])
			{
				bitMax = bit[i - j + 1];
			}
			if (sum[i] > sum[i - j] + j*bitMax)
			{
				sum[i] = sum[i - j] + j*bitMax;
				len[i] = j;
			}
		}
		sum[i] += 11;
	}

	Traceback(size - 1, paragraph);
	for (int i = 1; i <= paragraph; i++)
	{
		len[i] = len[sum[i]];
		bit[i] = bit[sum[i]];
	}

	int prePos = 0;
	for (int i = 1; i <= paragraph; i++)
	{
		for (int j = 1; j <= len[i]; j++)
		{
			bitMax = BitLength(m_data[prePos]);
			bit[i] = (bitMax > bit[i]) ? bitMax : bit[i];
			prePos++;
		}
	}

	const char* filename = "out.img";///////////////////////////
	fstream file(filename, ios::out);
	file.close();
	file.open(filename, ios::out | ios::binary);
	file.write(reinterpret_cast<char*>(&fileHeader), sizeof(BITMAPFILEHEADER));
	file.write(reinterpret_cast<char*>(&infoHeader), sizeof(BITMAPINFOHEADER));
	file.write(reinterpret_cast<char*>(RGBArrary), infoHeader.biClrUsed * 4);
	file.write((char*)(&paragraph), 4);//�洢������

	short restBit = 32;//ʣ��λ��
	unsigned int storeBit = 0;//�����洢
	unsigned int mergeBit = 0;//�ϲ�len[i]��bit[i],����λ����Ϊ11λ
	for (int i = 1; i <= paragraph; i++)//�洢�ֶ���Ϣ
	{
		mergeBit = ((len[i]-1) << 3) | (bit[i] - 1);
		if (restBit >= 11)
		{
			restBit = restBit - 11;
			mergeBit = mergeBit << restBit;
			storeBit = storeBit | mergeBit;
		}
		else
		{
			storeBit = storeBit | (mergeBit >> (11 - restBit));
			file.write((char*)(&storeBit), 4);
			restBit = 32 - (11 - restBit);
			storeBit = mergeBit << restBit;
		}
	}
	if (restBit != 32)
	{
		file.write((char*)(&storeBit), 4);
	}

	restBit = 32;
	storeBit = 0;
	mergeBit = 0;
	int i = 1;
	int k = 0;
	while (i <= paragraph&&k < size)//�洢ԭ��Ϣ
	{
		for (int j = 0; j < len[i]; j++)
		{
			mergeBit = m_data[k];
			k++;
			if (k > size)
				break;
			if (restBit >= bit[i])
			{
				restBit = restBit - bit[i];
				mergeBit = mergeBit << restBit;
				storeBit = storeBit | mergeBit;
			}
			else
			{
				storeBit = storeBit | (mergeBit >> (bit[i] - restBit));
				file.write((char*)(&storeBit), 4);
				restBit = 32 - (bit[i] - restBit);
				storeBit = mergeBit << restBit;
			}
		}
		i++;
	}
	if (restBit != 32)
	{
		file.write((char*)(&storeBit), 4);
	}
	if (rest_size != 0)
	{
		file.write(rest, rest_size);
	}
	file.close();
	if (m_data != NULL)
	{
		delete[]m_data;
		m_data = NULL;
	}
	if (rest != NULL)
	{
		delete[]rest;
		rest = NULL;
	}
	if (sum != NULL)
	{
		delete[]sum;
		sum = NULL;
	}
	if (bit != NULL)
	{
		delete[]bit;
		bit = NULL;
	}
	if (len != NULL)
	{
		delete[]len;
		len = NULL;
	}
	return paragraph;
}

bool CompressBmp::UnCompress()
{
	const char* filename = "out.img";
	fstream file(filename, ios::in | ios::binary);
	if (!file.good())
		return false;
	file.read(reinterpret_cast<char*>(&fileHeader), sizeof(BITMAPFILEHEADER));
	file.read(reinterpret_cast<char*>(&infoHeader), sizeof(BITMAPINFOHEADER));
	RGBArrary = new tagRGBQUAD[infoHeader.biClrUsed];
	file.read(reinterpret_cast<char*>(RGBArrary), infoHeader.biClrUsed * 4);
	file.read((char*)(&paragraph), 4);//��ȡ������

	len = new int[paragraph];
	bit = new unsigned short[paragraph];

	unsigned int storeBit = 0;//�����洢��ȡ������
	file.read((char*)(&storeBit), 4);
	short restBit = 32;//ʣ��λ��
	unsigned int splitBit = 0;//�ó�һ��len[i]��bit[i],����λ����Ϊ11λ
	int i = 0;
	while (i < paragraph)//��ȡ�ֶ���Ϣ
	{
		while (restBit>=11)
		{
			splitBit = (storeBit << (32 - restBit)) >> 21;
			len[i] = (splitBit >> 3) + 1;
			bit[i] = ((splitBit << 29) >> 29) + 1;
			i++;
			if (i>=paragraph)
				break;
			restBit -= 11;
		}
		if (i >= paragraph)
			break;
		if (restBit == 0)
		{
			file.read((char*)(&storeBit), 4);
			restBit = 32;
			continue;
		}
		splitBit = (storeBit << (32 - restBit)) >> (32 - restBit);
		file.read((char*)(&storeBit), 4);
		splitBit = (splitBit << (11 - restBit)) | (storeBit >> (32 - (11 - restBit)));
		len[i] = (splitBit >> 3) + 1;
		bit[i] = ((splitBit << 29) >> 29) + 1;
		i++;
		restBit = 32 - (11 - restBit);
	}

	storeBit = 0;//�����洢��ȡ������
	file.read((char*)(&storeBit), 4);
	restBit = 32;//ʣ��λ��
	m_data = new unsigned char[infoHeader.biHeight*infoHeader.biWidth + 1];
	int j = 0;
	i = 0;
	int size = infoHeader.biHeight*infoHeader.biWidth;
	while (j < size)
	{
		for (int k = 0; k < len[i]; k++)
		{
			if (restBit >= bit[i])
			{
				m_data[j] = storeBit >> (32 - bit[i]);
				j++;
				if (j > size)
					break;
				storeBit = storeBit << bit[i];
				restBit -= bit[i];
			}
			else
			{

				m_data[j] = storeBit >> (32 - restBit);
				file.read((char*)(&storeBit), 4);
				m_data[j] = (m_data[j] << (bit[i] - restBit)) | (storeBit >> (32 - (bit[i] - restBit)));
				j++;
				storeBit = storeBit << (bit[i] - restBit);
				restBit = 32 - (bit[i] - restBit);
				if (j > size)
					break;
			}
		}
		i++;
	}
	stat(filename, &buf);
	rest_size = buf.st_size - file.tellg();
	if (rest_size != 0 && file.tellg() > 0)
	{
		rest = new char[rest_size];
		file.read(rest, rest_size);
	}

 	fstream datafile("test_data.txt", ios::out | ios::binary);///////���Բ���
 	datafile.write((char*)(m_data), size);
 	datafile.close();

	deformation();

	file.close();
	WriteBitmap("out.bmp");
	return false;
}

