#include<iostream>
#include<algorithm>
using namespace std;
int m,n ;        //mΪ������������n����Ʒ������ 
int dp[31][201]; //״̬ת�Ʒ��� ,��ά������ 
int w[31];       //��Ʒ��Ӧ������ 
int c[31];       //��Ʒ�ļ�ֵ 
int main(){
	cout<<"�����뱳������������Ʒ��������"<<endl; 
	cin>>m>>n;
	cout<<"��������Ʒ�����������Ӧ�ļ�ֵ��"<<endl;
	for(int i = 1; i <= n; i++)
	cin>>w[i]>>c[i];
	for(int i = 1; i<=n;i++){    //���н������ 
		for(int j=1;j<=m;j++)
        {		
            if(j>=w[i])          
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);//dp[i-1][j]û��ѡ��ǰ��Ʒ����� 
                else
                dp[i][j]=dp[i-1][j];     //��һ�е�ֱ��������     
        }
    }
        cout<<"����ֵΪ��"<<dp[n][m];
        return 0;
}
