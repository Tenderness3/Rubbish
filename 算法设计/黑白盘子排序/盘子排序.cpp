#include<iostream>
using namespace std;
int main(){
    int n;
    int num=0;
    cout<<"请输入共有几对盘子:"<<endl;
    cin>>n;
    int *a = new int [2*n]; 
    //初始化盘子 
    for(int i=0;i<2*n;i++){
            if(i%2==0) a[i]=1;
            else a[i]=0;    
    }
    cout<<"盘子初始排序状态:"<<endl; 
    for(int i=0;i<2*n;i++){
            if(a[i]==1)
                       cout<<"黑 ";  
            else   cout<<"白 "; 
    }
    cout<<endl; 
    //冒泡排序 
     for(int i=0;i<n;i++){
             for(int j=i;j<2*n-i;j++){
                     if(a[j]==1&&a[j+1]==0){
                           a[j]=0;
                           a[j+1]=1;
                           num++;
                     }    
             }
     }
      cout<<"共交换："<<num<<"次  盘子交换后排序状态:"<<endl;
    for(int i=0;i<2*n;i++){
            if(a[i]==1)
                       cout<<"黑 ";  
            else   cout<<"白 "; 
    }
    cout<<endl;
    system("pause");
    return 0;
    
}
