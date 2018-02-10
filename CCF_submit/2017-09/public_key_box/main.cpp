#include <iostream>
#include<algorithm>
#include<vector>
#define MAX_NUMBER 1001
using namespace std;

//�Ͽ���ʦ����
class Teacher{
	public:
		int id;
		int star_time;
		int end_time;
};

//�Ͽ��б���������
bool compareA(const Teacher &a, const Teacher &b)
{
	//��ʼʱ���С��������
	if(a.star_time<b.star_time)
		return true;
	//��ʼʱ����ͬ���򰴽���ʱ���С��������
	else if(a.star_time==b.star_time&&a.end_time<b.end_time)
		return true;
	else
		return false;
}

//ʹ���б���������
bool compareB(const Teacher &a,const Teacher &b)
{
	//��ʼʱ���С��������
    if(a.end_time<b.end_time)
        return true;
    //����ʱ����ȣ���id����
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
    //��ʼ��Կ������
    for(int i=1;i<=MAX_NUMBER;i++)
        key_box[i]=i;
    //��������
	for(int i=0;i<k;i++)
	{
		cin>>temp.id>>temp.star_time>>temp.end_time;
        temp.end_time=temp.star_time+temp.end_time;
        //�õ������С��Χ
        temp.end_time>max_time?max_time=temp.end_time:0;
        temp.star_time<min_time?min_time=temp.star_time:0;
		teachers.push_back(temp);
	}
	//����
    stable_sort(teachers.begin(), teachers.end(), compareA);
	//һ��ѭ��һ��ʱ�䵥λ
	for(int j=min_time;j<=max_time;j++)
	{
        //cout<<"teachers:"<<teachers.size()<<" use_key:"<<use_key.size();

        //ʹ���б�����ʱ�䣬id����
        stable_sort(use_key.begin(),use_key.end(),compareB);

        //�����ǰʹ���б�Ϊ�գ���ʼ��Կ��
        if(use_key.size()!=0&&use_key.front().end_time==j)
        {
            //����Ҫ����Կ��
            for(vector<Teacher>::iterator it=use_key.begin();it!=use_key.end();)
            {
                //�����Ҫ����Կ��
                if(it->end_time==j)
                {
                    //�ҵ�����ߵĿ�λ����Կ��
                    for(int k=1;k<=n;k++)
                    {
                        if(key_box[k]==-1)
                        {
                            key_box[k]=it->id;
                            break;
                        }
                    }
                    //ɾ��Ԫ�أ�����ֵָ����ɾ��Ԫ�ص���һ��λ��
                    it=use_key.erase(it);
                }
                else{//���û��Ҫ����Կ��
                    //�˳�����
                    break;
                }
            }
        }

        //������ǰʱ��Ҫ�õ�Կ��
		for(vector<Teacher>::iterator it=teachers.begin();teachers.size()!=0;)
		{
			//�����Ҫ�õ�Կ��
			if(it->star_time==j)
			{
				//��ע����Կ��
                for(int i=1;i<=n;i++)
                    if(key_box[i]==it->id)
				        key_box[i]=-1;
				//��ӵ�ʹ���б�
				use_key.push_back(*it);
				//�Ƴ���ǰ��
				it=teachers.erase(it);
			}else{//���û��Ҫ�õ�Կ��
                //�˳�����
				break;
			}

		}
	}

    //������
	for(int i=1;i<=n;i++)
    {
        if (i == n)
            cout << key_box[i];
        else
            cout << key_box[i] << " ";
    }
  	return 0;
}
