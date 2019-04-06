#pragma pack(1)
#include <vector>
#include <set>
#include <iostream>
#include <math.h>
#include <algorithm>
#include "windows.h"
using namespace std;

vector<int> getNext(vector<char> pattern)
{
	vector<int> next(pattern.size(), 0);
	int i = 0;
	int j = -1;
	next[0] = -1;
	while (i < pattern.size() - 1)
	{
		if (j == -1 || pattern[i] == pattern[j])
		{
			i++;
			j++;
			if (pattern[i] != pattern[j])
			{
				next[i] = j;
			}
			else
				next[i] = next[j];
		}
		else
			j = next[j];
	}
	return next;
}

int match(vector<char> src, vector<char> pattern)
{
	vector<int> next = getNext(pattern);
	int j = 0;
	for (int i = 0; i < src.size(); i++)
	{
		if (src[i] == pattern[j])
		{
			j++;
			if (j>=pattern.size())
			{
				return i - pattern.size();
			}
			continue;
		}
		else
		{
			i = i + j - next[j];
			j = next[j] > 0 ? next[j] : 0;
		}
	}

	return -1;
}

vector<char> transf(string a) 
{
	vector<char> tem;
	for (int i = 0; i < a.length(); i++)
	{
		tem.push_back(a.at(i));
	}
	return tem;
}

int main()
{
	string a = "sabfcxzabudadhvlabdabec";
	string b = "abdabec";
	vector<char> src = transf(a);
	vector<char> pattern = transf(b);
	cout << match(src, pattern) << endl;
	system("pause");
	return 0;
}