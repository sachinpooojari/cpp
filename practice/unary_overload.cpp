#include<iostream>
using namespace std;
class unary
{
	int x,y;
public:
	unary()
	{
		x=y=0;
	}
	void read()
	{
		cout<<"x y?"<<endl;
		cin>>x>>y;
	}
	void show()
	{
		cout<<"x="<<x<<" y= "<<y<<endl;	
	}
	unary operator - ();
	friend unary  operator - (const unary& u );
	
	
//	unary  operator ++ (int );
	friend unary operator ++ ( unary &u,int);
	unary  operator ++ ( );
};
unary unary::operator - ()
{
	cout<<" in member "<<endl;
	unary t;
	t.x= x;
	t.y= y;
	return t;
}
unary operator - (const unary& u)
{
	cout<<" in friend "<<endl;
	unary t;
	t.x= -u.x;
	t.y= -u.y;
	return t;

}

/*
 * unary unary::operator ++ (int l)
{
	cout<<" in member  "<<l<<endl;
	unary tmp;

	tmp.x=x;
	x=x+1;	


	tmp.y=y;
	y=y+1;	
	return tmp;
}

*/
unary operator ++ ( unary& u,int l)
{
	cout<<" in friend "<<l<<endl;
	unary tmp;

	tmp.x=u.x;
	u.x=u.x+1;	


	tmp.y=u.y;
	u.y=u.y+1;	
	return tmp;
}

unary unary::operator ++( )
{
	x=x+1,y=y+1;

	return *this;

}



main()
{
	unary u,u2;
	u.read();
	u.show();
	cout<<"unary -"<<endl;
	u2=-u; //u2=u.operator-( );  ---> u2=unary::operator-(&u)
	u.show();
	u2.show();
	
	
	cout<<"post increment "<<endl;
	unary u3;
	u3=u2++; //u3=u2.operator++(int );  ---> u3=unary::operator++(&u2,int)
	u2.show();
	u3.show();
	
	
	cout<<"pre increment "<<endl;
	u3=++u2; //u3=u2.operator++(int );  ---> u3=unary::operator++(&u2,int)
	u2.show();
	u3.show();
	


}

