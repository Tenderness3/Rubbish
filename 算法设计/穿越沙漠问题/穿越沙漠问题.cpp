#include<stdio.h>
//using namespace std;
int main(){
	int dis = 500, oil = 500;
    int k = 1;
    //��Ϊ��ȷ��ѭ����������������һ�Σ�����������do_while
    do
    {
        printf("���͵�%d�����������%5d,",k,1000-dis);
        printf("������%5dL\n",oil);
        k = k+1;
        dis = dis +500/(2*k-1);
        oil = 500*k;
    }while(dis<1000);
    
    // �ټ��������Ĵ�����
    oil = 500*(k-1)+(1000-dis)*(2*k-1);
   
    
    printf("���͵�%d�����������%5d,������%5dL\n�������յ� %5d  ",k,0,oil,1000-dis);
    return 0;
} 
