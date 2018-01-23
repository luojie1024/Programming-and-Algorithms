#include <iostream>
#include<algorithm>
using namespace std;
//三角形最大层数 
#define MAX 101
//存储三角形
int D[MAX][MAX];
//存储计算结果，避免重复计算 
int maxSum[MAX][MAX];
//三角形的层数 
int n;

/*
           ->   i   
     2     ->   1
    3 4    ->   2
   5 6 8   ->   3
*/

int MaxSum(int i,int j)
{
	//如果之前已经计算过该结果 
	if(maxSum[i][j]!=-1)
		//返回计算过的结果 
	 	return maxSum[i][j];
	//如果到达三角形的底部 
	if (i==n)
		//直接返回前步骤结果
		return D[i][j];
	//向三角形的左下移动 
	int left=MaxSum(i+1,j);
	//向三角形的右下移动 
	int right= MaxSum(i+1,j+1);
	//当前步最大值=当前值+下一步路径的最大值 
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
