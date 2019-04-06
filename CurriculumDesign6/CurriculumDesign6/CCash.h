#pragma once
#include <iostream>
#include "CMyAccount.h"
#include <fstream>
#include <string>
using namespace std;

class CCash :public CMyAccount
{
public:
	CCash();
	// ����˵����ptSourceA[in]-ת��Դ����
	//           ptDestA[in] - ת��Ŀ�ķ���
	//           sum[in]    - ת�ʽ��
	//           ptNote[in]  - ��ע
	// ���ܾ�����������ȡǮʱ������Ҫִ��ת�ʲ�������ĳ�������ʺ�ת�뵽�ֽ��ʺ��С�
	long Transfer(CMyAccount *ptSourceA, CMyAccount *ptDestA, double sum, CString ptNote);
	// ����˵����inType[in]-�������ͣ����罱ѧ���ڹ���ѧ����ĸ֧���ȡ��ɸ���ʵ�������ӡ�
	long Income(CString inType, double sum, CString ptNote);
	// ����˵����conType[in]-֧�����ͣ�ʳ����ѧ�ѡ��鼮�ȡ��ɸ���ʵ�������ӡ�
	long Consume(CString conType, double sum, CString ptNote);
	// ����˵����conType[in]-֧�����ͣ�ʳ����ѧ�ѡ��鼮�ȡ��ɸ���ʵ�������ӡ�
	// ����˵����ͳ��ĳ��ʱ����ڵ���֧������������֧��������͸�������ľ������ݡ�
	long Statistic(CString &bankofChinaaccount);

private:
	double balance;

};
