#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

bool fun(string str,string s1,string s2)
{
    //s1或者s2从0开始找到
    int pos1=str.find(s1,0);

    //如果s1未找到
    if(str.find(s1,0)==string::npos)
        return false;

    //开始pos1指向s1的开头，现在我们把它指向s1的末尾的后一个位置
    pos1+=s1.length();

    //s2从s1的结尾开始找未找到
    if(str.find(s2,pos1)==string::npos)
    {
       return false;
    }
    //找到了
    return true;

}
int main() {
    string str;
    string s1,s2;
    bool forward=0,backward=0;
    while(cin>>str>>s1>>s2)
    {
        forward=fun(str,s1,s2);
        reverse(str.begin(),str.end());
        backward=fun(str,s1,s2);
        if(!forward&&!backward)
            cout<<"invalid"<<endl;
        else if(forward&&!backward)
            cout<<"forward"<<endl;
        else if(!forward&&backward)
            cout<<"backward"<<endl;
        else if(forward&&backward)
            cout<<"both"<<endl;
    }
    return 0;
}