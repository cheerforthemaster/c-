#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	int one = 1, two = 2, three = 3, four = 4;
	Stack<int> sta;
	sta.push(one);
	sta.push(two);
	sta.push(three);
	sta.push(four);

	sta.pop(one);
	sta.pop(two);
	sta.pop(three);
	sta.pop(four);


	cout << one << two << three << four << endl;

	int tem[56];
	for (int i = 0; i < 56; i++)
	{
		tem[i] = i;
		sta.push(tem[i]);
	}
	for (int i=0;i<56;i++)
	{
		sta.pop(tem[i]);
	}

	for (int i = 0; i < 56; i++)
	{
		cout << tem[i];
	}

	return 0;
}