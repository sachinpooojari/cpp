#include<iostream>
using namespace std;

class P
{
	static int count;
	int age;
	public:
	P()
	{
		age=100;

		count++;
	}
	void read()
	{
		cout<<"ID "<<count<<" age "<<age<<endl;
	}

	static void print(P k)
	{

		cout<<k.age<<endl;	
   	    	static 	P a;
       
			a.read();		
	
	}

	~P()
	{
		cout<<"~"<<endl;
	}


};
int P::count;
main()
{
	P p;
	P::print(p);
	P::print(p);
/*	P::print();
	{
	P::print();
	
	}
	P::print();
	*/
}
