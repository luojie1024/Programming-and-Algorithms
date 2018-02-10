#include <iostream>
#include<algorithm>
#include<vector>
#define MAX_NUMBER 1001
using namespace std;

//上课老师对象
class Teacher{
	public:
		int id;
		int star_time;
		int end_time;
};

//上课列表的排序规则
bool compareA(const Teacher &a, const Teacher &b)
{
	//开始时间从小到大排序
	if(a.star_time<b.star_time)
		return true;
	//开始时间相同，则按结束时间从小到大排序
	else if(a.star_time==b.star_time&&a.end_time<b.end_time)
		return true;
	else
		return false;
}

//使用列表的排序规则
bool compareB(const Teacher &a,const Teacher &b)
{
	//开始时间从小到大排序
    if(a.end_time<b.end_time)
        return true;
    //结束时间相等，则按id排序
    else if(a.end_time==b.end_time&&a.id<b.id)
		return true;
	else
		return false;
}



int main(int argc, char** argv) {
	int n,k;
	int key_box[MAX_NUMBER];
	vector<Teacher> teachers;
	vector<Teacher>	use_key;
	Teacher temp;
	cin>>n>>k;
    int max_time = 0;
    int min_time = 10100;
    //初始化钥匙数组
    for(int i=1;i<=MAX_NUMBER;i++)
        key_box[i]=i;
    //输入数据
	for(int i=0;i<k;i++)
	{
		cin>>temp.id>>temp.star_time>>temp.end_time;
        temp.end_time=temp.star_time+temp.end_time;
        //得到最大最小范围
        temp.end_time>max_time?max_time=temp.end_time:0;
        temp.star_time<min_time?min_time=temp.star_time:0;
		teachers.push_back(temp);
	}
	//排序
    stable_sort(teachers.begin(), teachers.end(), compareA);
	//一个循环一个时间单位
	for(int j=min_time;j<=max_time;j++)
	{
        //cout<<"teachers:"<<teachers.size()<<" use_key:"<<use_key.size();

        //使用列表按结束时间，id排序
        stable_sort(use_key.begin(),use_key.end(),compareB);

        //如果当前使用列表不为空，则开始还钥匙
        if(use_key.size()!=0&&use_key.front().end_time==j)
        {
            //遍历要还的钥匙
            for(vector<Teacher>::iterator it=use_key.begin();it!=use_key.end();)
            {
                //如果有要还的钥匙
                if(it->end_time==j)
                {
                    //找到最靠坐边的空位，放钥匙
                    for(int k=1;k<=n;k++)
                    {
                        if(key_box[k]==-1)
                        {
                            key_box[k]=it->id;
                            break;
                        }
                    }
                    //删除元素，返回值指向已删除元素的下一个位置
                    it=use_key.erase(it);
                }
                else{//如果没有要还的钥匙
                    //退出遍历
                    break;
                }
            }
        }

        //遍历当前时间要拿的钥匙
		for(vector<Teacher>::iterator it=teachers.begin();teachers.size()!=0;)
		{
			//如果有要拿的钥匙
			if(it->star_time==j)
			{
				//标注拿走钥匙
                for(int i=1;i<=n;i++)
                    if(key_box[i]==it->id)
				        key_box[i]=-1;
				//添加到使用列表
				use_key.push_back(*it);
				//移除当前列
				it=teachers.erase(it);
			}else{//如果没有要拿的钥匙
                //退出遍历
				break;
			}

		}
	}

    //输出结果
	for(int i=1;i<=n;i++)
    {
        if (i == n)
            cout << key_box[i];
        else
            cout << key_box[i] << " ";
    }
  	return 0;
}
