#include <iostream>
#include <map>
using namespace std;

template <class Key,class Value>

//reseting << sign
ostream & operator<<(ostream & o, const pair<Key,Value> &p)
{
    o<<"("<<p.first<<","<<p.second<<")";
    return o;
}

int main() {
    typedef map<int,double ,less<int> > mmid;
    mmid pair;

    cout<<"1)"<<pair.count(15)<<endl;

    //insert way 1
    pair.insert(mmid::value_type(15,3.7));
    //insert way 2
    pair.insert(make_pair(7,9.9));
    cout<<"2)"<<pair.count(15)<<endl;

    pair.insert(mmid::value_type(15,9.2));
    mmid::iterator it;
    cout<<"3)";
    for (it=pair.begin();it!=pair.end();it++)
        cout<<*it<<",";
    cout<<endl;

    cout<<"4)";
    int n=pair[40];
    for (it=pair.begin();it!=pair.end();it++)
        cout<<*it<<",";
    cout<<endl;

    cout<<"5.)";
    pair[15]=6.66;
    for (it=pair.begin();it!=pair.end();it++)
        cout<<*it<<",";
    return 0;
}