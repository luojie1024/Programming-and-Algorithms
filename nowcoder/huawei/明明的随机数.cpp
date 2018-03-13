#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    int temp;
    while (cin >> n) {
        set<int> sets;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            sets.insert(temp);
        }
        for (auto ele:sets) {
            cout << ele << endl;
        }
    }
    return 0;
}
