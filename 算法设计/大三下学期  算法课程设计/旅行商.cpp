#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int a[21][21];         
int dp[1<<21][21];     

int main()
{
	printf("����;�����и�����");
	int n;
	scanf("%d",&n);	
	for(int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	//�߼� ���� >> �����һλ��� 11111-->1111 
   	//�߼� ���� << �����һλ��1  11111-->111110 
    //	�����㣬ֻ��1 1���ܵ�1 ������Ϊ0
    //	| ������� ֻҪ����1�͵õ�1 
    //	x&1==1 ����   x&1==0 ż�� 
	
	 
	memset(dp,0x3f,sizeof(dp));
	dp[1][1]=0;

	//��ǰ����Щ�㣬��һ���㡣��ʼö�� 
	for(int i=0; i<(1<<n);i++)  //�����Ƽ��ϡ�0Ϊû�ߣ�1Ϊ�߹��� 
	{
		for(int now=1;now<=n;now++) //��ǰ���ĸ��� 
		{
			if(!((i>>(now-1)) & 1))  //��֤��ǰ����㲻��״̬�����У����ж��������� 
			{
				for(int pre = 1;pre <= n;pre++) //ö��֮ǰ���Ǹ��� 
				{
					if((i>>(pre - 1)) &1 )
					{
						dp[i | (1<<(now-1))][now]=min(dp[i|(1<<(now-1))][now],dp[i][pre]+a[pre][now]);
					}      //dp[i | (1<<(now-1))][now]�߹��¼���һ����ļ���	
				}		//dp[i][pre]+a[pre][now]��֮ǰ�����Ǹ���ļ���			
			}		//a[pre][now]����һ�����ߵ�����������·������ 
		}		
	}
	
	printf("%d\n",dp[(1<<n)-1][n]);
	return 0;
}
