#include<cstdio>
#include<Windows.h>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include <math.h>
#include<iostream>
using namespace std;
 
const int maxn = 100000000;   

int a[maxn];           //a[]Ϊ�������������
int b[maxn], t[maxn];  //b[]�����������,t[]���ڹ鲢����,��ʱ����a[]
int n;                       //����������ĸ��� 
// �������±�� p��r֮�������������
//ʹ��ǰ�����ȫ�������ڻ�׼Ԫ, ���������С�ڻ�׼Ԫ

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
	return j; //���ػ�׼Ԫ�ź�����λ�� 
}
 
int randomizedPartition(int p, int r) //�Ի�׼Ԫ���д��� 
{
	int i = rand() % (r-p+1) + p; //����p �� q ֮�������� i 
 
	int temp = a[i];    //�������λ�õ���ʼλ��,ʹ���Ϊ��׼Ԫ 
	a[i] = a[p];
	a[p] = temp;
 
	return partition(p, r);
}
 
 
 //�������� 
void randomizedQuickSort(int p, int r) 
{
	if(p < r)
	{
		int q = randomizedPartition(p, r); // �ָ� 
		randomizedQuickSort(p, q-1);      // �����߷ֱ����� 
		randomizedQuickSort(q+1, r);
	}
	
}
 
 
 //�鲢���� 
void merge_sort(int *a, int x, int y, int *t) 
{
	if(y-x > 1)
	{
		int m = (y-x)/2 + x;       //ȡ�м� 
		int p = x, q = m, i = x;
 
		merge_sort(b, p, m, t);   //���߷ֱ����� 
		merge_sort(b, m, y, t);
 
		while(p < m && q < y)
		{
			if(b[p] <= b[q]) t[i++] = b[p++];
			else t[i++] = b[q++];
		}
 
		while(p < m) t[i++] = b[p++];
		while(q < y) t[i++] = b[q++];
 
		for(i = x; i < y; i++) //������õĲ������´������� a[]
			b[i] = t[i];
	}
}
 
int main()
{
    printf("������Ҫ����Ƚϵĸ��� n ( n <= 100000000 ): ");
    while(scanf("%d", &n) != EOF)
    {
        LARGE_INTEGER begin, end;
        long long  MergeSortCost, QuickSortCost; //������ 
        memset(a, 0, sizeof(a));       //��ʼ�� 
        for(int i = 0; i < n; i++)    //��������� 
        {
             a[i]= rand();
            b[i] = a[i];
            printf("%d\n",a[i]);
        }
 
        QueryPerformanceCounter(&begin); // ��ʱ��
        randomizedQuickSort(0, n-1);
        QueryPerformanceCounter(&end); 
        QuickSortCost = end.QuadPart - begin.QuadPart; 
 
 
        QueryPerformanceCounter(&begin); 
        merge_sort(b, 0, n, t); //�鲢���� 
        QueryPerformanceCounter(&end); 
        MergeSortCost = end.QuadPart - begin.QuadPart; 
		
		
 
        printf("���������ʱ��%lld ns,�鲢�����ʱ��%lldns\n\n\n", QuickSortCost*100, MergeSortCost*100);
 		printf("%lld ns-%lld ns=%lld ns\n",QuickSortCost*100, MergeSortCost*100,100*(QuickSortCost-MergeSortCost));
 		
        printf("���Ҫ�����Ƚ����������Ƚϵĸ��� n : ");
 
    }
    return 0;
}

