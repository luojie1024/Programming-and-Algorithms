#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int year,d,day,month;
	int sum=0;
	int month_arr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	cin>>year>>d;

	//ÅĞ¶ÏÊÇ·ñÊÇÈòÄê
	if((year%4==0&&year%100!=0)||(year%400==0))
		month_arr[2]=29; 
	for(int i=1;i<=12;i++)
	{
		if(d>month_arr[i])
			d-=month_arr[i];
		else
		{
			month=i;
			break;
		}	
	}
	
	cout<<month<<endl;
	cout<<d<<endl;
	return 0;
}
