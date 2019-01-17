#include<iostream>
using namespace std;

class A
{
	private :
		int x;
		int y;
		static int count;
		static A* prev;
	public:
		A()
		
		{
			if(count==0)
			{		x=10;y=20;
					prev=this;
			}	
			else{

			this->x=prev->x;
			this->y=prev->y;
			prev=this;
			}
		count++;
		
		}
		A(int a,int b)
		{
			
			this->x=a;
			this->y=b;
			prev=this;

		}
		A(A& a)
		{
			x=a.x;
			y=a.y;

		}

		void print()
		{
			cout<<x<<" "<<y<<endl;
		}
		void modify(int a,int b)
		{
			x=a;
			y=b;

		}



};
int A::count;
A* A::prev;
main()
{
	
	A a;//(100,252);
	a.print();
	A b(100,200);
	b.print();
	A c;
	c.print();

}
