#include<iostream>
using namespace std;
void quickSort(int array[],int X,int Y) //X,Y分别是数组的起始下标
{
    int z,y,i,k;
    if(X<Y)
    {
        z=X;//起始 
        y=Y;//结尾 
        k=array[z];  //起始 
        do{
            while((z<y)&&(array[y]>=k))
             y--;
            if(z<y)               //右边的元素小于k，移到k的左边。
            {
                array[z]=array[y];
                z++;
            }
            while((z<y)&&array[z]<=k)
                z++;
            if(z<y)  //左边的值小于k，移到看k的右边
            {
                array[y]=array[z];
            }

        }while(z!=y);
          array[z]=k;//复制key值到array[z] 
        quickSort(array,X,z-1);//对z的左侧进行排序
            quickSort(array,z+1,Y);//对z的右侧进行排序
    }
}
int main()
{
	int a[5];
	cout<<"请输入5个数："; 
	for(int i=0;i<5;i++){
		cin>>a[i];
	}
    quickSort(a,0,4); 
    cout<<"排好序的数为："; 
    for (int k = 0; k<5; k++){
    	cout<<a[k]<<" ";
	}
    
    for(int i=1;i<5;i++){
		if(a[i-1] == a[i]){
			cout<<"该序列有重复"; 
			return 0;
   		}  		 		  
   }
   	cout<<"该序列无重复";
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
   cout<<"输出数组元素"<<a[i]<<endl;
  system("pause");
     return 0;
 }
 */


