#include <iostream>
#include<algorithm>
using namespace std;
//������������ 
#define MAX 101
//�洢������
int D[MAX][MAX];
//�洢�������������ظ����� 
int maxSum[MAX][MAX];
//�����εĲ��� 
int n;

/*
           ->   i   
     2     ->   1
    3 4    ->   2
   5 6 8   ->   3
*/

int MaxSum(int i,int j)
{
	//���֮ǰ�Ѿ�������ý�� 
	if(maxSum[i][j]!=-1)
		//���ؼ�����Ľ�� 
	 	return maxSum[i][j];
	//������������εĵײ� 
	if (i==n)
		//ֱ�ӷ���ǰ������
		return D[i][j];
	//�������ε������ƶ� 
	int left=MaxSum(i+1,j);
	//�������ε������ƶ� 
	int right= MaxSum(i+1,j+1);
	//��ǰ�����ֵ=��ǰֵ+��һ��·�������ֵ 
	maxSum[i][j]=max(left,right)+D[i][j];
	return maxSum[i][j];
} 

int main(int argc, char** argv) {
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		{
			cin>>D[i][j];
			maxSum[i][j]=-1;
		}
	cout<<MaxSum(1,1)<<endl; 
	return 0;
}
