#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"���������鳤�ȣ�"<<endl; 
	cin>>n;
	char *array = new char;
	for(int i=0;i<n;i++){
		cout<<"����������Ϊ"<<i<<"������"; 
		cin>>array[i];
	}
//	for(int i=0;i<n;i++)
//	cout<<array[i];
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(array[i] == array[j]){
				cout<<"���������ظ�"<<endl; 
				return 0;
			}
		}
	}
	cout<<"������û�ظ�"<<endl; 
	return 0;
}

//ʱ�临�Ӷ�Ϊ0(n2) 
