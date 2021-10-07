# include <iostream>
# include <time.h> 
# include <stdio.h>
# include <dos.h>
using namespace std;
int main(void){
	time_t start, end;
	int i, j;
	double k;
	start = time(NULL);
	for(i = 0; i < 10000; i++)
	for(j = 0; j < 10000; j++)
	k = 0.123 * j + 3.567 + i;
	end = time(NULL);
	printf("the time was: %f\n" , difftime(end,start));
	return 0;
}
