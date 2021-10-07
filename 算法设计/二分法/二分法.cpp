#include <iostream>

using namespace std;


int SearchK(int *Arr,int k)//在有序数列中返回t的序号p是数列的起点，q是终点
{
	int low=1;
	int high=7;
	int mid;
	while (low<=high)//稳定版，考虑数组中不存在k的情况
	{
		mid = (low + high) / 2;

		if (Arr[mid] ==k)
		{
			return Arr[mid];
		}
		else 
		{
			if (Arr[mid] < k)//右边查找
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
	}
}

int main()
{
	int p[] = { 1, 2, 3, 4, 5, 6, 7 };
	cout<<SearchK(p, 4)<<endl;
	return 0;
}
