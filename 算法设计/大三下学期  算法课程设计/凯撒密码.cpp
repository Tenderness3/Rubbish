#include<cstring>
#include <iostream>
#include <string>
#define N 100
using namespace std;
void encryption(char *str, int offset);
int main()
{
    char str[N];    //�����ַ��� 
    int offset;     //ƫ����
    cout<<"��������Ҫ���ܵ����ݣ�"<<endl;
    cin>> str;
    cout<<"������ƫ����"<<endl;
    cin>> offset;
    encryption(str,offset);
    return 0;
}

void encryption(char *str,int offset){
     for (int i = 0; i < strlen(str); i++)
     {
         if(str[i]>='A' && str[i] <= 'Z')//�ж�������ĸ�Ĵ�Сд
         {
           str[i] = ((str[i] -'A') + offset) %26+'A';
         }
         else if (str[i]>='a' && str[i] <='z')
         {
              str[i]=((str[i] - 'a')+offset)%26+'a';
         }
     }
     cout<<"���ܽ��Ϊ��"<<str<<endl;
} 

