#include<iostream>
using namespace std;
class emp
{
private:
	int salary;
protected:
	string name;
	int age;
public:
	string id;
	void read()
	{
		cout<<"Name | age | id"<<endl;
		cin>>name>>age>>id;
	}
	void readp()
	{
		cout<<" salary"<<endl;
		cin>>salary;
	}
	void show()
	{
		
		cout<<"Name | age | id"<<endl;
		cout<<name<<" "<<age<<" "<<id<<endl;
	}
};

class manager: private emp
{
private:
		string proj_name;
		int date;
public:
	void read()
	{
		
		cout<<"Name | age | id"<<endl;
		cin>>name>>age>>id;
		emp::read();
		cout<<"proj_name| date"<<endl;
		cin>>proj_name>>date;		
	}

	void show()
	{

		emp::show();
		cout<<"proj |date "<<endl;
		cout<<proj_name<<" "<<date<<endl	;
		
	}


};


main()
{
	emp e;
	manager m;

	e.readp();
	e.show();

	cout<<"\n*****************"<<endl;


	m.read();
	m.show();
}

