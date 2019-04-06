#ifndef CMYACCOUNT
#define CMYACCOUNT

#include <iostream>
#include <cstring>
#include <afx.h>
using namespace std;

struct TimeStamp_STRU;

class CMyAccount
{
public:
	// ����˵����ptSourceA[in]-ת��Դ����
	//           ptDestA[in] - ת��Ŀ�ķ���
	//           sum[in]    - ת�ʽ��
	//           ptNote[in]  - ��ע
	// ���ܾ�����������ȡǮʱ������Ҫִ��ת�ʲ�������ĳ�������ʺ�ת�뵽�ֽ��ʺ��С�
	virtual long Transfer(CMyAccount *ptSourceA, CMyAccount *ptDestA, double sum, CString ptNot) = 0;
	// ����˵����inType[in]-�������ͣ����罱ѧ���ڹ���ѧ����ĸ֧���ȡ��ɸ���ʵ�������ӡ�
	virtual long Income(CString inType, double sum, CString ptNote) = 0;
	// ����˵����conType[in]-֧�����ͣ�ʳ����ѧ�ѡ��鼮�ȡ��ɸ���ʵ�������ӡ�
	virtual long Consume(CString conType, double sum, CString ptNote) = 0;
	// ����˵����conType[in]-֧�����ͣ�ʳ����ѧ�ѡ��鼮�ȡ��ɸ���ʵ�������ӡ�
	// ����˵����ͳ��ĳ��ʱ����ڵ���֧������������֧��������͸�������ľ������ݡ�
	virtual long Statistic(CString &bankofChinaaccount) = 0;

	CString GetTime();
private:
	double balance;
};
#endif // !CMYACCOUNT
