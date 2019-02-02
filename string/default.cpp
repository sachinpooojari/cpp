#include<iostream>
using namespace std;

int get()
{	int n;
	cout<<"Enter default v"<<endl;
	cin>>n;
return n;

}


void called(int a=get() ,int b=get())
{
	cout<<a<<" "<<b<<endl;


}
main()
{


	called();
	called(60);
	called(40,50);


}
