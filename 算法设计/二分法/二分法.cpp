#include <iostream>

using namespace std;


int SearchK(int *Arr,int k)//�����������з���t�����p�����е���㣬q���յ�
{
	int low=1;
	int high=7;
	int mid;
	while (low<=high)//�ȶ��棬���������в�����k�����
	{
		mid = (low + high) / 2;

		if (Arr[mid] ==k)
		{
			return Arr[mid];
		}
		else 
		{
			if (Arr[mid] < k)//�ұ߲���
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
