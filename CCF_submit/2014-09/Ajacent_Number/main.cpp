#include <iostream>
#include <algorithm>
#define MAX_SIZE 1001
using namespace std; 


int numbers[MAX_SIZE]={};
int main(int argc, char** argv) {
	int n,result=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>numbers[i];
	}
	//���� 
	sort(numbers,numbers+n+1);
	
	//�Ҷ��� 
	for(int i=2;i<=n;i++) 
	{
		if((numbers[i]-numbers[i-1])==1)
		{
			result++;
		}
	}
	//������ 
	cout<<result;
	return 0;
}
