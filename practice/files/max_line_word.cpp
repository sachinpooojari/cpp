#include<iostream>
#include<fstream>
using namespace std;
main()
{
	fstream f("data");
	int line=0;
	int w_count=0;
	string s;
	char ch;
	int max=0;
	
	while((ch=f.get())!=EOF)
	{	w_count++;
		if(ch=='\n')
		{
			line++;
			if(w_count>max)
			{
					max=w_count;
				}
				w_count=0;
		}
		
	
	}
	cout<<"line "<<line<<endl<<"max"<<max<<endl;




}
