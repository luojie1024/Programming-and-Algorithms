#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int n,result=0;
	cin>>n;
	for(int i=1;i<=9;i++)
	{
		result+=n%10;
		n/=10;
	}
	cout<<result;
	return 0;
}
