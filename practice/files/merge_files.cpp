#include<iostream>
#include<fstream>
using namespace std;
class  max_c
{
	public:

	int total_c;
	int line_c;
	int char_c;
	max_c()

	{
		total_c=line_c=char_c=0;
	}
	void count(fstream& f)
	{	char ch;
		int tmp_c=0;
		while((ch=f.get())!=EOF)	
		{	tmp_c++;
			if(ch=='\n')
			{
				line_c++;
				if(tmp_c>char_c)
					char_c=tmp_c;
			}
				tmp_c=0;			
		
		
		}
		f.clear();
//		f.seekg(0,ios::beg);
		f.seekg(0,ios::end);
		total_c=f.tellg();

	
	
	}
};


void con(fstream& f1,fstream& f2,fstream& f3)
{
	max_c m1;
	m1.count(f1);
	cout<<m1.total_c<<endl;
	char s[m1.total_c];

}
void word(fstream& f1,fstream& f2,fstream& f3)
{


}
void line(fstream& f1,fstream& f2,fstream& f3)
{

}

int main(int argc ,char **argv)
{
	if(argc!=4)
	{
		cout<<"./a.out f1_name f2_name";
		return 0 ;

	}
	fstream f1,f2,f3;
	f1.open(argv[1]);
	f2.open(argv[2]);
	f3.open(argv[3],ios::in|ios::out|ios::trunc);
	try{

	if(f1.fail() || f2.fail() || f3.fail() )
	
		throw "Error in opening fine";
	}
  	catch (const char* s)
	{
		cout<<s<<endl;
		return 0;
	}
	
	int choice;
	cout<<"enter choice 1.conctinate 2.line by line 3.word by word"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1: con(f1,f2,f3);
			break;
		case 2: line(f1,f2,f3);
			break;
		case 3: word(f1,f2,f3);
			break;
	
	
	}
	
	



}
