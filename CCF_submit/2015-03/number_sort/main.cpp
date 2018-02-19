#include <iostream>
#include <vector>
#include <algorithm> 
#define MAX_SIZE 1001
using namespace std; 

//���ֶ��� 
class Number
{
	public:
		int number;
		int frequency;
};


//������� 
bool frequency_sort(Number a,Number b)
{
	if(a.frequency>b.frequency)
		return true;
	else if(a.frequency==b.frequency&&a.number<b.number) 
		return true;
	else
		return false;
}

//����Ƶ�ʵ����� 
int numbers[2][MAX_SIZE]={};

int main(int argc, char** argv) {
	int n,temp;
	vector<Number> vec_numbers;
	cin>>n;
	//���������Ƶ�� 
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		numbers[1][temp]++;
	}
	
	//�����ݷŵ�vector������ 
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
	
	//���� 
	stable_sort(vec_numbers.begin(),vec_numbers.end(),frequency_sort);
	
	//���
	for(vector<Number>::iterator it=vec_numbers.begin();it!=vec_numbers.end();it++)
	{
		cout<<it->number<<" "<<it->frequency<<endl;
	}
	
	return 0;
}
