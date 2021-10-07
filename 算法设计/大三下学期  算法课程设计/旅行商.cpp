#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int a[21][21];         
int dp[1<<21][21];     

int main()
{
	printf("输入途径城市个数：");
	int n;
	scanf("%d",&n);	
	for(int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	//逻辑 右移 >> 将最后一位舍掉 11111-->1111 
   	//逻辑 左移 << 将最后一位加1  11111-->111110 
    //	与运算，只有1 1才能的1 ，否则为0
    //	| 异或运算 只要出现1就得到1 
    //	x&1==1 奇数   x&1==0 偶数 
	
	 
	memset(dp,0x3f,sizeof(dp));
	dp[1][1]=0;

	//当前在哪些点，下一个点。开始枚举 
	for(int i=0; i<(1<<n);i++)  //二进制集合。0为没走，1为走过。 
	{
		for(int now=1;now<=n;now++) //当前在哪个点 
		{
			if(!((i>>(now-1)) & 1))  //保证当前这个点不在状态集合中，运行二进制运算 
			{
				for(int pre = 1;pre <= n;pre++) //枚举之前的那个点 
				{
					if((i>>(pre - 1)) &1 )
					{
						dp[i | (1<<(now-1))][now]=min(dp[i|(1<<(now-1))][now],dp[i][pre]+a[pre][now]);
					}      //dp[i | (1<<(now-1))][now]走过新加入一个点的集合	
				}		//dp[i][pre]+a[pre][now]和之前加入那个点的集合			
			}		//a[pre][now]从上一个点走到现在这个点的路径花费 
		}		
	}
	
	printf("%d\n",dp[(1<<n)-1][n]);
	return 0;
}
