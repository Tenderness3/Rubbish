//���ӷ� 
#include<iostream>
#include <cmath>
using namespace std;
int main(){
	int s,i,j,n;
	cin>>n;
	for(i = 1;i <= n; i++)
		s=1;  //��ʾ������
		for(j = 2; j <= i; j++)
			if(i%j==0)
				s =+ 1;
			if(s%2 == 1)
				cout<<i<<"is free";
			
		
	
	return 0;
} 
