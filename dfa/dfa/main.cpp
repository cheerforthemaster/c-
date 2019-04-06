#include <iostream>
#include "suffix.h"
#include "nfa.h"
#include "dfa.h"
#include <stack>
using namespace std;

string txt = "a(a|b)*a|ba";

int main()
{
	stack<nfa> s_nfa;
	nfa *preNfa = NULL;
	nfa *lastNfa = NULL;
	vector<char> out = m_suffix(txt);
	for (int i = 0; i < out.size(); i++)
	{
		cout << out[i];
	}
	cout << endl;

	for (int i = 0; i < out.size(); i++)
	{
		if (isword(out[i]))
		{
			preNfa = new nfa(out[i]);
			s_nfa.push(*preNfa);
		}
		else
		{
			preNfa=&(s_nfa.top());
			s_nfa.pop();
			lastNfa = preNfa;
			if (out[i]!='*')
			{
				lastNfa = &(s_nfa.top());
				s_nfa.pop();
			}
			lastNfa->merge(*preNfa, out[i]);
			s_nfa.push(*lastNfa);
			preNfa = lastNfa;
		}
	}
	preNfa->out();
	dfa one(*preNfa);

	system("pause");
	return 0;
}