#include <iostream>
#include <algorithm>
#include<vector>
#define MAX_SIZE 501
using namespace std;

vector<int> plus_number;
vector<int> negative_number;
int main(int argc, char** argv) {
	int n,temp,result=0;
	cin>>n;
	//输入 
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		if(temp>0)
			plus_number.push_back(temp);
		else if(temp<0)
			negative_number.push_back(temp);
	}
	//从小到大排序
	sort(plus_number.begin(),plus_number.end());
	sort(negative_number.begin(),negative_number.end());
	
	for(vector<int>::iterator plus_it=plus_number.begin();plus_it!=plus_number.end();plus_it++)
	{
		for(vector<int>::iterator nega_it=negative_number.begin();nega_it!=negative_number.end();nega_it++)
		{
			if(*plus_it==-*nega_it)	
			{
				result++;
				break;
			}
		}	
	} 
	cout<<result;
	return 0;
}
