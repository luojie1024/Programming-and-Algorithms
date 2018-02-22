#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char** argv) {
	map<int,int> mapNumber;
	multimap<int,int> multimapNumber;
	multimap<int,int>::iterator iter;
	int n,temp;
	cin>>n;
	//输入 
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		mapNumber[temp]++;
	}

	//按值从小打大排序 键值交换 
	for(map<int,int>::iterator it=mapNumber.begin();it!=mapNumber.end();it++)
	{
		int x=it->second;
		int s=it->first;
		iter=multimapNumber.find(x);
		//如果已存在 
		if(iter!=multimapNumber.end())
		{
			//存在值大于插入值，则替换 
			if(iter->second>s)
			{
				multimapNumber.insert(pair<int,int>(x,s));		
			}
		}else
		{
			multimapNumber.insert(pair<int,int>(x,s));
		} 
						
		
	} 		
	
	//输出排序后的最后一个数 
	cout<<multimapNumber.rbegin()->second;
	return 0;
}
