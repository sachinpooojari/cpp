// overloadding only through member functions 

#include<iostream>
#define MAX 5
using namespace std;
class Complex
{
	float  real,img;
	int a[MAX];
public:
	Complex()
	{
		real=0,img=0;
	}
	void read()
	{
	
		cin>>real>>img;	
	
	
	}
	void show()
	{
		cout<<real<<showpos<<img<<"j"<<noshowpos<<endl;
	}
	Complex operator = (Complex& c2);
	Complex operator ()(const int n1,const int n2);
	int& operator [](const int n1);
};


Complex Complex:: operator = (Complex& c2)
{

	cout<<"Assignment ..."<<endl;
	real=c2.real;
	img=c2.img;


}
Complex Complex::operator ()(const int n1,const int n2)
{
	 this->real=n1;
	 this->img=n2;
}

int& Complex::operator [](const int n1)
{
	return a[n1];
}

main()
{
/************************************************************************
  Complex c1,c2,c3,c4,c5;
	c1.read();
	c2.read();
	c3.read();
	c4.read();

	c1.show();
	c2.show();
	c3.show();
	c4.show();

	c2=c1;// Complex::operator(&c2,c1);
	cout<<"_res_"<<endl;
	
	
	c2(100,200);// Complex::operator(&c2,100,200);
	cout<<"_res_"<<endl;
	c2.show();
	
	c2(100,200);// Complex::operator(&c2,100,200);
	cout<<"_res_"<<endl;
	c2.show();
*************************************************************************/




//subscript operator []
/************************************************************************
 *
	Complex c;


	cout<<"Enter Array Element of size "<<MAX<<endl;
	for(int i=0;i<MAX;i++)
		cin>>c[i];   //Complex::operator[](&c,i)
	for(int i=0;i<MAX;i++)
		cout<<c[i]<<" ";   //Complex::operator[](&c,i)
************************************************************************** /	
	


}
