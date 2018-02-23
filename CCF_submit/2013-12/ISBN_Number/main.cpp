#include <iostream>
#include <string>
#define MAX_LENGTH 10
using namespace std;


int main(int argc, char** argv) {
	string str;
	int numbers[10]={};
	int flag=0;
	cin>>str;
	
	//输入 
	for(int i=0,j=1;i<str.length()-2;i++)
	{
		if(str[i]!='-')
		{
			flag+=(j*(str[i]-'0'));
			j++;
		}
	}
	
	//判断校验位 
	char c;
	c=flag%11;
	if(c==10)
		c='X';
	else
		c=c+'0';
	
	//输出 
	if(c==(str[str.length()-1]))
		cout<<"Right"<<endl;
	else
	{
		str[str.length()-1]=c;
		cout<<str<<endl;
	}
	return 0;
}
