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
// 	char    rgbReserved; //保留，置0
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
	bool deformation();//将m_data变形
	struct stat buf;//显示文件状态信息;
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
	tagRGBQUAD* RGBArrary;
	unsigned char* m_data;//像素点的信息
	char* rest;//多余的字节
	int rest_size;
	int *sum;//分段信息
	unsigned short *bit;//记录相应像素点的位数
	int *len;//段中像素点个数
	int paragraph;//段落数
};