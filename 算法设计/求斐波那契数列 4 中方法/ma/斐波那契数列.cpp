//쳲���������   0,1,1,2,3,5,8,13..........
//F(1)=0; F(1)=1; F(n)=F(n-1)+F(n-2)
# include <iostream>
using namespace std;
// �ݹ� 
int i(int n){
	if( n == 1){
		return 0;
	}
	else if(n == 2 || n == 3){
		return 1;
	}
	else{
		return i(n - 1) + i(n - 2);
	}
}
int main(){
	int n = 0;
	int ret =0;
	cout<<"������n :"<<endl; 
	cin>>n;
	ret = i(n);
	printf("�� %d ��쳲���������Ϊ %d", (n,ret));
	return 0;
}



public int i3(int n){
	List<int> list = new List<int>();
	list.
}

