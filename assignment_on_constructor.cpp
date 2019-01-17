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
			count++;
			if(count==1)
			{
				x=y=555;
				prev=this;
				//	cout<<count<<" "<<this <<" "<<prev->x<<" "<<prev->y<<endl;
			}
			else
			{	
				this->x=prev->x;
				this->y=prev->y;
				//	cout<<count<<" "<<this <<" "<<prev->x<<" "<<prev->y<<endl;
				prev=this;

			}


		}
		A(int a,int b)
		{
			x=a;
			y=b;


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
	
	A a;
	a.modify(100,200);
	A b;
	b.print();

}
