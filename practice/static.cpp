#include<iostream>
using namespace std;
class A
{
	static 	int x;
	public:
	A()
	{
	
		x=10;
		cout<<"constructor  "<<x<<endl;	
	}

	void show()
	{
			cout<<x<<endl;	
			x++;
	}


};

int A::  x;

void print()
{
	static A a;
	a.show();
}



main()
{
	A a;
	a.show();
	print();
	print();


}
