#include<iostream>
#include <string.h>
#define N 100
using namespace std;

//���ܺ���
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
    cout<<"���ܺ�Ϊ��"<<Str<<endl;
}

//���ܺ���
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
    cout<<"������ɣ�"<<Str<<endl;
}

int main()
{
    char str[N];
    int num;
    int S; 
    cout<<"��ѡ����ܻ���ܣ�"<<endl;
	cout<<"1.����" <<endl;
    cout<<"2.����" <<endl;
    cin>>S;
	if(S==1){
		cout<<"����Ҫ���ܵ��ַ���:";
            cin>>str;
            cout<<"����������㷨��ƫ��������";
            cin>>num;
            Encrypt(str,num);
            cout<<endl;
	} 
	else if(S==2){
		cout<<"����Ҫ���ܵ��ַ���:";
        cin>>str;
        cout<<"����ԭ�����㷨��ƫ��������";
        cin>>num;
        Decrypt(str,num);
        cout<<endl;
	}
	else{
		cout<<"�������"<<endl; 
	}
	return 0;
}
