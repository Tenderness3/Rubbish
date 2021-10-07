#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int i,j,n;
	cin>>n;
	int *a = new int[n];
	//a = calloc (n+1,sizeof(int));
	for(i = 1; i <= n; i++){
		a[i] = 1;
	}
	for(i = 1; i <= n; i++){
		for(j = i; j <= n; j = j + i){
			a[i] = 1 - a[i];
		}
	}
	for(i = 1; i <= n; i++){
		if(a[i] = 0)
		cout<<i<<"is free";
	}
	return 0;
} 
