#include<iostream>
using namespace std;
class Complex
{
	float  real,img;
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

	Complex operator + ( Complex &c2);
	friend Complex operator + (const Complex* c1,const Complex &c2 );
	friend Complex operator - (const Complex& c1,const Complex &c2 );
	friend Complex operator * (const Complex& c1,const Complex &c2 );
	friend Complex operator / (const Complex& c1,const Complex &c2 );
	friend Complex operator + (const Complex& c1,const int num);
	friend Complex operator - (const Complex& c1,const int num);
	friend Complex operator - (const int num,const Complex c1);
	friend Complex operator + (const int num,const Complex c1);
};


Complex Complex:: operator + ( Complex &c2)
{
		Complex temp;
		temp.real = c2.real + this->real;
		temp.img = c2.img + this->img;
		return temp;		

}
//eventhogh memeber fn present not give error ....freind given higher priority.
Complex operator + (const Complex* c1,const Complex &c2)

	{
		Complex temp;
		cout<<"called "<<endl;

		temp.real = c1->real  + c2.real;
		temp.img = c1->img  + c2.img;
		return temp;		
	}
Complex operator - (const Complex& c1,const Complex &c2)
	{
		Complex temp;

		temp.real = c1.real - c2.real;
		temp.img = c1.img - c2.img;
		return temp;		
	
	}
Complex operator * (const Complex& c1,const Complex &c2)
	{
		Complex temp;

		temp.real = c1.real * c2.real;
		temp.img = c1.img * c2.img;
		return temp;		
	
	}
Complex operator / (const Complex& c1,const Complex &c2)
	{
		Complex temp;

		temp.real = c1.real / c2.real;
		temp.img = c1.img - c2.img;
		return temp;		
	
	}

Complex operator + (const Complex& c1,const int num)
{
		Complex temp;

		temp.real = c1.real + num;
		temp.img = c1.img + num;
		return temp;		
	

}

Complex operator - (const Complex& c1,const int num)
{
		Complex temp;

		temp.real = c1.real - num;
		temp.img = c1.img - num;
		return temp;		
	
}

Complex operator + (const int num,const Complex c1)
{
		Complex temp;

		temp.real = num+ c1.real ;
		temp.img = num + c1.img;
			
		return temp;		
}


Complex operator - (const int num,const Complex c1)
{
		Complex temp;

		temp.real = num - c1.real ;
		temp.img = num - c1.img;
			
		return temp;		
}


main()
{
	Complex c1,c2,c3,c4,c5;
	c1.read();
	c2.read();
	c3.read();
	c4.read();

	c1.show();
	c2.show();
	c3.show();
	c4.show();

	c4=c1+c2;//-c3*c4; // c1.operator(c2);
	
	cout<<"_res_"<<endl;	
	c4.show();

	c5=100-c3;
	cout<<"_res_"<<endl;	
	c5.show();


}
