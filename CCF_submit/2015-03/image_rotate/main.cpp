#include <iostream>
#define MAX_LENGTH 1001
using namespace std;

int grad[MAX_LENGTH][MAX_LENGTH];
int result[MAX_LENGTH][MAX_LENGTH];

int main(int argc, char** argv) {
    int n,m;
    cin>>n>>m;
    //输入数据
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>grad[i][j];
        }
    }

    //图像转换
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            result[m-j+1][i]=grad[i][j];
        }
    }

    //输出结果
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==n)
                cout<<result[i][j]<<endl;
            else
                cout<<result[i][j]<<' ';
        }
    }

    return 0;
}
