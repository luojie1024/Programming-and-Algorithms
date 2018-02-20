#include <iostream>
#include <vector> 
#define MAX_LENGTH 501
using namespace std;

enum Direction{Bottom,Bottom_left,Right,Top_right}flag;
int grad[MAX_LENGTH][MAX_LENGTH]; 

int main(int argc, char** argv) {
	int n;
	vector<int> vec_Z;
	cin>>n;
	//���� 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>grad[i][j];
		}
	}
	
	//��ʼ����һ��λ�� 
	int i=1,j=1;
	flag=Right;
	vec_Z.push_back(grad[1][1]);
	//��ʼZɨ�� 
	for(int k=1;k<n*n;k++)
	{
		switch(flag)
		{
			case Bottom:
			i++;
			vec_Z.push_back(grad[i][j]);
			//�������߽磬�����ϣ��ұ߽磬������ 
			if(j==1)
				flag=Top_right;
			else if(j==n)
				flag=Bottom_left;
			break;
			
			case Bottom_left:
			i++;j--;
			vec_Z.push_back(grad[i][j]);
			//������߽�ʱ�������� �� 
			if(j==1&&i!=n)
				flag=Bottom;
			else if(i==n)
				flag=Right;
			break;
			
			case Right:
			j++;
			vec_Z.push_back(grad[i][j]);
			if(i==1)//�Ƿ����Ͻ� 
				flag=Bottom_left;		
			else if(i==n) 
				flag=Top_right; 
			break;
			
			case Top_right:
			i--;j++;
			vec_Z.push_back(grad[i][j]);
			//�����Ͻ� ����Ϊ�ұ� 
			if(i==1&&j!=n)
				flag=Right;
			else if(j==n)//�����ҽ� ����������
				flag=Bottom; 
			break;
		} 
	}
	
	//������� 
	for(vector<int>::iterator it=vec_Z.begin();it!=vec_Z.end();it++)
		cout<<*it<<' ';	
	
	return 0;
}
