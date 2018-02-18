#include <iostream>
#include <cmath>
#define MAX_GARD 31
using namespace std;

int main(int argc, char** argv) {
	int n,m;
	int grad[MAX_GARD][MAX_GARD];
	cin>>n>>m;
	//输入 
	for(int i=1;i<=n;i++)	
	{
		for(int j=1;j<=m;j++)
		{
			cin>>grad[i][j];
		}
	}
	//计算需横向要消去的值
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-2;j++)
		{
			//横轴三位相同 
			if((abs(grad[i][j])==abs(grad[i][j+1]))&&(abs(grad[i][j+1])==abs(grad[i][j+2])))
			{
				grad[i][j]=-abs(grad[i][j]);
				grad[i][j+1]=-abs(grad[i][j+1]);
				grad[i][j+2]=-abs(grad[i][j+2]);
			}		 
		}
	} 
	
	//计算需纵向向要消去的值
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n-2;j++)
		{
			//纵向轴三位相同 
			if((abs(grad[j][i])==abs(grad[j+1][i]))&&(abs(grad[j+1][i])==abs(grad[j+2][i])))
			{
				grad[j][i]=-abs(grad[j][i]);
				grad[j+1][i]=-abs(grad[j+1][i]);
				grad[j+2][i]=-abs(grad[j+2][i]);
			}		 
		}
	}
	
	//消除标记位 
	for(int i=1;i<=n;i++)	
	{
		for(int j=1;j<=m;j++)
		{
			if(grad[i][j]<0)
				grad[i][j]=0;
		}
	}
	
	//输出结果 
	for(int i=1;i<=n;i++)	
	{
		for(int j=1;j<=m;j++)
		{
			if(j==m)
				cout<<grad[i][j]<<endl;
			else 
				cout<<grad[i][j]<<' ';
		}
	}
	return 0;
}
