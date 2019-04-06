#include <iostream>
#include <string>
using namespace std;

int main()
{
	string data;
	getline(cin, data);
	int len = data.length();
	char *Data = new char[len + 1];
	strcpy_s(Data, len + 1, data.c_str());

	//for (int i = 0; i <= len + 1; i++)
	//{
	//	cout << Data[i];
	//}

	for (int i = 0; i <= len + 1; i++)
	{
		if (Data[i] == ',')
		{
			cout << " ";
		}
		else
		{
			cout << Data[i];
		}
// 		if(Data[i]!=32)
// 		{
// 			cout << Data[i];
// 		}
	}
	cout << endl;
	system("pause");
	return 0;
}