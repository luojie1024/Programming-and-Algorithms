#include <iostream>
using namespace std;

class Tax
{
	public:
		double income_before_tax;
		double income_after_tax;
		float tax_rate;
		
	public:
		void display()
		{
			cout<<"income_after_tax:"<<income_after_tax;
		}
};

int main(int argc, char** argv) {
	double T,real_income=0,result;
	float tax_rates[8]={0,0.03,0.1,0.2,0.25,0.3,0.35,0.45};
	double income_scope[8]={3500,1500,3000,4500,26000,20000,25000,100000};	
	cin>>T;
	//初始化税务等级
	Tax taxs[8];
	//初始化最低无税收入 
	taxs[0].income_before_tax=3500; 
	taxs[0].income_after_tax=3500; 
	taxs[0].tax_rate=0; 
	 for(int i=1;i<8;i++)
	 {
	 	//初始化税率 
	 	taxs[i].tax_rate=tax_rates[i];
	 	//初始化范围 
	 	//初始化税前收入=上一阶段+范围 
		taxs[i].income_before_tax=taxs[i-1].income_before_tax+income_scope[i];
		//初始化税后收入=上一阶段税后+范围*（1-税率） 
		taxs[i].income_after_tax=taxs[i-1].income_after_tax+income_scope[i]*(1-tax_rates[i]);
	 }
	 //计算税收 
	 for(int i=0;i<8;i++)
	 {
	 	//大于税后收入 
	 	if(T>taxs[i].income_after_tax)
	 		//至少拥有当前税前收入 
	 		result=taxs[i].income_before_tax;
	 	else
	 	{
	 		//小于3500不上税 
	 		if(T<=3500)
	 			result=T;
	 		else
	 		{
	 			//当前税前收入+超出税收部分 
		 		result+=(T-taxs[i-1].income_after_tax)/(1.0-taxs[i].tax_rate);
				break;	
			}
	 		
		}
	 		
	 } 
	 //输出结果 
	cout<<result;
	return 0;
}
