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
		
	//���� 
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		number.push_back(temp);	
	}
	//���� 
	stable_sort(number.begin(),number.end());
	middle=n/2; 
	//�����ż�� 
	if(n%2==0) 
	{
		//�м���������ͬ 
		if(number[middle]==number[middle-1])
		{
			//����С��������  ���������� 
			computer_min_max_sum(min,max,middle,n,number);
			if(min==max)
				result=number[middle];
		}
		else
			result=-1;
	}else{//���������
			//����С��������  ���������� 
			computer_min_max_sum(min,max,middle,n,number);
			if(min==max)
				result=number[middle]; 
			else
				result=-1;
	}
	cout<<result;		
	return 0;
}
