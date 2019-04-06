#include <iostream>
#include "CBase.h"
#include "CBook.h"
using namespace std;

class CReader:public CBase
{
public:
	CReader(char readername[20],int r_number):CBase(readername, r_number)
	{
		book_number = 0;
		cout << "读者";
		show();
	}
	void rentbook(CBook a)
	{
		if (book_number > 5)
			cout << "已借五本书，若要继续借书，请先归还已借的书" << endl;
		else
		{
			book[book_number] = a;
			book_number=book_number+1;
		}
	}
	void showreader()
	{
		cout << "所借图书：" << endl;
		for (int i = 0; i < book_number; i++)
		{		
			cout << i + 1 << " : ";
			book[i].show();
		}
	}
private:
	char reader_name[20];
	int number;
	int book_number;
	CBook book[5];
};
