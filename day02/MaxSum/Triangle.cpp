#include <iostream>
#include<algorithm>
#define MAX 101
using namespace std;
int D[MAX][MAX];
int n;
/*
           ->   i   
     2     ->   1
    3 4    ->   2
   5 6 8   ->   3
*/
int MaxSum(int i,int j)
{
	//����Ѿ�������������ײ� 
	if(i==n)
	{
		//���ص�����ײ���·��Ȩ�� 
		return D[i][j];	
	}
	int left=MaxSum(i+1,j);
	int right=MaxSum(i+1,j+1);
	//��ǰ�²����·��+֮ǰ·���� 
	return max(left,right)+D[i][j];
}


int main(int argc, char** argv) {
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>D[i][j];
	cout<<MaxSum(1,1)<<endl; 
	return 0;
}
