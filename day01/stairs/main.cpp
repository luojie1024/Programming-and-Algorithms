#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int N;
int stairs(int n)
{
	if(n<0)
		return 0;
	else
		return 1;
	return stairs(n-1)+stairs(n-2);	
} 
int main(int argc, char** argv) {
	while(cin>>N)
		cout<<stairs(N)<<endl;
	return 0;
}
