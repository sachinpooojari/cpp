#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class my_string 
{
	char *c;
public:
	my_string()
	{
		c=new char[1];
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
	my_string s1,s2;
	cout<<s1<<" "<<s2;





}


