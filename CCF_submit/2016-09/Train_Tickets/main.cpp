#include <iostream>
#include <algorithm>
#define MAX_NUMBER 101
using namespace std;

class Line{
	public:
		int postion[6];
		int null_number;
};

int main(int argc, char** argv) {
	int n;
	int sample_value[MAX_NUMBER];
	Line  train[21];
	cin>>n;
	//输入样例数据 
	for(int i=1;i<=n;i++)
	{
		cin>>sample_value[i];
	}
	//初始化车厢座位
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=5;j++)
			train[i].postion[j]=(i-1)*5+j;
		train[i].null_number=5;
	}
	//处理样例n组 
	for(int i=1;i<=n;i++) 
	{
		//是否分配完毕 
		int flag=0;
		//从小到大遍历火车座位20排 
		for(int j=1;j<=20;j++)
		{
			//如果需要的座位小于等于当前排的座位，则安排在当前排 
			if(sample_value[i]<=train[j].null_number) 
			{
				//输出座位信息 
				for(int k=1;k<=sample_value[i];k++)
				{
					cout<<train[j].postion[5-train[j].null_number+k];
					//如果输入到最后一个信息，则换行 
					if(k==(sample_value[i]))
						cout<<endl;
					else 
						cout<<" ";
				} 
				//减去空座位 
				train[j].null_number-=sample_value[i];
				flag=1; 
				//选票完毕，跳出循环 
				break;
			}
		
		}
		//20排全部不足以连续分配，则单个分配
		if(flag==0)
		{
			//需要分配的位置数量 
			int temp=sample_value[i];
			for(int j=1;j<20;j++)
			{
				//只有当前排有位置，就分配 
				while(train[j].null_number!=0&&temp!=0)
				{
					cout<<train[j].postion[5-train[j].null_number+1];
					train[j].null_number--; 
					temp--;
					if(temp==0)
					{
						cout<<endl;
						break;
					}
					else
						cout<<" ";
				} 
				if(temp==0)
					break;
			}
		} 
	}
	return 0;
}
