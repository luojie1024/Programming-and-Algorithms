#include <iostream>
#include <vector>
#include <string>
#include<stdlib.h>
#include <math.h>
#include <algorithm>
#define MAX_MIN 61
#define MAX_HOURS 25
#define MAX_DAY_OF_MONTH 33
#define MAX_MONTH 13
#define MAX_DAY_OF_WEEK 8
using namespace std;



enum Month{Jan=1,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
enum Week{Sun,Mon,Tue,Wed,Thu,Fri,Sat};

class Crontab
{
public:
    int minutes[MAX_MIN]={};
    int hours[MAX_HOURS]={};
    int day_of_month[MAX_DAY_OF_MONTH]={};
    int month[MAX_MONTH]={};
    int day_of_week[MAX_DAY_OF_WEEK]={};
    string command;
};

class Time
{
public:
    int minutes;
    int hours;
    int day_of_month;
    int month;
    int year;
};


//字符串分割
vector<string> split(const string &s,const char &split)
{
    vector<string> result;
    string str_temp;

    string::size_type pos1,pos2;
    pos2=s.find(split);
    pos1=0;
    while(string::npos!=pos2)
    {
        result.push_back(s.substr(pos1,pos2-pos1));

        pos1=pos2+1;
        pos2=s.find(split,pos1);
    }

    result.push_back(s.substr(pos1));

    return result;
}


bool isnumber(char c)
{
	if(c>=0&&c<='9')
		return true;
	else 
		return false;
}

char * convnumber(string s)
{
	return 0;
}



//输入处理
void input(string s,int arr[])
{
    //如果是*号
    if(s.compare("*")==0)
    {
        //-2代表*号
        arr[0]=-2;
    }else if(s.find(",")!=string::npos)
    {
        vector<string> v1;
        //逗号分割
        v1=split(s,',');
        for(vector<string>::iterator it=v1.begin();it!=v1.end();it++)
        {
        	const char *cstr;
        	if(it->length()>3||!isnumber(it->c_str()[0]))
        	{
        		cstr=convnumber(*it);
			}else{
				//获得字符数组
            	cstr=it->c_str();
			}
            
            //是否是范围值
            if(it->find("-")!=string::npos)
            {
                for(int k=cstr[0]-'0';k<=cstr[2]-'0';k++)
                {
                    arr[k]=1;
                }
            }else{
                arr[cstr[0]-'0']=1;
            }
        }
    }
}





int strtoint(string s)
{
    int result=0,j=0;
    for(int i=s.length();i>0;i--)
    {
        result=(s[i-1]-'0')*pow(10,j)+result;
        j++;
    }
    return result;
}

//排序规则
bool compare(Crontab a,Crontab b)
{
    if(a.month<b.month)
        return true;
    else if(a.month==b.month&&a.day_of_month<b.day_of_month)
        return true;
    else if(a.month==b.month&&a.day_of_month==b.day_of_month&&a.hours<b.hours)
        return true;
    else if(a.month==b.month&&a.day_of_month==b.day_of_month&&a.hours==b.hours&&a.minutes<=b.minutes)
        return true;
    else
        return false;

}

int main(int argc, char** argv) {
    int n;
    vector<Crontab> vec_crontab;

    string str;
    Time start_time,end_time;
    /*
    for(int i=0;i<60;i++)
        cout<<temp_crontab.minutes[i];
    */

    cin>>n;
    //输入时间
    cin>>str;
    start_time.year=strtoint(str.substr(0,4));
    start_time.month=strtoint(str.substr(4,2));
    start_time.day_of_month=strtoint(str.substr(6,2));
    start_time.hours=strtoint(str.substr(8,2));
    start_time.minutes=strtoint(str.substr(10,2));

    cin>>str;
    end_time.year=strtoint(str.substr(0,4));
    end_time.month=strtoint(str.substr(4,2));
    end_time.day_of_month=strtoint(str.substr(6,2));
    end_time.hours=strtoint(str.substr(8,2));
    end_time.minutes=strtoint(str.substr(10,2));

    //输入命令
    for(int i=0;i<n;i++)
    {
        Crontab temp_crontab;
        cin>>str;
        input(str,temp_crontab.minutes);
        cin>>str;
        input(str,temp_crontab.hours);
        cin>>str;
        input(str,temp_crontab.day_of_month);
        cin>>str;
        input(str,temp_crontab.month);
        cin>>str;
        input(str,temp_crontab.day_of_week);
        cin>>temp_crontab.command;
        vec_crontab.push_back(temp_crontab);
    }

    //排序
    sort(vec_crontab.begin(),vec_crontab.end(),compare);

    //输出
    for(int year=start_time.year;year<=end_time.year;year++)
    {
        for(int month=start_time.month;month<=end_time.month;month++)
        {
            for(int day=start_time.day_of_month;day<=end_time.day_of_month;day++)
            {
                for(int hours=start_time.hours;hours<=end_time.hours;hours++)
                {
                    for(int min=start_time.minutes;min<=end_time.minutes;min++)
                    {
                        for(vector<Crontab>::iterator it=vec_crontab.begin();it!=vec_crontab.end();it++)
                        {
                            if((it->month[month]==1||it->month[0]==-2)&&
                               (it->day_of_month[day]==1||it->day_of_month[0]==-2)&&
                               (it->hours[hours]==1||it->hours[0]==-2)&&
                               (it->minutes[min]==1||it->minutes[0]==-2)
                                    )
                            {
                                cout<<year<<month<<day<<hours<<min<<' '<<it->command<<endl;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
