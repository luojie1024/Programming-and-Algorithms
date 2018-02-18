#include <iostream>
#include <cmath>
#define MAX_GARD 31
using namespace std;

int main(int argc, char** argv) {
	int n,m;
	int grad[MAX_GARD][MAX_GARD];
	cin>>n>>m;
	//���� 
	for(int i=1;i<=n;i++)	
	{
		for(int j=1;j<=m;j++)
		{
			cin>>grad[i][j];
		}
	}
	//���������Ҫ��ȥ��ֵ
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-2;j++)
		{
			//������λ��ͬ 
			if((abs(grad[i][j])==abs(grad[i][j+1]))&&(abs(grad[i][j+1])==abs(grad[i][j+2])))
			{
				grad[i][j]=-abs(grad[i][j]);
				grad[i][j+1]=-abs(grad[i][j+1]);
				grad[i][j+2]=-abs(grad[i][j+2]);
			}		 
		}
	} 
	
	//������������Ҫ��ȥ��ֵ
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n-2;j++)
		{
			//��������λ��ͬ 
			if((abs(grad[j][i])==abs(grad[j+1][i]))&&(abs(grad[j+1][i])==abs(grad[j+2][i])))
			{
				grad[j][i]=-abs(grad[j][i]);
				grad[j+1][i]=-abs(grad[j+1][i]);
				grad[j+2][i]=-abs(grad[j+2][i]);
			}		 
		}
	}
	
	//�������λ 
	for(int i=1;i<=n;i++)	
	{
		for(int j=1;j<=m;j++)
		{
			if(grad[i][j]<0)
				grad[i][j]=0;
		}
	}
	
	//������ 
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
