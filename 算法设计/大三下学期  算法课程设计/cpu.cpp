#include<stdio.h>
#include<string.h> 
#include<iostream>
using namespace std;
struct work{
	int priority;    //优先级
	int time;    //工作时间
	char name[10]; //工作名称 
}; 
int cpu(work works){
	for(int i=0;i<works.time;i++){
		cout<<"作业名称:"<<works.name<<"    时间片:"<<i<<"    优先级:"<<works.priority-20<<endl;
	}
} 
int main(){

	int priority=1,time=15,number;
	char name[10];
	//String name;
	cout<<"创建工作数量："<<endl;
	cin>>number; 
	work works[number];
	cout<<"请输入工作优先级、时间片长度、工作名称(要求-20（最高优先级）~19（最低优先级)"<<endl;
	cout<<"时间片长度是1~100之间的整数"<<endl; 
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
