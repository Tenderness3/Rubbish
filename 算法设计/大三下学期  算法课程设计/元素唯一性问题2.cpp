#include<iostream>
using namespace std;
void quickSort(int array[],int X,int Y) //X,Y�ֱ����������ʼ�±�
{
    int z,y,i,k;
    if(X<Y)
    {
        z=X;//��ʼ 
        y=Y;//��β 
        k=array[z];  //��ʼ 
        do{
            while((z<y)&&(array[y]>=k))
             y--;
            if(z<y)               //�ұߵ�Ԫ��С��k���Ƶ�k����ߡ�
            {
                array[z]=array[y];
                z++;
            }
            while((z<y)&&array[z]<=k)
                z++;
            if(z<y)  //��ߵ�ֵС��k���Ƶ���k���ұ�
            {
                array[y]=array[z];
            }

        }while(z!=y);
          array[z]=k;//����keyֵ��array[z] 
        quickSort(array,X,z-1);//��z������������
            quickSort(array,z+1,Y);//��z���Ҳ��������
    }
}
int main()
{
	int a[5];
	cout<<"������5������"; 
	for(int i=0;i<5;i++){
		cin>>a[i];
	}
    quickSort(a,0,4); 
    cout<<"�ź������Ϊ��"; 
    for (int k = 0; k<5; k++){
    	cout<<a[k]<<" ";
	}
    
    for(int i=1;i<5;i++){
		if(a[i-1] == a[i]){
			cout<<"���������ظ�"; 
			return 0;
   		}  		 		  
   }
   	cout<<"���������ظ�";
	return 0; 
 }

   

    
    
    
    
    
    /* 
    

 int main()
{
    int a[11], i;
    // char tmp[20];
  for (i = 0; i<11; i++) 
   cin>>a[i];
  quickSort(a, 0, 10); 
  for (i = 0; i<11; i++)
   cout<<"�������Ԫ��"<<a[i]<<endl;
  system("pause");
     return 0;
 }
 */


