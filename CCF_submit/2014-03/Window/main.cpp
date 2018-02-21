#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_LENGTH 2560
#define MAX_M 11 
using namespace std;

//区域类 
class Area
{
	public:
		int id;
		int star_x,star_y;
		int end_x,end_y;
		
};

//点击事件 
class Click
{
	public:
		int click_x,click_y;
};

//比较规则 
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
	//输入区域 
	for(int i=1;i<=n;i++)
	{
		area.id=i;
		cin>>area.star_x>>area.star_y>>area.end_x>>area.end_y;
		vec_area.push_back(area);
	}
	
	//输入点击事件 
	for(int i=1;i<=m;i++)
	{
		cin>>click[i].click_x>>click[i].click_y;
	}
	
	//按层级排序 
	sort(vec_area.begin(),vec_area.end(),compare);

	
	//处理点击事件 
	for(int i=1;i<=m;i++)
	{
		for(vector<Area>::iterator it=vec_area.begin();it!=vec_area.end();it++)
		{
			//在区域范围内 
			if(click[i].click_x>=it->star_x&&click[i].click_x<=it->end_x&&click[i].click_y>=it->star_y&&click[i].click_y<=it->end_y)
			{
				//拷贝区域 
				area_temp=*it;
				//输出区域编号 
				cout<<it->id<<endl; 
				//从列表中移除该区域 
				vec_area.erase(it);
				break;
			}
			//如果没有找到对应的区域 
			if((it+1)==vec_area.end()) 
				cout<<"IGNORED"<<endl;
		}
		//讲移除的区域置顶 
		vec_area.insert(vec_area.begin(),area_temp);
	}
	return 0;
}
