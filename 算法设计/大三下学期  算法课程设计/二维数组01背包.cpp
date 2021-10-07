#include<iostream>
#include<algorithm>
using namespace std;
int m,n ;        //m为背包的容量，n是物品的数量 
int dp[31][201]; //状态转移方程 ,二维的数组 
int w[31];       //物品对应的重量 
int c[31];       //物品的价值 
int main(){
	cout<<"请输入背包的容量及物品的数量："<<endl; 
	cin>>m>>n;
	cout<<"请输入物品的重量及其对应的价值："<<endl;
	for(int i = 1; i <= n; i++)
	cin>>w[i]>>c[i];
	for(int i = 1; i<=n;i++){    //逐行进行填充 
		for(int j=1;j<=m;j++)
        {		
            if(j>=w[i])          
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);//dp[i-1][j]没有选择当前商品的情况 
                else
                dp[i][j]=dp[i-1][j];     //上一行的直接落下来     
        }
    }
        cout<<"最大价值为："<<dp[n][m];
        return 0;
}
