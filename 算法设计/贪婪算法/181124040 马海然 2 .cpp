#include <iostream>
using namespace std;
int main(){
	int shuzu[6]={2,3,4,5,6,7};
	int shanchu,i,j,c,data[100],changdu,m;
	cout<<"数组为{";
	for(int q=0;q<=5;q++){
		cout<<shuzu[q]<<",";
	}
	cout<<"}"<<endl;
	cout<<"输入可以删除数的最大数量"<<endl; 
	cin>>shanchu;	
	if(shanchu>changdu){
		cout<<"错误";
	}
	for(i=0;i<shanchu;i=i+1){
		if(shuzu[i]>shuzu[i+1]){
			data[i]=0;
		}
		else data[i]=1;
		
	}
	for(j=0;j<changdu;j++){
		if(data[j]==1){
			cout<<shuzu[j]<<"  ";
		}
	}
return 0;		
	
} 
