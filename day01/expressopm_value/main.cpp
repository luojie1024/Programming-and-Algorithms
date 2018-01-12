#include <iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int factor_value();
int term_value();
int expression_value();


int main(int argc, char** argv) {
	cout<<expression_value()<<endl; 
	getchar();
	return 0;
}

//处理表达式 
int expression_value()
{
	//先求得第一项的值 
	int result=term_value();
	//判断是否还有项 
	bool more=true; 
	while(more)
	{
		//看第一项的值，但不取走 
		char op=cin.peek();
		if(op=='+'||op=='-')
		{
			//取走一个字符 
			cin.get();
			int value=term_value();
			if(op=='+')
				result+=value;
			else
				result-=value; 
		}
		else
			more=false;
	} 
	return result;
}


//质的处理 
int term_value()
{
	int result=factor_value();
	while(true)
	{
		char op=cin.peek();
		if(op=='*'||op=='/')
		{
			cin.get();
			int value=factor_value();
			if(op=='*')
				result*=value;
			else
				result/=value;
		}
		else
			break;
	}
	return result;
} 


int factor_value()
{
	int result=0;
	char c=cin.peek();
	if(c=='(')
	{
		cin.get();
		result=expression_value();
		cin.get();
	}else
	{
		//逐个取出数位，拼接成数字 
		while(isdigit(c))
		{
			result=10*result+c-'0';
			cin.get();
			c=cin.peek();
		}
	}
	return result;
}
