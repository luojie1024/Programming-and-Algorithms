#include <iostream>
using namespace std;
 

int main(int argc, char** argv) {
	//俄罗斯方块 
	int box[19][11]={0}; 
	//方块 
	int tetris[5][5];
	int temp[5][5];
	int result_row=-1; 
	int flag=0; 
	//列号
	int  column;
	//输入方格图 
	for(int i=1;i<=15;i++) 
	{
		for(int j=1;j<=10;j++)
		{
			cin>>box[i][j];
		}
	}
	//初始化方格下界 
	for(int i=1;i<=10;i++)
		box[16][i]=1;
		
	//输入方块
	for(int i=1;i<=4;i++) 
	{
		for(int j=1;j<=4;j++)
		{
			cin>>tetris[i][j];
			//初始化 
		}
	}
	
	//输入列号 
	cin>>column;
	//逐行判断1-10行 
	for(int i=1;i<=15;i++)
	{
		 for(int j=1;j<=4;j++)
		 {
		 	for(int k=1;k<=4;k++)
		 	{
		 		//[1][1]      [2-1][3+1-1] 检查是否有越界情况，有则记录上一步的位置 ||(box[16][column+k-1]+tetris[4][k])>0
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
		 //全部行遍历完,还没越界，则是最后行 
		 if(i==15)
		 	result_row=15; 
	}
	
	//计算结果 
	for(int i=1;i<=4;i++) 
	{
		for(int j=1;j<=4;j++)
		{
			box[i+result_row-1][column+j-1]+= tetris[i][j]; 
		}
	}
	
	//输出方格图 
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
