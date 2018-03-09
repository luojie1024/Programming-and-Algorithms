#include<iostream>
#include<map>
#include<string>
using namespace std;

class CStudent
{
public:
    struct CInfo {
        int id;
        string name;
    };
    //student score
    int score;
    //student info date
    CInfo info;
};

typedef multimap<int,CStudent::CInfo> MAP_STD;

int main()
{
    MAP_STD mp;
    CStudent student;
    string cmd;
    while(cin>>cmd)
    {
        if(cmd=="Add")
        {
            cin>>student.info.name>>student.info.id>>student.score;
            //insert cin date
            mp.insert(MAP_STD::value_type(student.score,student.info));
        }
        else if(cmd=="Query")
        {
            int score;
            cin>>score;
            //find lower bound point
            MAP_STD::iterator it=mp.lower_bound(score);
            //is find date [begin,it)
            if(it!=mp.begin())
            {
                --it;
                score=it->first;
                MAP_STD::iterator max_it=it;
                int max_id=max_it->second.id;
                for (; it!=mp.begin()&&it->first==score; --it)
                {
                    if (it->second.id > max_id)
                    {
                        max_it=it;
                        max_id=it->second.id;
                    }
                }
                //if it==mp.begin() end code
                if(it->first==score)
                {
                    if (it->second.id>max_id)
                    {
                        max_it=it;
                    }

                }
                cout<<max_it->second.name<<" "<<max_it->second.id<<" "<<max_it->first<<endl;
            }
            else
                cout<<"Nobody"<<endl;
        }
    }
    return 0;
}
