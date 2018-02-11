#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void computer_min_max_sum(int &min,int &max,int middle,int n,vector<int> &number)
{
	for(int i=0;i<middle;i++)
	{
		if(number[i]<number[middle])
			min++;
	}
			
	for(int i=middle;i<n;i++)
	{
		if(number[i]>number[middle])
			max++;
	}
}

int main(int argc, char** argv) {
	int n,temp,middle;
	int min=0,max=0;
	int result=-1;
	vector<int> number;
	cin>>n;
		
	//输入 
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		number.push_back(temp);	
	}
	//排序 
	stable_sort(number.begin(),number.end());
	middle=n/2; 
	//如果是偶数 
	if(n%2==0) 
	{
		//中间两个数相同 
		if(number[middle]==number[middle-1])
		{
			//计算小于数数量  大于数数量 
			computer_min_max_sum(min,max,middle,n,number);
			if(min==max)
				result=number[middle];
		}
		else
			result=-1;
	}else{//如果是奇数
			//计算小于数数量  大于数数量 
			computer_min_max_sum(min,max,middle,n,number);
			if(min==max)
				result=number[middle]; 
			else
				result=-1;
	}
	cout<<result;		
	return 0;
}
