#include <iostream>
#define MAX_LENGTH 101

using namespace std;

//��ʼ����������Ϊ0 
int grad[MAX_LENGTH][MAX_LENGTH]={};

int main(int argc, char** argv) {
	int n;
	int result=0;
	int star_x=0,star_y=0;
	int end_x=0,end_y=0;
	cin>>n;
	
	//���� 
	for(int i=1;i<=n;i++)
	{
		//��ͼ���� 
		cin>>star_x>>star_y>>end_x>>end_y;
		for(int j=star_y;j<end_y;j++)
		{
			for(int k=star_x;k<end_x;k++)
			{
				//��ͼ�����С 
				grad[j][k]--; 
			}
		}
	}
	
	//ͳ��С������������ 
	for(int i=0;i<MAX_LENGTH;i++)
	{
		for(int j=0;j<MAX_LENGTH;j++)
		{
			if(grad[i][j]<0)
				result++;
		}
	}
	
	//������ 
	cout<<result;
	return 0;
}
