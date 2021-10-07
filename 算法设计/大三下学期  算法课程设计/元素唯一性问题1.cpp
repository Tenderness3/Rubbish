#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"请输入数组长度："<<endl; 
	cin>>n;
	char *array = new char;
	for(int i=0;i<n;i++){
		cout<<"请输入数组为"<<i<<"的数："; 
		cin>>array[i];
	}
//	for(int i=0;i<n;i++)
//	cout<<array[i];
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(array[i] == array[j]){
				cout<<"该序列有重复"<<endl; 
				return 0;
			}
		}
	}
	cout<<"该序列没重复"<<endl; 
	return 0;
}

//时间复杂度为0(n2) 
