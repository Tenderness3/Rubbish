#include<cstdio>
#include<Windows.h>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include <math.h>
#include<iostream>
using namespace std;
 
const int maxn = 100000000;   

int a[maxn];           //a[]为随机产生的数组
int b[maxn], t[maxn];  //b[]复制随机数组,t[]用于归并排序,暂时保存a[]
int n;                       //产生随机数的个数 
// 对数组下标从 p到r之间的数进行排序
//使得前面的数全都不大于基准元, 后面的数不小于基准元

int partition(int p, int r)
{
	int i = p;
	int j = r+1;
	int x = a[p];
 
	while(true)
	{
		while(a[++i] < x && i < r);
		while(a[--j] > x);
 
		if(i >= j) break;
 

		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
 
	a[p] = a[j];
	a[j] = x;
	return j; //返回基准元排好序后的位置 
}
 
int randomizedPartition(int p, int r) //对基准元进行处理 
{
	int i = rand() % (r-p+1) + p; //产生p 到 q 之间的随机数 i 
 
	int temp = a[i];    //交换随机位置到开始位置,使其成为基准元 
	a[i] = a[p];
	a[p] = temp;
 
	return partition(p, r);
}
 
 
 //快速排序 
void randomizedQuickSort(int p, int r) 
{
	if(p < r)
	{
		int q = randomizedPartition(p, r); // 分割 
		randomizedQuickSort(p, q-1);      // 从两边分别排序 
		randomizedQuickSort(q+1, r);
	}
	
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
    printf("请输入要排序比较的个数 n ( n <= 100000000 ): ");
    while(scanf("%d", &n) != EOF)
    {
        LARGE_INTEGER begin, end;
        long long  MergeSortCost, QuickSortCost; //长整型 
        memset(a, 0, sizeof(a));       //初始化 
        for(int i = 0; i < n; i++)    //生成随机数 
        {
             a[i]= rand();
            b[i] = a[i];
            printf("%d\n",a[i]);
        }
 
        QueryPerformanceCounter(&begin); // 计时器
        randomizedQuickSort(0, n-1);
        QueryPerformanceCounter(&end); 
        QuickSortCost = end.QuadPart - begin.QuadPart; 
 
 
        QueryPerformanceCounter(&begin); 
        merge_sort(b, 0, n, t); //归并排序 
        QueryPerformanceCounter(&end); 
        MergeSortCost = end.QuadPart - begin.QuadPart; 
		
		
 
        printf("快速排序耗时：%lld ns,归并排序耗时：%lldns\n\n\n", QuickSortCost*100, MergeSortCost*100);
 		printf("%lld ns-%lld ns=%lld ns\n",QuickSortCost*100, MergeSortCost*100,100*(QuickSortCost-MergeSortCost));
 		
        printf("如果要继续比较请继续输入比较的个数 n : ");
 
    }
    return 0;
}

