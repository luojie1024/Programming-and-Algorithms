#include <iostream>
using namespace std;
 

int main(int argc, char** argv) {
	//����˹���� 
	int box[19][11]={0}; 
	//���� 
	int tetris[5][5];
	int temp[5][5];
	int result_row=-1; 
	int flag=0; 
	//�к�
	int  column;
	//���뷽��ͼ 
	for(int i=1;i<=15;i++) 
	{
		for(int j=1;j<=10;j++)
		{
			cin>>box[i][j];
		}
	}
	//��ʼ�������½� 
	for(int i=1;i<=10;i++)
		box[16][i]=1;
		
	//���뷽��
	for(int i=1;i<=4;i++) 
	{
		for(int j=1;j<=4;j++)
		{
			cin>>tetris[i][j];
			//��ʼ�� 
		}
	}
	
	//�����к� 
	cin>>column;
	//�����ж�1-10�� 
	for(int i=1;i<=15;i++)
	{
		 for(int j=1;j<=4;j++)
		 {
		 	for(int k=1;k<=4;k++)
		 	{
		 		//[1][1]      [2-1][3+1-1] ����Ƿ���Խ������������¼��һ����λ�� ||(box[16][column+k-1]+tetris[4][k])>0
		 		if((tetris[j][k]+box[i+j-1][column+k-1])==2)
		 		{
		 			result_row=(i-1);
		 			flag=1;
		 			break;
				}
			}
			if(flag==1)
				break;
		 }
		 if(flag==1)
		 	break;
		 //ȫ���б�����,��ûԽ�磬��������� 
		 if(i==15)
		 	result_row=15; 
	}
	
	//������ 
	for(int i=1;i<=4;i++) 
	{
		for(int j=1;j<=4;j++)
		{
			box[i+result_row-1][column+j-1]+= tetris[i][j]; 
		}
	}
	
	//�������ͼ 
	for(int i=1;i<=15;i++) 
	{
		for(int j=1;j<=10;j++)
		{
			if(j==10)
				cout<<box[i][j]<<endl;
			else
				cout<<box[i][j]<<' ';
		} 
	}
	return 0;
}
