#include<iostream>
using namespace std;
int main(){
    int n;
    int num=0;
    cout<<"�����빲�м�������:"<<endl;
    cin>>n;
    int *a = new int [2*n]; 
    //��ʼ������ 
    for(int i=0;i<2*n;i++){
            if(i%2==0) a[i]=1;
            else a[i]=0;    
    }
    cout<<"���ӳ�ʼ����״̬:"<<endl; 
    for(int i=0;i<2*n;i++){
            if(a[i]==1)
                       cout<<"�� ";  
            else   cout<<"�� "; 
    }
    cout<<endl; 
    //ð������ 
     for(int i=0;i<n;i++){
             for(int j=i;j<2*n-i;j++){
                     if(a[j]==1&&a[j+1]==0){
                           a[j]=0;
                           a[j+1]=1;
                           num++;
                     }    
             }
     }
      cout<<"��������"<<num<<"��  ���ӽ���������״̬:"<<endl;
    for(int i=0;i<2*n;i++){
            if(a[i]==1)
                       cout<<"�� ";  
            else   cout<<"�� "; 
    }
    cout<<endl;
    system("pause");
    return 0;
    
}
