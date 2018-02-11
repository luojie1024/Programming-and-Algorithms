#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_LENTHG 1000
using namespace std; 

class Temp
{
	public:
		int number;
		int postion;
};

//排队操作 
void computer(Temp temp,vector<int> &line,int n)
{
	int now_postion=0,move_postion=0;
	for(int i=0;i<n;i++)
	{
		//如果是需要移动的学生，则记录位置 
		if(line[i]==temp.number)
		{
			//找到位置 
			now_postion=i;
			//插入的位置 
			move_postion=now_postion+temp.postion;
			//移出队伍 
			line.erase(line.begin()+now_postion);
			//插入队伍 
			line.insert(line.begin()+move_postion,temp.number);
			break;
		}
	}
}

int main(int argc, char** argv) {
	int n,m;
	cin>>n;
	cin>>m;
	vector<int> line;
	Temp temp;
	//初始化队列 
	for(int i=1;i<=n;i++)
		line.push_back(i);
	//输入数据 
	for(int i=1;i<=m;i++)
	{
		//输入数据 
		cin>>temp.number>>temp.postion;
		computer(temp,line,n);
	}
	//输出 
	for(int i=0;i<n;i++)
	{
		if(i==(n-1))
			cout<<line[i];
		else 
			cout<<line[i]<<' '; 
	}
		
	return 0;
}
