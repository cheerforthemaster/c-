
#include "Cdecompose_String.h"

Decompose::Decompose()//��Result��ʼ��Ϊ��
{
	Result = NULL;
	Str_Num = 0;
}

CString Decompose::decom(CString &tem1, CString &tem2, CString &tem3)//��Դ�ļ��е��ַ����ֽ�   �������ļ�����Դ�ļ��е��ַ������ֽ����ַ���
{
	fstream myfile;
	myfile.open(tem1);//1.txt 2.txt 3.txt ��Ӧ 1_result.txt 2_result.txt 3_result.txt
	myfile.seekg(0, ios::end);
	int file_size = myfile.tellg();
	myfile.seekg(0, ios::beg);
	char* File = new char[file_size];//��Ҫdelete-------
	File = "\0";
	myfile.read(File, file_size); //��Դ�ļ����ַ��������浽char *File��
	tem2.Format(_T("%s"), File);//��Դ�ļ����ַ�����Edit�ؼ��ı���

	//������ж��ٸ�����Ҫ������ִ�
	for (int i = 1; i < file_size; i++)//��1��ʼ��Ϊ�˷�ֹ�����if�еĵڶ�������Խ�硪����������
	{                                  //                                             |
		if (48 <= File[i] <= 57 &&//��ǰ�����е�Ԫ��Ϊ����                              |
			48 <= File[i - 1] <= 57 &&//��ǰ��һ�������е�Ԫ��Ҳ������             <����������
			48 > File[i + 1] || File[i + 1] > 57)//������һ�������е�Ԫ�ز�������
			Str_Num++;
	}

	Result = new int[Str_Num];//��Ҫdelete---------
	Result = 0;

	char *temporary = new char[file_size];//��Ҫdelete--------
	for (int i = 0, k = 0; i < file_size; i++, k++)
	{
		temporary = "\0";
		if (48 <= File[i] <= 57 &&//��ǰ�����е�Ԫ��Ϊ����
			48 <= File[i + 1] <= 57)//������һ�������е�Ԫ��Ҳ������
		{
			for (int j = 0; j < file_size; j++)
			{
				if (48 <= File[i] <= 57)//��ǰ�����е�Ԫ��Ϊ����
				{
					temporary[j] = File[i];//�ݴ浽temporary
					i++;
				}
				else
					break;
			}
			Result[k] = atoi(temporary);
		}
	}

	tem3 = Str_Num + "\r\n";
	for (int k = 0; k < Str_Num; k++)
		tem3 +=  Result[k] + "\r\n";

	delete[]File;
	delete[]temporary;
	return tem3;
}

Decompose::~Decompose()//delete
{
	delete[]Result;
}
