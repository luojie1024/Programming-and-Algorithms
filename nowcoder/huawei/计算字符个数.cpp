#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
    string str;
    char s;
    int count=0;
    cin>>str>>s;
    s=tolower(s);
    for (char st:str) {
        st=tolower(st);
        if (st==s)
            count++;
    }
    cout<<count;
    return 0;
}
