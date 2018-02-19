#include <iostream>
#define MAX_LENGTH 1001
using namespace std; 


int main(int argc, char** argv) {
	int n,result=0;
	int array[MAX_LENGTH];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>array[i];
	}
	
	for(int i=1;i<n;i++)
	{
		if(array[i]!=array[i+1])
			result++;
	}
	
	cout<<++result;
	return 0;
}
