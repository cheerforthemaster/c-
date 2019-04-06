#include<iostream>
using namespace std;

class Building
{
public:
	Building() {};
	Building(int m, int n, float s)
	{
		cout << "base constructor called" << endl;
		layernumber = m;
		housenumber = n;
		sumarea = s;
	}
	void print()
	{
		cout << "this is a " << layernumber << "-story building" << endl;
		cout << "there are " << housenumber << " houses" << endl;
		cout << "And total area is " << sumarea << endl;
	}
	~Building() {};

private:
	int layernumber;
	int housenumber;
	float sumarea;

};

class House:public virtual Building
{
public:
	House(int m, int n, float s ,int b,int a):Building(m,n,s)
	{
		cout << "House constructer called." << endl;
	}
private:
	int bedroom;
	int bathroom;
};
void main()
{
	Building build1(18, 360, 8000);
	build1.print();
	House house(6, 24, 2880, 4, 2);
	house.print();
}
