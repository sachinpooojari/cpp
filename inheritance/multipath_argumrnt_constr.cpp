#include<iostream>
using namespace std;
class A
{
public:
	int a;
	A(int x)
	{
		this->a=x;
		cout<<"constr"<<endl;	
	}
	~A()
	{
	cout<<"dest"<<endl;
	}


		void show()
		{cout<<a<<endl;
	
		}
};
class B:public A
{
public:
	int b;
	B(int x,int y):A(a)
	{
		this->b=y;
		cout<<"constr"<<endl;	
	}
	~B()
	{
	cout<<"dest"<<endl;
	}

	
	void show()
	{
		cout<<b<<endl;
	}


};
class C:public A
{
public:
	int c;
	C(int x,int z):A(x)
	{
		this->c=z;
		cout<<"constr"<<endl;	
	}
	~C()
	{
	cout<<"dest"<<endl;
	}
	void show()
	{
		cout<<c<<endl;
	}


};
class D:public B,public C
{
public:
	int d;
	D(int x,int y,int z,int m):B(x,y),C(x,z)
	{
		this->d=m;
		cout<<"constr"<<endl;	
	}
	~D()
	{

	cout<<"dest"<<endl;
		
	}
	void show()
	{
		B::show();
		C::show();
		cout<<d<<endl;	
	}

};


main()
{
	D d(10,20,30,40);
	d.show();
//	A a;
//	a.show();
	


}
