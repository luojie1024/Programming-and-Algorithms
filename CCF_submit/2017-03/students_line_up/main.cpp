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

//�ŶӲ��� 
void computer(Temp temp,vector<int> &line,int n)
{
	int now_postion=0,move_postion=0;
	for(int i=0;i<n;i++)
	{
		//�������Ҫ�ƶ���ѧ�������¼λ�� 
		if(line[i]==temp.number)
		{
			//�ҵ�λ�� 
			now_postion=i;
			//�����λ�� 
			move_postion=now_postion+temp.postion;
			//�Ƴ����� 
			line.erase(line.begin()+now_postion);
			//������� 
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
	//��ʼ������ 
	for(int i=1;i<=n;i++)
		line.push_back(i);
	//�������� 
	for(int i=1;i<=m;i++)
	{
		//�������� 
		cin>>temp.number>>temp.postion;
		computer(temp,line,n);
	}
	//��� 
	for(int i=0;i<n;i++)
	{
		if(i==(n-1))
			cout<<line[i];
		else 
			cout<<line[i]<<' '; 
	}
		
	return 0;
}
