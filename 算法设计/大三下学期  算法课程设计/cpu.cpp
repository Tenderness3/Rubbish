#include<stdio.h>
#include<string.h> 
#include<iostream>
using namespace std;
struct work{
	int priority;    //���ȼ�
	int time;    //����ʱ��
	char name[10]; //�������� 
}; 
int cpu(work works){
	for(int i=0;i<works.time;i++){
		cout<<"��ҵ����:"<<works.name<<"    ʱ��Ƭ:"<<i<<"    ���ȼ�:"<<works.priority-20<<endl;
	}
} 
int main(){

	int priority=1,time=15,number;
	char name[10];
	//String name;
	cout<<"��������������"<<endl;
	cin>>number; 
	work works[number];
	cout<<"�����빤�����ȼ���ʱ��Ƭ���ȡ���������(Ҫ��-20��������ȼ���~19��������ȼ�)"<<endl;
	cout<<"ʱ��Ƭ������1~100֮�������"<<endl; 
	for(int i=0;i<number;i++){		
		cin>>priority;
		cin>>time;
		cin>>name;
		works[i].priority=priority+20;
		strcpy(works[i].name,name);
		works[i].time=time;	
	}
	for(int i=0;i<40;i++){   
		for(int j=0;j<number;j++){
			if(works[j].priority==i)
				cpu(works[j]);
		}
	} 
	
	return 0;
}
