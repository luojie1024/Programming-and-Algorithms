#include <iostream>
#include<algorithm>
#include<vector>
#define MAX_NUMBER 1000
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,temp,result=MAX_NUMBER;
	vector<int> vect;
	cin>>n;
	//输入数据，保存到vetor中 
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		vect.push_back(temp); 
	}
	stable_sort(vect.begin(),vect.end());
	for(int j=1;j<vect.size();j++)
	{
		//如果两数相等，则输出0 
		if(vect[j-1]==vect[j])
		{
			result=0;
			break;
		}else{
			if(vect[j]-vect[j-1]<result)
			{
				result=vect[j]-vect[j-1];	
			}
		}
	}
	cout<<result;		
			 
	return 0;
}
