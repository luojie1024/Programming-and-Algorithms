#include <iostream>
#include <algorithm>
#define MAX_LENGTH 1000 
using namespace std; 

int main(int argc, char** argv) {
	int n,max_wave=0;
	int days[MAX_LENGTH];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>days[i];
	}
	for(int i=1;i<n;i++)
	{
		if(abs(days[i-1]-days[i])>max_wave)
			max_wave=abs(days[i-1]-days[i]);
	}
	cout<<max_wave;
	return 0;
}
