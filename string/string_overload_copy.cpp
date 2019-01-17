#include<iostream>
#include<string.h>
#include<stdlib.h>
#define MAX 2000
using namespace std;
class my_string 
{
	char *c;
public:
	my_string()
	{
		c=new char[MAX];
		strcpy(c," ");
	}
	my_string(const char *s)
	{
		c=new char[strlen(s)+1];
		strcpy(c,s);
			
	}

	my_string(const my_string& s)
	{
		c=new char[strlen(s.c)+1];
		strcpy(c,s.c);
		
	
	}


	void print();
	friend istream& operator >> (istream& in,my_string& s);
	friend ostream& operator << (ostream& out,my_string& s);
//	friend void Getline(istream& in,my_string& s);
	my_string operator = (const my_string& s);
	my_string operator = (const char *);
	my_string operator () (const char *);
	my_string operator () (const my_string& );
	void* operator new(size_t size);//ho it cach size dont know 
	void operator delete (void *);//ho it cach size dont know 

	bool operator > (const my_string& );
	bool operator < (const my_string& );
	bool operator == (const my_string& );
	bool operator >= (const my_string& );
	bool operator <= (const my_string& );
	friend my_string operator + ( const my_string& s1,const  my_string& s2);

};

void* my_string ::operator new(size_t size)
{
	cout<<"string overloaded new "<<size<<endl;
	void *p=malloc(size);
	return p;
}

void my_string ::operator delete (void *p)
{
	cout<<"string overloaded delete"<<endl;

	free(p);
}




//membr: print funtion  
void my_string::print()
{
	cout<<c<<endl;

}


//frnd:  >>  overloaded 	
istream& operator >> (istream& in,my_string& s)
{
	in>>s.c;
}

//frnd:  <<  overloaded 	
ostream& operator << (ostream& out,my_string& s)
{
	out<<s.c;
}


/*
//frnd: getline funtion implemment
void Getline(istream& in,my_string& s)
{	getline(in,s.c)	
}
*/
//memr: == overloaded
my_string my_string:: operator = (const my_string& s)
{
	strcpy(this->c,s.c);

}

my_string my_string:: operator = (const char *word)
{
	strcpy(this->c,word);

}
//frnd:  ()  overloaded	
my_string my_string:: operator () (const char *word)
{
	for(int i=0;word[i];i++)
		{
			this->c[i]=word[i];
		}
//	strcpy(this->c,word);
	
}

my_string my_string::operator () (const my_string& s)
{
	strcpy(this->c,s.c);


}

//memr: + overload 
my_string  operator + (const my_string&  s1,const my_string& s2)
{
	my_string temp;
	strcpy(temp.c,s1.c);
	strcat(temp.c,s2.c);
	return temp;

}
bool my_string::operator > (const my_string& s )
{
	
	if(strcmp(c,s.c)>0)
		return true;
	else 
		return false;
}

bool my_string::operator < (const my_string& s )
{
	
	if(strcmp(c,s.c)<0)
		return true;
	else 
		return false;
}


bool my_string::operator == (const my_string& s )
{
	
	if(strcmp(c,s.c)==0)
		return true;
	else 
		return false;
}

bool my_string::operator <= (const my_string& s )
{
	
	if( strcmp(c,s.c)<0 || strcmp(c, s.c )==0)
		return true;
	else 
		return false;
}

bool my_string::operator >= (const my_string& s )
{
	
	if( strcmp(c,s.c)>0 || strcmp(c, s.c )==0)
		return true;
	else 
		return false;
}



main()
{
/*	my_string s("vet");
	s.print();	
//	Getline(cin,s);
	cin>>s;
	cout<<"Enterd:   "<<s<<endl;
	my_string s1("k");
	s1=s;
	cout<<"copied::   "<<s1<<endl;
	
	my_string s2;  ///mystring s2="vector"   ????
	s2="Vector\n";
	cout<<"=strig ovrld :    "<<s2<<endl;
	
	s1("hai");
	cout<<"('') ovrld:   "<<s1<<endl;
	s(s1);

	cout<<"() ovrld:    "<<s<<endl;
	
	s=s1+s2;
	cout<<"concatinated   "<<s<<endl;
	
	my_string s3("contr");	
	cout<<"constr(''):   "<<s3<<endl;
	my_string s4="contr";	
	cout<<"contr= :''    "<<s4<<endl;
	
	my_string s5=s3;	
	cout<<"contr = :    "<<s5<<endl;
	
	*/

	my_string s1,s2,s3;
	cin>>s1>>s2;
	cout<<boolalpha;
	cout<<"| > :  "<<(s1>s2)<<" | < : "<<(s1<s2)<<" | == :  "<<(s1==s2)<<" | >= : "<<(s1>=s2)<<" | <= :" <<(s1<=s2)<<endl;
	
	my_string *s;
	s=new my_string ("jsijsijsi");  //s=operator new (&my_string)
	cout<<endl<<*s<<"  "<<sizeof(my_string)<<endl;
	delete s;
}
