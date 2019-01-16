#include<iostream>
using namespace std;
class A
{
	int x;
	int y;
	public:
		A()
		{
			x=10;y=20;		
			cout<<x<<" "<<y<<endl;
		}

		void show()const
		{
//			x=1000;y=5000;
			cout<<x<<" "<<y<<endl;
		}
};
main()
{
	const A a1;
	A a2;

	a1.show();	//a1::show(const A &a1)
	a1=a2;
	a1.show();	//a1::show(const A &a1)
}






