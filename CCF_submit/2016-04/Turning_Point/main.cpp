#include <iostream>
#define MAX_LENGTH 10001
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,sale_amount[MAX_LENGTH];
	int result=0,temp=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>sale_amount[i];
	}
	//第一个数和最后一个肯定不是折点 n-2次遍历 
	for(int i=2;i<n;i++)
	{
		if((sale_amount[i-1]-sale_amount[i])*(sale_amount[i]-sale_amount[i+1])<0)
			result++; 
	}	
	cout<<result;
	return 0;
}
