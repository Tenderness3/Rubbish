# include <iostream>
using namespace std;
	int n;
	int feibo;
	int num1 = 1;
	int num2 = 1;
	int tmp;
int main(){
	cout<<"请输入 n :"<<endl;
	cin>>n; 
	if(n == 1){
		cout<<"数列是:"<<0<<endl;
	}
	else if(n == 2 || n == 3){
		cout<<"数列是:"<<1<<endl;
	}
	else{
		for(int i = 0; i<n-3; i++){
			tmp = num1 + num2;
			num1 = num2;
			num2 = tmp;
			
		}
		cout<<"数列是:"<<tmp<<endl;
}
}
