#include <iostream>
#include <string>
#include <cmath>
#define MAX_LENGTH 101
using namespace std;


int main() {
    string str;
    int result;
    while (cin >> str) {
        result=0;
        str=str.substr(2);
        for (int i = str.length()-1,j=0; i >=0; --i,++j) {
            if (str[i] >= 'A' && str[i] <= 'F') {
                result+=(str[i]-'A'+10)*pow(16,j);
            } else {
                result+=(str[i]-'0')*pow(16,j);
            }
        }
        cout<<result<<endl;
    }
    return 0;
}
