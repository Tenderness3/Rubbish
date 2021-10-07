#include<cstring>
#include <iostream>
#include <string>
#define N 100
using namespace std;
void encryption(char *str, int offset);
int main()
{
    char str[N];    //加密字符串 
    int offset;     //偏移量
    cout<<"请输入你要加密的内容："<<endl;
    cin>> str;
    cout<<"请输入偏移量"<<endl;
    cin>> offset;
    encryption(str,offset);
    return 0;
}

void encryption(char *str,int offset){
     for (int i = 0; i < strlen(str); i++)
     {
         if(str[i]>='A' && str[i] <= 'Z')//判断输入字母的大小写
         {
           str[i] = ((str[i] -'A') + offset) %26+'A';
         }
         else if (str[i]>='a' && str[i] <='z')
         {
              str[i]=((str[i] - 'a')+offset)%26+'a';
         }
     }
     cout<<"加密结果为："<<str<<endl;
} 

