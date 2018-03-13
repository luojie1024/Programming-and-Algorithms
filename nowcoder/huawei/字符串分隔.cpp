#include <iostream>
#include <string>
#include <vector>
#define MAX_LENGTH 101
using namespace std;


int main() {
    int n=2;
    vector<string> vecs;
    string s1;
    while(n)
    {

        n--;
        cin>>s1;
        int pos=0;
        if(s1.length()<8)
        {
            while(s1.length()!=8)
                s1+='0';
            vecs.push_back(s1);
            continue;
        } else {
            while(s1.length()-pos>8)
            {
                string str=s1.substr(pos,8);
                vecs.push_back(str);
                pos+=8;
            }
            s1=s1.substr(pos);
            while(s1.length()!=8)
                s1+='0';
            vecs.push_back(s1);
        }
    }

    for (auto v:vecs) {
        cout<<v<<endl;
    }
    return 0;
}
