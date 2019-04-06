#pragma once
#include <stdio.h>  
#include <stdlib.h>  
#include <windows.h>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
// typedef struct tagRGBQUAD
// {
// 	char    rgbBlue;
// 	char    rgbGreen;
// 	char    rgbRed;
// 	char    rgbReserved; //��������0
// };

class CompressBmp
{
public:
	CompressBmp();
	~CompressBmp();
	bool ReadBitmap(const char* filename);
	bool WriteBitmap(const char* filename);
	int Compress();
	bool UnCompress();
private:
	int BitLength(unsigned char i);
	void Traceback(int n, int & i);
	bool deformation();//��m_data����
	struct stat buf;//��ʾ�ļ�״̬��Ϣ;
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
	tagRGBQUAD* RGBArrary;
	unsigned char* m_data;//���ص����Ϣ
	char* rest;//������ֽ�
	int rest_size;
	int *sum;//�ֶ���Ϣ
	unsigned short *bit;//��¼��Ӧ���ص��λ��
	int *len;//�������ص����
	int paragraph;//������
};