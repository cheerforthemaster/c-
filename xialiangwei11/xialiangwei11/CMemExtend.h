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
	void GetContent()//��ȡ����
	{
		cout << "���������ݣ�" << endl;
		cin >> Content;
		Content_Size = Content.length();//������ռ���ڴ��С
	}

	void*GetMemBuf(long lMenSize)
	{
		cout << "�����������ڴ��С���������ֽڣ���" << endl;
		cin >> lMenSize;

		if (lMenSize >= Content_Size)//�û�ָ�����ڴ��С���ڻ���������ڴ�
		{
			m_ICurBytesNum = lMenSize;
			m_pvBuf = new char[m_ICurBytesNum];//�����û�ָ����С���ڴ�
			strcpy_s(m_pvBuf, m_ICurBytesNum, Content.c_str());
			return m_pvBuf;
		}
		else
		{
			m_ICurBytesNum = Content_Size+1;
			m_pvBuf = new char[m_ICurBytesNum];//����������ռ���ڴ��С
			strcpy_s(m_pvBuf, m_ICurBytesNum, Content.c_str());
			return m_pvBuf;
		}
	}

	void Read()
	{
		cout << "��ռ���ڴ��С�� " << m_ICurBytesNum << endl;
		cout << "������ݣ�" << endl;
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
