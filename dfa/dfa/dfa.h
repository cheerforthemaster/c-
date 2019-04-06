#pragma once
#include <map>
#include "nfa.h"
using namespace std;

int Number = 0;

class dfaNode
{
public:
	void addNext(char word, int nextNum)
	{
		next[word].push_back(nextNum);
	}
	vector<int> num;//µ±Ç°×´Ì¬±àºÅ
	map<char,vector<int>> next;	
};

class dfa
{
public:
	dfa(nfa & Nfa);

private:
	void transform(nfa &Nfa);
	int transform(nfaNode* preNode,char word);
	vector<dfaNode*> nodes;
	dfaNode* preNode;
	bool isRepeat(vector<int> order,vector<int> preVec);
};

dfa::dfa(nfa & Nfa)
{
	preNode = new dfaNode();
	preNode->num.push_back(Nfa.frist->num);
	nodes.push_back(preNode);
	transform(Nfa);
}

inline void dfa::transform(nfa & Nfa)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = 0; j < allword.size(); j++)
		{
			for (int k = 0; k < nodes[i]->num.size(); k++)
			{
				preNode = nodes[i];
				if (allNode[nodes[i]->num[k]]!=NULL)
				{
					transform(allNode[nodes[i]->num[k]], allword[j]);
				}
				
			}

			dfaNode* temNode = new dfaNode();
			if (nodes[i]->next[allword[j]].size() != 0)
			{
				bool is = false;
				for (int n = 0; n < nodes.size(); n++)
				{
					is = is || isRepeat(nodes[n]->num, nodes[i]->next[allword[j]]);
				}
				if (!is)
				{
					for (int m = 0; m < nodes[i]->next[allword[j]].size(); m++)
					{
						temNode->num.push_back(nodes[i]->next[allword[j]][m]);
					}
					nodes.push_back(temNode);
				}
			}		
		}

	}

	cout << endl;
	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = 0; j < nodes[i]->num.size(); j++)
		{
			cout << nodes[i]->num[j] << " ";
		}
		for (int j = 0; j < allword.size(); j++)
		{
			cout << allword[j] << ": ";
			for (int k = 0; k < nodes[i]->next[allword[j]].size(); k++)
			{
				cout << nodes[i]->next[allword[j]][k] << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = 0; j < nodes.size(); j++)
		{
			bool is = true;
			for (int k = 0; k < allword.size(); k++)
			{
				is = is&& isRepeat(nodes[i]->next[allword[k]], nodes[j]->next[allword[k]]);
			}
			if (is&&i!=j)
			{
				for (int m = 0; m < nodes[j]->num.size(); m++)
				{
					bool has = false;
					for (int n = 0; n < nodes[i]->num.size(); n++)
					{
						if (nodes[i]->num[n]== nodes[j]->num[m])
						{
							has = true;
							break;
						}
					}
					if (!has)
					{
						nodes[i]->num.push_back(nodes[j]->num[m]);						
					}
				}		
			}
		}
	}

	vector<int> tem;
	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = i + 1; j < nodes.size(); j++)
		{
			if (isRepeat(nodes[i]->num, nodes[j]->num)&&i!=j)
			{
				tem.push_back(j);
				nodes[j]->num.clear();
			}
		}
	}

	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i]->num.size() == 0)
		{
			nodes.erase(nodes.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = 0; j < nodes.size(); j++)
		{
			for (int k = 0; k < allword.size(); k++)
			{
				if (isRepeat(nodes[j]->num,nodes[i]->next[allword[k]]))
				{
					nodes[i]->next[allword[k]].clear();
					nodes[i]->next[allword[k]].push_back(j);
				}
			}
		}
	}

	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->num.clear();
		nodes[i]->num.push_back(i);
	}

	cout << endl;
	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = 0; j < nodes[i]->num.size(); j++)
		{
			cout << nodes[i]->num[j] << " ";
		}
		for (int j = 0; j < allword.size(); j++)
		{
			cout << allword[j] << ": ";
			for (int k = 0; k < nodes[i]->next[allword[j]].size(); k++)
			{
				cout << nodes[i]->next[allword[j]][k] << " ";
			}
		}
		cout << endl;
	}

// 	for (int i = 0; i < allword.size(); i++)
// 	{
// 		for (int j = 0; j < nodes.size(); j++)
// 		{
// 			for (int k = 0; k < nodes.size(); k++)
// 			{
// 				if (isRepeat(nodes[k]->num, nodes[j]->next[allword[i]]))
// 				{
// 					nodes[j]->next[allword[i]].clear();
// 					nodes[j]->next[allword[i]].push_back(k);
// 				}
// 			}
// 		}
// 	}
// 	for (int i = 0; i < nodes.size(); i++)
// 	{
// 		nodes[i]->num.clear();
// 		nodes[i]->num.push_back(i);
// 	}
// 	cout << endl;
// 	for (int i = 0; i < nodes.size(); i++)
// 	{
// 		cout << nodes[i]->num[0] << "  ";
// 		for (int j = 0; j < allword.size(); j++)
// 		{
// 			if (nodes[i]->next[allword[j]].size() != 0)
// 			{
// 				cout << allword[j] <<":"<< nodes[i]->next[allword[j]][0]<<"  ";
// 			}
// 		}
// 		cout << endl;
// 	}
}

inline int dfa::transform(nfaNode * prenfa,char word)
{
	if (prenfa==NULL)
	{
		return 0;
	}
	for (int i = 0; i < prenfa->next.size(); i++)
	{		
		if (prenfa->word==word)
		{
			bool is = false;
			for (int j = 0; j < this->preNode->next[word].size(); j++)
			{
				if (this->preNode->next[word][j] == prenfa->next[i]->num)
				{
					is = true;
					break;
				}
			}
			if (!is)
			{
				this->preNode->next[word].push_back(prenfa->next[i]->num);
			}
			continue;
		}
		else
		{
			if (prenfa->word == nul)
			{
// 				bool is = false;
// 				for (int j = 0; j < this->preNode->next[word].size(); j++)
// 				{
// 					if (this->preNode->next[word][j] == prenfa->next[i]->num)
// 					{
// 						is = true;
// 						break;
// 					}
// 				}
// 				if (!is)
// 				{
// 					this->preNode->next[word].push_back(prenfa->next[i]->num);
// 				}
				transform(prenfa->next[i], word);
			}
		}
	}
	return 0;
}

inline bool dfa::isRepeat(vector<int> order,vector<int> preVec)
{
	bool repeat = false;

	for (int i = 0; i < preVec.size(); i++)
	{
		repeat = false;
		for (int j = 0; j < order.size(); j++)
		{
			if (order[j] == preVec[i])
			{
				repeat = true;
				break;
			}
		}
		if (!repeat)
		{
			break;
		}
	}
	if (repeat)
	{
		return repeat;
	}
	return false;
}
