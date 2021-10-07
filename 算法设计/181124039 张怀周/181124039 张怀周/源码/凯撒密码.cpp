#include<iostream>
#include <string.h>
#define N 100
using namespace std;

//加密函数
void Encrypt(char *Str,int num)
{
    for(int i=0; i<strlen(Str); i++)
    {
        if(Str[i] >= 'A' && Str[i] <= 'Z')
        {
            Str[i] = ((Str[i]-'A')+num)%26+'A';
        }
        else if(Str[i] >= 'a' && Str[i] <= 'z')
        {
            Str[i] = ((Str[i]-'a')+num)%26+'a';
        }
    }
    cout<<"加密后为："<<Str<<endl;
}

//解密函数
void Decrypt(char *Str,int num)
{
    int x;
    x=26-num;
    for(int i=0; i<strlen(Str); i++)
    {
        if(Str[i] >= 'A' && Str[i] <= 'Z')
        {
            Str[i] = ((Str[i]-'A')+x)%26+'A';
        }
        else if(Str[i] >= 'a' && Str[i] <= 'z')
        {
            Str[i] = ((Str[i]-'a')+x)%26+'a';
        }
    }
    cout<<"解密完成："<<Str<<endl;
}

int main()
{
    char str[N];
    int num;
    int S; 
    cout<<"请选择加密或解密："<<endl;
	cout<<"1.加密" <<endl;
    cout<<"2.解密" <<endl;
    cin>>S;
	if(S==1){
		cout<<"输入要加密的字符串:";
            cin>>str;
            cout<<"输入该密码算法的偏移数量：";
            cin>>num;
            Encrypt(str,num);
            cout<<endl;
	} 
	else if(S==2){
		cout<<"输入要解密的字符串:";
        cin>>str;
        cout<<"输入原密码算法的偏移数量：";
        cin>>num;
        Decrypt(str,num);
        cout<<endl;
	}
	else{
		cout<<"输入错误："<<endl; 
	}
	return 0;
}
