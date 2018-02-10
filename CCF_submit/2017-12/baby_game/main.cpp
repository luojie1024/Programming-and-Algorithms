#include <iostream>
#define MAX_LENGTH 1000
#include<algorithm>
#include<list>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,k,temp=1;
	list<int> student;
	cin>>n>>k;
	//初始化数据 
	for(int i=1;i<=n;i++)
	{
		student.push_back(i);
	}
	while(1)
	{
		for(list<int>::iterator iter=student.begin();iter!=student.end();)
		{
			if((temp%k==0)||(temp%10==k))
			{
				student.erase(iter++);
			}else{
				iter++;
			}
			temp++;
			if(student.size()==1)
				break;
		}
		if(student.size()==1)
				break;
	}
	//for(list<int>::iterator iter=student.begin( );iter!=student.end();iter++)
	cout<<student.front();
	return 0;
}
