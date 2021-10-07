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
	for(j=0;j<shanchu;j++){
		data[j]=j;
	}
	for(i=0;i<changdu;i++){
		if(shuzu[data[i]]>shuzu[data[i+1]]){
			data[i]=data[i+1];
			changdu-=1; 
		}
		
	}
	for(int k=0;k<changdu;k++){
		cout<<shuzu[data[k]]<<"  ";
	}
	return 0;
}
