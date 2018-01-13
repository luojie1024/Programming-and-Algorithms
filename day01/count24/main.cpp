#include <iostream>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//�洢�����4������ 
double a[5];
#define EPS 1e-6
 
//�жϸ������Ƿ�Ϊ��
bool isZero(double x)
{
	return fabs(x)<=EPS;	
} 

//������a�����n����������24
bool count24(double a[],int n)
{
		if(n==1)
		{
			//�ж��Ƿ�Ϊ�� 
			if(isZero(a[0]-24))	
				return true;
			else
				return false;
		} 
		//���ڴ���м��� 
		double b[5]; 
		//ö������������� 
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				//ʣ�µĸ�����m=n-2
				int m=0;
				for(int k=0;k<n;k++)
					if(k!=i&&k!=j)
						//������������뵽b 
						b[m++]=a[k]; 
				b[m]=a[i]+a[j];
				if(count24(b,m+1))
					return true;
				b[m]=a[i]-a[j];
				if(count24(b,m+1))
					return true;
				b[m]=a[j]-a[i];
				if(count24(b,m+1))
					return true;
				b[m]=a[i]*a[j];
				if(count24(b,m+1))
					return true;
				b[m]=a[i]-a[j];
				if(count24(b,m+1))
					return true;
				b[m]=a[i]-a[j];
				if(count24(b,m+1))
					return true;		
				if(!isZero(a[j]))
				{
					b[m]=a[i]/a[j];
					if(count24(b,m+1))
						return true;
				}		
				if(!isZero(a[i]))
				{
					b[m]=a[j]/a[i];
					if(count24(b,m+1))
						return true;
				}
			}	
		} 
		
	return false;
} 


int main(int argc, char** argv) {
	int n;
	cin>>n;
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<4;i++)
			cin>>a[i];
		if(count24(a,n))
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}
	return 0;
}
