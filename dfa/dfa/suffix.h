#pragma once
#include <vector>
#include <stack>
#include <map>
using namespace std;
//��׺ת��׺
//������ӷ� .
//�������ȼ��Ӵ�С * . |


bool isword(char word)//�Ƿ����ַ�
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
	vector<char> temWord;//��׺���ʽ
	vector<char> suffixWord;//��׺���ʽ
	stack<char> symbol;//����ջ
	bool need = false;//�Ƿ���Ҫ�������ӷ� .
	for (int i = 0; i < txt.length(); i++)
	{
		if (i+1<txt.length())//��һ��char�Ƿ����ַ�
		{
			if (isword(txt.at(i)) && (isword(txt.at(i + 1)) || txt.at(i + 1) == '('))//��ǰΪ�ַ������Ϊ�ַ��� (
			{
				need = true;
			}
			if (txt.at(i) == '*'&&txt.at(i + 1) != '|'&&txt.at(i + 1) != ')')//��ǰΪ*����߲��� |��)
			{
				need = true;
			}
			if (txt.at(i) == ')'&&(txt.at(i + 1) == '(' || isword(txt.at(i + 1))))//��ǰ��)�������( �� �ַ�
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
		if (isword(temWord[i]))//�ַ�ֱ�����
		{
			suffixWord.push_back(temWord[i]);
		}
		else//����ѹջ����ջ���������ȼ���С�ڵ�ǰ���ţ���ջ���� ֻ������ ���ų�ջ
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