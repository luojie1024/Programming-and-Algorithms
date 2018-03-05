#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n,temp;
    vector<int> vec_data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        vec_data.push_back(temp);
    }

    sort(vec_data.begin(),vec_data.end());

    int count=1;
    int result=0;
    for(int i=1;i<n;i++)
    {
        //连续两题符合要求
        if(vec_data[i]-vec_data[i-1]<=10)
        {
            count++;
        } else{//连续题目不符合要求
            if(count%3!=0)//没有达到连续三题
                result+=(3-count%3);//加上需要出的题目
            count=1;//又从第一题开始数
        }
    }

    if(count%3!=0)//如果还有剩余题目
        result+=(3-count%3);//加上要出的题目
    cout<<result;
    return 0;
}