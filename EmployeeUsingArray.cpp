//Program to read the data of n employee and compute net salary of each using array as object
#include<iostream>
using namespace std;
class employee
{
	int num, basic;
	long da,it,netsal,gsal;
	char name[20];
	public:
	void read();
	void disp();
	void calc();
};
void employee::read()
{
	cout<<"Enter Employee Id,Name & Basic salary \n";
	cin>>num>>name>>basic;
}
void employee::calc()
{
	da=(0.52)*basic;
	gsal=da+basic;
	it=(0.3)*gsal;
	netsal=basic+da-it;
}
void employee::disp()
{
	cout<<num<<"\t\t"<<name<<"\t\t\t"<<basic<<"\t\t\t"<<da<<"\t\t\t"<<it<<"\t\t\t" <<gsal<<"\t\t\t"<<netsal<<"\n";

}
int main()
{
	int n;
	cout<<"Enter no. of employees \n";
	cin>>n;
	employee e[n];
	for(int i=0;i<n;i++)
	{
		
		e[i].read();
		e[i].calc();
	}

	cout<<"E-Id\t\t Name \t\t\t Basic Salary \t \t DA\t\t       Gross Salary \t\t        Income tax \t\t          Net salary\n";
	for(int i=0;i<n;i++)
	{
		
		e[i].disp();
	}
	return 0;
}
