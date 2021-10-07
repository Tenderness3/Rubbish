#include<cstdio>
#include<Windows.h>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include <math.h>
#include<iostream>
using namespace std;
const int maxn = 1000000;   

int n;   
int a[maxn];           //a[]为随机产生的数组
int b[maxn], t[maxn];  //b[]复制随机数组,t[]用于归并排序,暂时保存a[]
                    

//快速排序 
void quickSort(int *arr,int begin,int end)
{
	
	if(begin < end)//如果区间不只一个数
	{
		int temp = arr[begin]; 
		int i = begin;
		int j = end; 
		
		while(i < j)//不重复遍历
		{
			while(i<j && arr[j] > temp)
				j--;			
			arr[i] = arr[j];			
			while(i<j && arr[i] <= temp)
				i++;			
			arr[j] = arr[i];
		}		
		arr[i] = temp;		
		quickSort(arr,begin,i-1);//对基准元素的左边子区间进行相似的快速排序		
		quickSort(arr,i+1,end);//对基准元素的右边子区间进行相似的快速排序
	}
	//如果区间只有一个数，则返回
	else
		return;
}
 
 
 //归并排序 
void merge_sort(int *a, int x, int y, int *t) 
{
	if(y-x > 1)
	{
		int m = (y-x)/2 + x;       //取中间 
		int p = x, q = m, i = x;
 
		merge_sort(b, p, m, t);   //两边分别排序 
		merge_sort(b, m, y, t);
 
		while(p < m && q < y)
		{
			if(b[p] <= b[q]) t[i++] = b[p++];
			else t[i++] = b[q++];
		}
 
		while(p < m) t[i++] = b[p++];
		while(q < y) t[i++] = b[q++];
 
		for(i = x; i < y; i++) //将排序好的部分重新存入数组 a[]
			b[i] = t[i];
	}
}
 
int main()
{
    printf("随机产生n个数： ");
    while(scanf("%d", &n) != EOF)
    {
        LARGE_INTEGER begin, end;
        long long  MergeSortCost, QuickSortCost; 
        memset(a, 0, sizeof(a));      
        for(int i = 0; i < n; i++)    //生成随机数 
        {
             a[i]= rand();
            b[i] = a[i];
            printf("%d\n",a[i]);
        }
 
        QueryPerformanceCounter(&begin); //计算归并排序时间 
        merge_sort(b, 0, n, t);  
        QueryPerformanceCounter(&end); 
        MergeSortCost = end.QuadPart - begin.QuadPart; 
          
        QueryPerformanceCounter(&begin); // 计算快排时间 
        quickSort(a,0, n-1);
        QueryPerformanceCounter(&end); 
        QuickSortCost = end.QuadPart - begin.QuadPart; 
        printf("快速排序耗时：%lld ns,归并排序耗时：%lldns\n\n\n", QuickSortCost*100, MergeSortCost*100);       
 
    }
    return 0;
}

