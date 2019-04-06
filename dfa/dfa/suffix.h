#pragma once
#include <vector>
#include <stack>
#include <map>
using namespace std;
//中缀转后缀
//添加连接符 .
//符号优先级从大到小 * . |


bool isword(char word)//是否是字符
{
	if (word != '*'&&word != '+'&&word != '('&&word != ')'&&word != '|'&&word != '.')
	{
		return true;
	}
	return false;
}

vector<char> m_suffix(string txt)
{
	map<char, int> priority;
	priority['*'] = 3;
	priority['.'] = 2;
	priority['|'] = 1;
	priority['('] = 0;
	vector<char> temWord;//中缀表达式
	vector<char> suffixWord;//后缀表达式
	stack<char> symbol;//符号栈
	bool need = false;//是否需要加入连接符 .
	for (int i = 0; i < txt.length(); i++)
	{
		if (i+1<txt.length())//下一个char是否是字符
		{
			if (isword(txt.at(i)) && (isword(txt.at(i + 1)) || txt.at(i + 1) == '('))//当前为字符，后边为字符或 (
			{
				need = true;
			}
			if (txt.at(i) == '*'&&txt.at(i + 1) != '|'&&txt.at(i + 1) != ')')//当前为*，后边不是 |和)
			{
				need = true;
			}
			if (txt.at(i) == ')'&&(txt.at(i + 1) == '(' || isword(txt.at(i + 1))))//当前是)，后边是( 或 字符
			{
				need = true;
			}
		}
		temWord.push_back(txt.at(i));
		if (need)
		{
			temWord.push_back('.');
		}
		need = false;
	}

	for (int i = 0; i < temWord.size(); i++)
	{
		cout << temWord[i];
	}
	cout << endl;


	char tem;
	for (int i = 0; i < temWord.size(); i++)
	{
		if (isword(temWord[i]))//字符直接输出
		{
			suffixWord.push_back(temWord[i]);
		}
		else//符号压栈，若栈顶符号优先级不小于当前符号，出栈，（ 只有遇到 ）才出栈
		{
 			if (temWord[i] == '(')
 			{
 				symbol.push(temWord[i]);
 				continue;
 			}
			if (temWord[i] == ')')
			{
				tem = symbol.top();
				while (tem != '(')
				{
					suffixWord.push_back(tem);
					symbol.pop();
					tem = symbol.top();
				}
				symbol.pop();
				continue;
			}
			if (symbol.size() != 0)
			{
				tem = symbol.top();
				while (priority[tem] >= priority[temWord[i]]&& symbol.size() != 0)
				{
					tem = symbol.top();
					suffixWord.push_back(tem);
					symbol.pop();
				}
				symbol.push(temWord[i]);
			}
			else 
			{
				symbol.push(temWord[i]);
			}
		}

	}
	while (symbol.size() != 0)
	{
		tem = symbol.top();
		suffixWord.push_back(tem);
		symbol.pop();
	}
	return suffixWord;
}