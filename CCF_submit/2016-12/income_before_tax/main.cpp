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
	//��ʼ��˰��ȼ�
	Tax taxs[8];
	//��ʼ�������˰���� 
	taxs[0].income_before_tax=3500; 
	taxs[0].income_after_tax=3500; 
	taxs[0].tax_rate=0; 
	 for(int i=1;i<8;i++)
	 {
	 	//��ʼ��˰�� 
	 	taxs[i].tax_rate=tax_rates[i];
	 	//��ʼ����Χ 
	 	//��ʼ��˰ǰ����=��һ�׶�+��Χ 
		taxs[i].income_before_tax=taxs[i-1].income_before_tax+income_scope[i];
		//��ʼ��˰������=��һ�׶�˰��+��Χ*��1-˰�ʣ� 
		taxs[i].income_after_tax=taxs[i-1].income_after_tax+income_scope[i]*(1-tax_rates[i]);
	 }
	 //����˰�� 
	 for(int i=0;i<8;i++)
	 {
	 	//����˰������ 
	 	if(T>taxs[i].income_after_tax)
	 		//����ӵ�е�ǰ˰ǰ���� 
	 		result=taxs[i].income_before_tax;
	 	else
	 	{
	 		//С��3500����˰ 
	 		if(T<=3500)
	 			result=T;
	 		else
	 		{
	 			//��ǰ˰ǰ����+����˰�ղ��� 
		 		result+=(T-taxs[i-1].income_after_tax)/(1.0-taxs[i].tax_rate);
				break;	
			}
	 		
		}
	 		
	 } 
	 //������ 
	cout<<result;
	return 0;
}
