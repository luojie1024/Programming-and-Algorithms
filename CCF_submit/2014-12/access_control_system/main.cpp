#include <iostream>
#define MAX_LENGTH 1001
using namespace std;

int number_frequency[2][MAX_LENGTH]={};

int main(int argc, char** argv) {
	int n,temp;
	cin>>n;
	// ‰»Î 
	for(int i=1;i<=n;i++)
	{
		number_frequency[0][i]=i;
	}
	
	//º∆ ˝ 
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		number_frequency[1][temp]++;
		cout<<number_frequency[1][temp]<<' ';
	}
	return 0;
}
