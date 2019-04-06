#include <iostream>
#include "CBase.h"
using namespace std;
#ifndef CBOOK
#define CBOOK

class CBook:public CBase
{
public:
	CBook(){}
	CBook(char bookname[20],int number,char authorname[20]):CBase(bookname,number)
	{
		strcpy_s(author_name,20,authorname);
	}

private:
	char book_name[20];
	int num;//±àºÅ
	char author_name[20];
};
#endif // !CBOOK