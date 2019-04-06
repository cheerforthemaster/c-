#pragma once
#include <vector>
using namespace std;
//״̬nfa��ֻ��nfa���д���
//�ڵ�nfanode
// # Ϊ��

int now = -1;
char nul = '#';
vector<char> allword;

class nfaNode
{
public:
	nfaNode(int num, char word)
	{
		this->num = num;
		this->word = word;
	}

	int num;//��ǰ���
	char word;//������һ����Ҫ���ַ�
	vector<nfaNode*> next;
};

vector<nfaNode*> allNode;

class nfa
{
public:
	nfa(char word);//�ַ�nfa
	void merge(nfa next,char symbol);
	void out();
	nfaNode* frist;
	nfaNode* end;
};

nfa::nfa(char word)
{
	frist = new nfaNode(++now, word);
	allNode.push_back(frist);
	end = new nfaNode(++now, nul);
	frist->next.push_back(end);
	allNode.push_back(end);

	bool execute = 0;
	for (int i = 0; i < allword.size(); i++)
	{
		if (allword[i]==word)
		{
			execute = 1;
			break;
		}
	}
	if (!execute)
	{
		allword.push_back(word);
	}
}

inline void nfa::merge(nfa nextNFA, char symbol)
{
	if (symbol=='.')
	{
		end->next.push_back(nextNFA.frist);
		end = nextNFA.end;
	}
	if (symbol=='*')
	{
		nfaNode* newfrist = new nfaNode(++now, nul);
		allNode.push_back(newfrist);
		nfaNode* newend = new nfaNode(++now, nul);
		allNode.push_back(newend);
		newfrist->next.push_back(frist);
		newfrist->next.push_back(newend);
		end->next.push_back(frist);
		end->next.push_back(newend);
		frist = newfrist;
		end = newend;
	}
	if (symbol == '|')
	{
		nfaNode* newfrist = new nfaNode(++now, nul);
		allNode.push_back(newfrist);
		nfaNode* newend = new nfaNode(++now, nul);
		allNode.push_back(newend);
		newfrist->next.push_back(frist);
		newfrist->next.push_back(nextNFA.frist);
		end->next.push_back(newend);
		nextNFA.end->next.push_back(newend);
		frist = newfrist;
		end = newend;
	}
}

inline void nfa::out()
{
	cout << "��ʼ�ڵ�:" << frist->num << endl;
	for (int i = 0; i < allNode.size(); i++)
	{
		cout << allNode[i]->num << "  " << allNode[i]->word <<"  ";
		for (int j = 0; j < allNode[i]->next.size(); j++)
		{
			cout << allNode[i]->next[j]->num << "  ";
		}
		cout << endl;
	}
}

