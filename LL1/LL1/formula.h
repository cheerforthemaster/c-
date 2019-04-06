#pragma once
#include <vector>
#include <map>
using namespace std;


class formula
{
public:
	formula(string allwords);

	bool getFirst();
	bool getFollow();

	char name;
	vector<vector<char>> route;
	vector<char> first;
	vector<char> follow;
};

static map<char, formula*> allFormula;