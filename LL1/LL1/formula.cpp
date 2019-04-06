#include "formula.h"

formula::formula(string allwords)
{
	vector<char> oneRoute;
	this->name = allwords.at(0);
	for (int i = 3; i < allwords.length(); i++)
	{
		if (allwords.at(i)==' ')
		{
			continue;
		}
		if (allwords.at(i)=='|')
		{
			if (oneRoute.size()!=0)
			{
				route.push_back(oneRoute);
			}
			oneRoute.clear();
		}
		oneRoute.push_back(allwords.at(i));
	}
}

bool formula::getFirst()
{
	for (int i = 0; i < route.size(); i++)
	{
		for (int j = 0; j < route[i].size(); j++)
		{
			if (allFormula[route[i][j]]==NULL)
			{
				first.push_back(route[i][j]);
				break;
			}
			else
			{
				vector<char> tem = allFormula[route[i][j]]->first;
				if (tem.size()==0)
				{
					allFormula[route[i][j]]->getFirst();
					tem = allFormula[route[i][j]]->first;
				}
				bool nul = false;
				for (int k = 0; k < tem.size(); k++)
				{
					if (tem[k]=='@')
					{
						nul = true;
						continue;
					}
					else
					{
						first.push_back(tem[k]);
					}
				}
				if (nul)
				{
					if (j==route[i].size()-1)
					{
						first.push_back('@');
					}
					else
						continue;
				}
			}
		}
	}
	return false;
}

bool formula::getFollow()
{
	map<char, formula*>::reverse_iterator iter;
	formula* tem;
	for (iter = allFormula.rbegin(); iter != allFormula.rend(); iter++)
	{
		tem = iter->second;
		for (int i = 0; i < tem->route.size(); i++)
		{
			for (int j = 0; j < tem->route[i].size(); j++)
			{
				if (tem->route[i][j]==this->name)
				{
					if (j!=tem->route[i].size()-1)//不是最后一个
					{
						char next = tem->route[i][j + 1];
						if (allFormula[next] == NULL)//不是非终结符
						{
							this->follow.push_back(next);//直接添加
						}
						else
						{
							//是终结符，添加first集
							vector<char> nextFirst = allFormula[next]->first;
							for (int k = 0; k < nextFirst.size(); k++)
							{
								if (nextFirst[k]!='@')
								{
									this->follow.push_back(nextFirst[k]);
								}				
							}
						}
					}
					if (j== tem->route[i].size() - 1)
					{
						tem->getFollow();
						for (int k = 0; k < tem->follow.size(); k++)
						{
							this->follow.push_back(tem->follow[k]);
						}
					}
					if (j==tem->route[i].size()-2)
					{
						char next = tem->route[i][j + 1];
						if (allFormula[next]!=NULL)
						{
							vector<char > nextFirst = allFormula[next]->first;
							bool havaNul = false;
							for (int k = 0; k < nextFirst.size(); k++)
							{
								if (nextFirst[k]=='@')
								{
									havaNul = true;
									break;
								}
							}
							if (havaNul)
							{
								tem->getFollow();
								for (int k = 0; k < tem->follow.size(); k++)
								{
									this->follow.push_back(tem->follow[k]);
								}
							}
						}
					}
				}
			}
		}

	}


	return false;
}
