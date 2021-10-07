#include<stdio.h>
//using namespace std;
int main(){
	int dis = 500, oil = 500;
    int k = 1;
    //因为不确定循环次数，又至少做一次，所以我们用do_while
    do
    {
        printf("储油点%d：距离出发点%5d,",k,1000-dis);
        printf("储油量%5dL\n",oil);
        k = k+1;
        dis = dis +500/(2*k-1);
        oil = 500*k;
    }while(dis<1000);
    
    // 再计算出发点的储油量
    oil = 500*(k-1)+(1000-dis)*(2*k-1);
   
    
    printf("储油点%d：距离出发点%5d,储油量%5dL\n，距离终点 %5d  ",k,0,oil,1000-dis);
    return 0;
} 
