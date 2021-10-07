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
int a[maxn];           //a[]Ϊ�������������
int b[maxn], t[maxn];  //b[]�����������,t[]���ڹ鲢����,��ʱ����a[]
                    

//�������� 
void quickSort(int *arr,int begin,int end)
{
	
	if(begin < end)//������䲻ֻһ����
	{
		int temp = arr[begin]; 
		int i = begin;
		int j = end; 
		
		while(i < j)//���ظ�����
		{
			while(i<j && arr[j] > temp)
				j--;			
			arr[i] = arr[j];			
			while(i<j && arr[i] <= temp)
				i++;			
			arr[j] = arr[i];
		}		
		arr[i] = temp;		
		quickSort(arr,begin,i-1);//�Ի�׼Ԫ�ص����������������ƵĿ�������		
		quickSort(arr,i+1,end);//�Ի�׼Ԫ�ص��ұ�������������ƵĿ�������
	}
	//�������ֻ��һ�������򷵻�
	else
		return;
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
    printf("�������n������ ");
    while(scanf("%d", &n) != EOF)
    {
        LARGE_INTEGER begin, end;
        long long  MergeSortCost, QuickSortCost; 
        memset(a, 0, sizeof(a));      
        for(int i = 0; i < n; i++)    //��������� 
        {
             a[i]= rand();
            b[i] = a[i];
            printf("%d\n",a[i]);
        }
 
        QueryPerformanceCounter(&begin); //����鲢����ʱ�� 
        merge_sort(b, 0, n, t);  
        QueryPerformanceCounter(&end); 
        MergeSortCost = end.QuadPart - begin.QuadPart; 
          
        QueryPerformanceCounter(&begin); // �������ʱ�� 
        quickSort(a,0, n-1);
        QueryPerformanceCounter(&end); 
        QuickSortCost = end.QuadPart - begin.QuadPart; 
        printf("���������ʱ��%lld ns,�鲢�����ʱ��%lldns\n\n\n", QuickSortCost*100, MergeSortCost*100);       
 
    }
    return 0;
}

