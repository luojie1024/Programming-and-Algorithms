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
	//���� 
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		mapNumber[temp]++;
	}

	//��ֵ��С������� ��ֵ���� 
	for(map<int,int>::iterator it=mapNumber.begin();it!=mapNumber.end();it++)
	{
		int x=it->second;
		int s=it->first;
		iter=multimapNumber.find(x);
		//����Ѵ��� 
		if(iter!=multimapNumber.end())
		{
			//����ֵ���ڲ���ֵ�����滻 
			if(iter->second>s)
			{
				multimapNumber.insert(pair<int,int>(x,s));		
			}
		}else
		{
			multimapNumber.insert(pair<int,int>(x,s));
		} 
						
		
	} 		
	
	//������������һ���� 
	cout<<multimapNumber.rbegin()->second;
	return 0;
}
