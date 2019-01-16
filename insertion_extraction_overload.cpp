#include<iostream>
using namespace std;

class A 
{
	int x,y;
public:
	A(): x(0),y(0)
	{
	}

	friend istream& operator >> (istream& in,A& arg);
	friend ostream& operator << (ostream& in,A& arg);
};

istream& operator >>(istream& in,A& arg)
{
	in>>arg.x;
	in>>arg.y;
	return in;	

}
ostream& operator << (ostream& out,A& arg)
{
	out<<arg.x<<" ";
	out<<arg.y;
	return out;	
}
main()
{
	class A a;
	cin>>a;// cin.operator>>t(a)-->   A::operator(&cin,a); //since cin is object of other clas istream library file 
	cout<<a;

}
