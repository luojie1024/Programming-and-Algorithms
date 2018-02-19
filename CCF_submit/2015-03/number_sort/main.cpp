#include <iostream>
#include <vector>
#include <algorithm> 
#define MAX_SIZE 1001
using namespace std; 

//数字对象 
class Number
{
	public:
		int number;
		int frequency;
};


//排序规则 
bool frequency_sort(Number a,Number b)
{
	if(a.frequency>b.frequency)
		return true;
	else if(a.frequency==b.frequency&&a.number<b.number) 
		return true;
	else
		return false;
}

//计算频率的数组 
int numbers[2][MAX_SIZE]={};

int main(int argc, char** argv) {
	int n,temp;
	vector<Number> vec_numbers;
	cin>>n;
	//用数组计算频率 
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		numbers[1][temp]++;
	}
	
	//将数据放到vector中排序 
	for(int i=0;i<=MAX_SIZE;i++)
	{
		if(numbers[1][i]!=0)
		{
			Number number;
			number.number=i;
			number.frequency=numbers[1][i];
			vec_numbers.push_back(number);
		}
	}
	
	//排序 
	stable_sort(vec_numbers.begin(),vec_numbers.end(),frequency_sort);
	
	//输出
	for(vector<Number>::iterator it=vec_numbers.begin();it!=vec_numbers.end();it++)
	{
		cout<<it->number<<" "<<it->frequency<<endl;
	}
	
	return 0;
}
