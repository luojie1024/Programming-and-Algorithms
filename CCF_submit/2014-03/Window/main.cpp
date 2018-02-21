#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_LENGTH 2560
#define MAX_M 11 
using namespace std;

//������ 
class Area
{
	public:
		int id;
		int star_x,star_y;
		int end_x,end_y;
		
};

//����¼� 
class Click
{
	public:
		int click_x,click_y;
};

//�ȽϹ��� 
bool compare(Area a,Area b)
{
	if(a.id>b.id)
		return true;
	else 
		return false;
}

int main(int argc, char** argv) {
	int n,m;
	Click click[MAX_M];
	Area area,area_temp;
	vector<Area> vec_area;
	cin>>n>>m;
	//�������� 
	for(int i=1;i<=n;i++)
	{
		area.id=i;
		cin>>area.star_x>>area.star_y>>area.end_x>>area.end_y;
		vec_area.push_back(area);
	}
	
	//�������¼� 
	for(int i=1;i<=m;i++)
	{
		cin>>click[i].click_x>>click[i].click_y;
	}
	
	//���㼶���� 
	sort(vec_area.begin(),vec_area.end(),compare);

	
	//�������¼� 
	for(int i=1;i<=m;i++)
	{
		for(vector<Area>::iterator it=vec_area.begin();it!=vec_area.end();it++)
		{
			//������Χ�� 
			if(click[i].click_x>=it->star_x&&click[i].click_x<=it->end_x&&click[i].click_y>=it->star_y&&click[i].click_y<=it->end_y)
			{
				//�������� 
				area_temp=*it;
				//��������� 
				cout<<it->id<<endl; 
				//���б����Ƴ������� 
				vec_area.erase(it);
				break;
			}
			//���û���ҵ���Ӧ������ 
			if((it+1)==vec_area.end()) 
				cout<<"IGNORED"<<endl;
		}
		//���Ƴ��������ö� 
		vec_area.insert(vec_area.begin(),area_temp);
	}
	return 0;
}
