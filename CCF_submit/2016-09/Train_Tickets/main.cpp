#include <iostream>
#include <algorithm>
#define MAX_NUMBER 101
using namespace std;

class Line{
	public:
		int postion[6];
		int null_number;
};

int main(int argc, char** argv) {
	int n;
	int sample_value[MAX_NUMBER];
	Line  train[21];
	cin>>n;
	//������������ 
	for(int i=1;i<=n;i++)
	{
		cin>>sample_value[i];
	}
	//��ʼ��������λ
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=5;j++)
			train[i].postion[j]=(i-1)*5+j;
		train[i].null_number=5;
	}
	//��������n�� 
	for(int i=1;i<=n;i++) 
	{
		//�Ƿ������� 
		int flag=0;
		//��С�����������λ20�� 
		for(int j=1;j<=20;j++)
		{
			//�����Ҫ����λС�ڵ��ڵ�ǰ�ŵ���λ�������ڵ�ǰ�� 
			if(sample_value[i]<=train[j].null_number) 
			{
				//�����λ��Ϣ 
				for(int k=1;k<=sample_value[i];k++)
				{
					cout<<train[j].postion[5-train[j].null_number+k];
					//������뵽���һ����Ϣ������ 
					if(k==(sample_value[i]))
						cout<<endl;
					else 
						cout<<" ";
				} 
				//��ȥ����λ 
				train[j].null_number-=sample_value[i];
				flag=1; 
				//ѡƱ��ϣ�����ѭ�� 
				break;
			}
		
		}
		//20��ȫ���������������䣬�򵥸�����
		if(flag==0)
		{
			//��Ҫ�����λ������ 
			int temp=sample_value[i];
			for(int j=1;j<20;j++)
			{
				//ֻ�е�ǰ����λ�ã��ͷ��� 
				while(train[j].null_number!=0&&temp!=0)
				{
					cout<<train[j].postion[5-train[j].null_number+1];
					train[j].null_number--; 
					temp--;
					if(temp==0)
					{
						cout<<endl;
						break;
					}
					else
						cout<<" ";
				} 
				if(temp==0)
					break;
			}
		} 
	}
	return 0;
}
