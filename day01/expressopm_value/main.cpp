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

//������ʽ 
int expression_value()
{
	//����õ�һ���ֵ 
	int result=term_value();
	//�ж��Ƿ����� 
	bool more=true; 
	while(more)
	{
		//����һ���ֵ������ȡ�� 
		char op=cin.peek();
		if(op=='+'||op=='-')
		{
			//ȡ��һ���ַ� 
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


//�ʵĴ��� 
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
		//���ȡ����λ��ƴ�ӳ����� 
		while(isdigit(c))
		{
			result=10*result+c-'0';
			cin.get();
			c=cin.peek();
		}
	}
	return result;
}
