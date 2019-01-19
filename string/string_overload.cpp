#include<iostream>
//#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class my_string 
{
	char *c;
	public:


	my_string()
	{	//cout<<"def"<<endl;
		c=new char[1];
		c[0]=' ';
	}

	my_string(const char *s)
	{	//cout<<"par"<<endl;
		c=new char[strlen(s)+1];
		for(int i=0;c[i]=s[i];i++);



	}

	my_string(const my_string& s)
	{	//cout<<"copy"<<endl;
		c=new char[strlen(s)+1];
		for(int i=0;c[i]=s.c[i];i++);


	}
	/*
	   ~my_string()
	   {
	   cout<<"des"<<endl;
	   delete[] c;
	   }
	   */
	friend istream& operator >> (istream& in,my_string& s);
	friend ostream& operator << (ostream& out,my_string& s);
	friend istream& getline (istream& in,my_string& s);
	my_string operator = (const my_string& s);
	my_string operator = (const char *);
	my_string operator () (const char *);
	my_string operator () (const my_string& );
	void* operator new(size_t size);//ho it cach size dont know 
	void operator delete (void *);//ho it cach size dont know 
	bool operator > ( const my_string& );
	bool operator < (const my_string& );
	bool operator == (const my_string& );
	bool operator >= (const my_string& );
	bool operator <= (const my_string& );
	my_string& operator + ( const  my_string& s2);
	my_string operator + ( const  char* s2);
	void operator += (const  my_string& s2);
	void push_back(const char );
	void pop_back(void );
	unsigned int capacity(void  );
	void  resize(int size);
	int strlen(const my_string& );
	int strlen(const char * );
	char  cmp(const my_string& s);
};

/*********************************** New and Delete overload *******************************************************************/

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




/*********************************** >> and << overload : freind  *******************************************************************/


//frnd:  >>  overloaded 	
istream& operator >> (istream& in,my_string& s)
{
	FILE *fp;
	fp=fopen("temp","w+");
	char ch;
	while(1)
	{	ch=getchar();
		if(ch!=' ' && ch!='\n' )
			fputc(ch,fp);
		else
			break;	
	}
	int count=ftell(fp);
	rewind(fp);
	delete[] s.c;
	s.c=new char[count+1];
	int i=0;	
	while((ch=fgetc(fp))!=EOF)
		s.c[i++]=ch;
	s.c[i]=0;
	remove("temp");
	return in;
}



ostream& operator << (ostream& out,my_string& s)
{
	out<<s.c;
}


/*********************************** getline()  *******************************************************************/
istream& getline (istream& in,my_string& s)
{
	cout<<"getline_overloaded"<<endl;
	FILE *fp;
	fp=fopen("temp","w+");
	char ch;
	while(1)
	{	ch=getchar();
		if( ch!='\n' )
			fputc(ch,fp);
		else
			break;	
	}
	int count=ftell(fp);
	rewind(fp);
	delete[] s.c;
	s.c=new char[count+1];
	int i=0;	
	while((ch=fgetc(fp))!=EOF)
		s.c[i++]=ch;
	s.c[i]=0;
	remove("temp");
	return in;
}



/*******************************************| equla = ovrld  |********************************************************/

my_string my_string:: operator = (const my_string& s)
{
	delete[] this->c;
	this->c=new char[ strlen(s) +1 ];
	int i;
	for( i=0;s.c[i];i++)
		this->c[i]=s.c[i];
	this->c[i]=s.c[i];
	return *this;
	//	this->c=s.c; //   wrong approch since here address is passed not data
}

my_string my_string:: operator = (const char *word)
{	
	delete[] this->c;
	this->c=new char[ strlen(word) +1 ];
	//	strcpy(this->c,word); only once overload = without fn so next time can be used
	int i;
	for( i=0;word[i];i++)
		this->c[i]=word[i];
	this->c[i]=word[i];
	cout<<"= ovrload"<<endl;	
	return *this;

}
/*******************************************| () ovrload  |********************************************************/
my_string my_string:: operator () (const char *word)
{	
	delete[] this->c;
	this->c=new char[ strlen(word) +1 ];
	for(int i=0;word[i];i++)
	{
		this->c[i]=word[i];
	}

}

my_string my_string::operator () (const my_string& s)
{	
	delete[] this->c;
	this->c=new char[ strlen(s) +1 ];
	*this=s;

}

/*******************************************| + ovrload  |********************************************************/
my_string& my_string::  operator + (const my_string& s2)
{
	static my_string temp;
	temp.c= new char[ strlen(*this) + strlen(s2) +1 ];
	//strcpy(temp.c,this->c);
	//strcat(temp.c,s2.c);
	temp=*this;
	int i=0,j=0;
	for(i=0;temp.c[i];i++);
	for(j=0;temp.c[i]=s2.c[j];j++,i++);
	return temp; 		//may be memory leak  bcz returning large data ...reciver may not have such



}

