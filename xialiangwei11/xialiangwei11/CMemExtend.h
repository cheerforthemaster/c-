#include <iostream>
#include <string>
using namespace std;

class CMemExtend
{
public:
	CMemExtend()
	{
		m_pvBuf = NULL;
		m_ICurBytesNum = 0;
		Content_Size = 0;
	}
	void GetContent()//获取内容
	{
		cout << "请输入内容：" << endl;
		cin >> Content;
		Content_Size = Content.length();//内容所占的内存大小
	}

	void*GetMemBuf(long lMenSize)
	{
		cout << "请输入所需内存大小（即多少字节）：" << endl;
		cin >> lMenSize;

		if (lMenSize >= Content_Size)//用户指定的内存大小大于或等于所需内存
		{
			m_ICurBytesNum = lMenSize;
			m_pvBuf = new char[m_ICurBytesNum];//申请用户指定大小的内存
			strcpy_s(m_pvBuf, m_ICurBytesNum, Content.c_str());
			return m_pvBuf;
		}
		else
		{
			m_ICurBytesNum = Content_Size+1;
			m_pvBuf = new char[m_ICurBytesNum];//申请内容所占的内存大小
			strcpy_s(m_pvBuf, m_ICurBytesNum, Content.c_str());
			return m_pvBuf;
		}
	}

	void Read()
	{
		cout << "所占的内存大小： " << m_ICurBytesNum << endl;
		cout << "输出内容：" << endl;
		for (int i = 0; i < m_ICurBytesNum; i++)
			cout << m_pvBuf[i];
		cout << endl;
	}

	~CMemExtend()
	{
		delete[]m_pvBuf;
	}
private:
	char *m_pvBuf;
	long m_ICurBytesNum;
	unsigned int Content_Size;
	string Content;
};
