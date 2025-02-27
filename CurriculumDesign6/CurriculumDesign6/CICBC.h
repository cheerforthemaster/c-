#pragma once
#include <iostream>
#include "CMyAccount.h"
#include <fstream>
#include <string>
using namespace std;

class CICBC :public CMyAccount
{
public:
	CICBC();
	// 参数说明：ptSourceA[in]-转帐源方；
	//           ptDestA[in] - 转帐目的方；
	//           sum[in]    - 转帐金额
	//           ptNote[in]  - 备注
	// 功能举例：从银行取钱时，就需要执行转帐操作：从某个银行帐号转入到现金帐号中。
	long Transfer(CMyAccount *ptSourceA, CMyAccount *ptDestA, double sum, CString ptNote);
	// 参数说明：inType[in]-收入类型：例如奖学金、勤工俭学、父母支助等。可根据实际情况添加。
	long Income(CString inType, double sum, CString ptNote);
	// 参数说明：conType[in]-支出类型：食物、衣物、学费、书籍等。可根据实际情况添加。
	long Consume(CString conType, double sum, CString ptNote);
	// 参数说明：conType[in]-支出类型：食物、衣物、学费、书籍等。可根据实际情况添加。
	// 功能说明：统计某个时间段内的收支情况，结果有收支总体情况和各种子类的具体数据。
	long Statistic(CString &bankofChinaaccount);

private:
	double balance;

};
