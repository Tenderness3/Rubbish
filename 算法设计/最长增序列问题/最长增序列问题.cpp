#include<iostream>
#define max(a, b) ((a)>(b)?(a):(b))
 
const int INF = 1000000;
const int n = 6;
int a[n] = {4, 2, 3, 1, 5, 6};
 
int dp[n];
int dp1(){
	int res = 0;
	for (int i = 0; i < n; i++){
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{							  	 //0, 1, 2, 3, 4, 5
			if (a[i] > a[j])             //4, 2, 3, 1, 5, 6
			{
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		res = max(dp[i], res);
	}
 
	return res;
}
 
int main(){
	printf("%d\n", dp1());
	system("pause");
	return 0;
}
