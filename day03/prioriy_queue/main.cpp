#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<double> pq1;
    pq1.push(6.1);
    pq1.push(3.2);
    pq1.push(4.5);
    pq1.push(7.4);

    while (!pq1.empty()) {
        cout<<pq1.top()<<" ";
        pq1.pop();
    }

    cout<<endl;

    priority_queue<double,vector<double >,greater<double> > pq2;
    pq2.push(1.1);
    pq2.push(9.2);
    pq2.push(4.5);
    pq2.push(7.4);
    while (!pq2.empty()) {
        cout<<pq2.top()<<" ";
        pq2.pop();
    }

    cout<<endl;

    priority_queue<double,vector<double >,less<double> > pq3;
    pq3.push(1.1);
    pq3.push(9.2);
    pq3.push(4.5);
    pq3.push(7.4);
    while (!pq3.empty()) {
        cout<<pq3.top()<<" ";
        pq3.pop();
    }
    return 0;
}