my_string my_string:: operator + (const char* s2)
{

	my_string temp;
	temp.c= new char[ strlen(*this) + strlen(s2) +1 ];
	temp=*this;
	//strcat(temp.c,s2);
	int i=0,j=0;
	for(i=0;temp.c[i];i++);
	for(j=0;temp.c[i]=s2[j];j++,i++);
	return temp; 		//may be memory leak

}

/*******************************************| += ovrload  |********************************************************/
void my_string:: operator += (const  my_string& s2)
{
	my_string temp(*this);
	delete[] this->c;	
	this->c= new char [  strlen( temp) + strlen(s2) +1 ];
	*this=temp;
	*this=*this+s2;
/*	int i=0,j=0;
	for(i=0;this->c[i];i++);
	for(j=0;this->c[i]=s2.c[j];j++,i++);
*/

}

/*******************************************| > ovrload  |********************************************************/

bool my_string::operator >  (const my_string& s ) 
{
	if(cmp(s)>0)
		return true;
	else 
		return false;
}

/*******************************************| < ovrload  |********************************************************/

bool my_string::operator < (const my_string& s )
{

	if(cmp(s)<0)
		return true;
	else 
		return false;
}


/*******************************************| == ovrload  |********************************************************/
bool my_string::operator == (const my_string& s )
{

	if(cmp(s)==0)
		return true;
	else 
		return false;
}

/*******************************************| <= ovrload  |********************************************************/
bool my_string::operator <= (const my_string& s )
{

	if( cmp(s)<0 || cmp(s)==0)
		return true;
	else 
		return false;
}

/*******************************************| >= ovrload  |********************************************************/
bool my_string::operator >= (const my_string& s )
{

	if( cmp(s)>0 || cmp( s )==0)
		return true;
	else 
		return false;
}

/*******************************************| push_back function  |********************************************************/
void my_string:: push_back(const char ch )
{
	my_string temp(*this);		// temp to holde data untill allocate memory to this pointer.
	delete[] this->c;
	this->c= new char [ strlen(temp) + 1 + 1];
	int i;
	for( i=0;temp.c[i];i++);
	temp.c[i++]=ch;
	temp.c[i]=0;
	*this=temp;	
}


/*******************************************| pop_back function  |********************************************************/

void my_string:: pop_back(void  )
{
	my_string temp(*this);		// temp to holde data untill allocate memory to this pointer.
	delete[] this->c;
	this->c= new char [ strlen(temp) + 1 + 1];
	int i;
	for( i=0;temp.c[i];i++);
	i=i-1;
	temp.c[i]=0;
	*this=temp;	

}

/*******************************************| capacity() function  |********************************************************/
unsigned int  my_string:: capacity(void  )
{
	return strlen(*this);

}

/*******************************************|  resize() function  |********************************************************/
void my_string:: resize(int size)
{

	my_string temp(*this);		// temp to holde data untill allocate memory to this pointer.
	delete[] this->c;
	this->c= new char [ size + 1];
	int i;
	for(i=0;i<size;i++)
	{
		this->c[i]=temp.c[i];	
	}
	this->c[i]=0;

}

/*******************************************|  strlen() function  |********************************************************/
int  my_string:: strlen(const my_string& s )
{
	int i;
	for(i=0;i<s.c[i];i++);
	return i;
}


int  my_string:: strlen(const char* s )
{
	int i;
	for(i=0;i<s[i];i++);
	return i;
}


/*******************************************|  strcmp() function  |********************************************************/
char my_string :: cmp(const my_string& s)
{	int i=0;
	for(i=0; (this->c[i]==s.c[i]  && c[i]!=0 )  ;i++);
	return ( this->c[i] - s.c[i] );   //0  equal  |  +ve a>b   | -ve a<b

}


main()
{
	my_string s1,s2(s1),*s4,s3;
	//	getline(cin,s1);
	cin>>s1;
	cin>>s2;
	//	s4 =new my_string;
	//	cin>>s2;
	//	s1.push_back('a');
	//	s2.pop_back();
	//	s1.resize(5);
	//	cout<<"cap ="<<s1.capacity()<<endl;
		cout<<">"<<(s1>s2)<<" < "<<(s1<s2)<<" ="<<(s1==s2)<<" <="<<(s1<=s2)<<" >="<<(s1>=s2)<<endl;
	s3="a";
	s2+=s1;
	cout<<s1<<" "<<s2<<" "<<s3<<endl;




}


