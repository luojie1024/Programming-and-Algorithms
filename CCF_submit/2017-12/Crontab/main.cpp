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


int leap_year[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int normal_year[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

string months[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
string weeks[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

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


bool isLeapYear(int year)
{
	if((year%4==0&&year%100!=0)||(year%400==0))
		return true;
	else
		return false;
}

int computWeek(Time time)
{
	int sumday=0;
	int * arr_month;
	//如果是1970年 
	if(time.year==1970)
	{
    	if(isLeapYear(1970)) 
			arr_month=leap_year;
		else 
			arr_month=normal_year;
		for(int month=1;month<time.month;month++)
			sumday+=arr_month[month];
	}else
	{
		//先处理整年 
		for(int year=1970;year<time.year;year++)
		{
			//闰年处理 
	    	if(isLeapYear(year)) 
				sumday+=366;
			else
				sumday+=365;
		}
		
    	if(isLeapYear(time.year)) 
			arr_month=leap_year;
		else 
			arr_month=normal_year;
			
		for(int month=1;month<time.month;month++)
			sumday+=arr_month[month];
		
	}
	
	//加上剩下的天数 
	sumday+=time.day_of_month-1;
	//	
	sumday+=4;
	return sumday%7; 	
}

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

int convnumber(string s)
{
	for(int i=0;i<12;i++)
	{
		if(s.compare(months[i])==0)
		{
			return i+1;
		}
	}
	
	for(int j=0;j<7;j++)
	{
		if(s.compare(weeks[j])==0)
		{
			return j;
		}
	}
	 
	return 0;
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
			//获得字符数组
        	cstr=it->c_str();
            
            //是否是范围值
            if(it->find("-")!=string::npos)
            {
            	int start,end;
        		vector<string> v2;
        		//逗号分割
        		v2=split(*it,'-');
        		if(v2[0].length()==3)
        		{
        			start=convnumber(v2[0]);
				}else{
					start=cstr[0]-'0';
				}
				if(v2[1].length()==3)
        		{
        			start=convnumber(v2[1]);
				}else{
					end=cstr[2]-'0';
				}
				
				//范围赋值 
                for(int k=start;k<=end;k++)
                {
                    arr[k]=1;
                }
            }else{
            	int postion=0;
            	if(it->length()==3)
            	{
            		postion=convnumber(*it);
				}
				else{
					postion=strtoint(*it);					
				}
				arr[postion]=1;
            }
        }
    }else{//单个出现
		if(s.length()==3)
		{
			arr[convnumber(s)]=1;
		}else{
			arr[strtoint(s)]=1;	
		}
	}
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
        /*for(int i=0;i<8;i++)
        {
        	//cout<<temp_crontab.minutes[i];
        	cout<<temp_crontab.day_of_week[i];
        	//cout<<temp_crontab.hours[i];
		}*/
        	
        vec_crontab.push_back(temp_crontab);
    }

    //排序
    sort(vec_crontab.begin(),vec_crontab.end(),compare);

	//计算开始时间是星期几
	int startweek;
	startweek=computWeek(start_time);
	//cout<<startweek<<endl;
	//结束标志 
	int end_flag=0;
    //输出
    for(int year=start_time.year;year<=end_time.year;year++)
    {
    	int * arr_month;
    	if(isLeapYear(year)) 
			arr_month=leap_year;
		else 
			arr_month=normal_year;
		
			
        for(int month=start_time.month;month<=13;month++)
        {		
            for(int day=start_time.day_of_month;day<=arr_month[month];day++)
            {
                for(int hours=start_time.hours;hours<=25;hours++)
                {
                    for(int min=start_time.minutes;min<=60;min++)
                    {
                        for(vector<Crontab>::iterator it=vec_crontab.begin();it!=vec_crontab.end();it++)
                        {
                            if((it->month[month]==1||it->month[0]==-2)&&
                               (it->day_of_month[day]==1||it->day_of_month[0]==-2)&&
                               (it->hours[hours]==1||it->hours[0]==-2)&&
                               (it->minutes[min]==1||it->minutes[0]==-2)&&(it->day_of_week[startweek]==1||it->day_of_week[0]==-2))
                            {
                                cout<<year;
								if(month<10)
									cout<<0;
								cout<<month;
								if(day<10)
									cout<<0;
								cout<<day;
								if(hours<10)
									cout<<0;
								cout<<hours;
								if(min<10)
									cout<<0;
								cout<<min;
								cout<<' '<<it->command<<endl;
                            }
                            
                        }
                     	//到了结束时间 
                        if(year==end_time.year&&month==end_time.month&&
						day==end_time.day_of_month&&hours==end_time.hours&&min==end_time.minutes)
						{
							end_flag=1;
							break; 
						}
                    }
                    start_time.minutes=0;
                    if(end_flag)
                    	break;
                }
                startweek++;
                startweek%=7;
                start_time.hours=0;
                if(end_flag)
                	break;
            }
            start_time.day_of_month=1;
            if(end_flag)
            	break;
        }
        start_time.month=1;
	    if(end_flag)
	    	break;
    }
    return 0;
}
