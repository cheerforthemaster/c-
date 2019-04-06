
#include "Cdecompose_String.h"

Decompose::Decompose()//将Result初始化为空
{
	Result = NULL;
	Str_Num = 0;
}

CString Decompose::decom(CString &tem1, CString &tem2, CString &tem3)//将源文件中的字符串分解   参数：文件名；源文件中的字符串；分解后的字符串
{
	fstream myfile;
	myfile.open(tem1);//1.txt 2.txt 3.txt 对应 1_result.txt 2_result.txt 3_result.txt
	myfile.seekg(0, ios::end);
	int file_size = myfile.tellg();
	myfile.seekg(0, ios::beg);
	char* File = new char[file_size];//需要delete-------
	File = "\0";
	myfile.read(File, file_size); //将源文件的字符串，保存到char *File中
	tem2.Format(_T("%s"), File);//将源文件的字符串给Edit控件的变量

	//计算出有多少个符合要求的数字串
	for (int i = 1; i < file_size; i++)//从1开始是为了防止下面的if中的第二个条件越界——————
	{                                  //                                             |
		if (48 <= File[i] <= 57 &&//当前格子中的元素为数字                              |
			48 <= File[i - 1] <= 57 &&//它前面一个格子中的元素也是数字             <—————
			48 > File[i + 1] || File[i + 1] > 57)//它后面一个格子中的元素不是数字
			Str_Num++;
	}

	Result = new int[Str_Num];//需要delete---------
	Result = 0;

	char *temporary = new char[file_size];//需要delete--------
	for (int i = 0, k = 0; i < file_size; i++, k++)
	{
		temporary = "\0";
		if (48 <= File[i] <= 57 &&//当前格子中的元素为数字
			48 <= File[i + 1] <= 57)//它后面一个格子中的元素也是数字
		{
			for (int j = 0; j < file_size; j++)
			{
				if (48 <= File[i] <= 57)//当前格子中的元素为数字
				{
					temporary[j] = File[i];//暂存到temporary
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
