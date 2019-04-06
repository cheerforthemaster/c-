#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	float debt = 50.00;
	const float rate = 0.02;
	int month = 1;

	while (debt <= 100)
	{
		debt = debt + debt*rate;;
		month++;
	}

	cout << "debt is "<< setprecision(2) << std::fixed << debt << endl;
	cout << "month is " << month << endl;

	system("pause");
	return 0;
}