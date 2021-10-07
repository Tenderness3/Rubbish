#include <bits/stdc++.h>
using namespace std;
const int max_ = 0x3f3f3f;
const int NoEdge = -1;
int citynum; //������ 
int edgenum;//���� 
int currentcost;//��ǰ·�� 
int bestcost;//����·�� 
int Graph[100][100];//�߾��¼ 
int x[100];//��¼����˳�� 
int bestx[100];//��¼��������˳�� 

//��ʼ�� 
void Initilize()
{
    currentcost = 0;
    bestcost = max_;
    for(int i = 1; i <= citynum; ++i)
    {
        x[i] = i;
    }
}
void Swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void BackTrack(int i) //i�����i��ȥ�ĳ��ж����Ǵ���Ϊi�ĳ���
{
    if(i == citynum)//t�����n�㼴������Ҷ�ӽ��
    {
    	
        if(Graph[x[i - 1]][x[i]] != NoEdge && Graph[x[i]][x[1]] != NoEdge && (currentcost + Graph[x[i - 1]][x[i]] + Graph[x[i]][x[1]] < bestcost || bestcost == max_))
        {
        	//�����һ���������������֮����·���ҵ�ǰ�ܾ��������ֵС 
            bestcost = currentcost + Graph[x[i - 1]][x[i]] + Graph[x[i]][x[1]];//��¼���Ž� 
            for(int j = 1; j <= citynum; ++j)//��¼����ֵ 
                bestx[j] = x[j];
        }
    }
    else   //û�е���Ҷ�ӽڵ� 
    {
        for(int j = i; j <= citynum; ++j)
        {
        	//����x[i-1]�ܴﵽ����x[j]�����������м��бߣ�����ǰ���ߵ�·��cc�������������еľ���û�бȵ�ǰ����ֵbestc��) 
            if(Graph[x[i - 1]][x[j]] != NoEdge && (currentcost + Graph[x[i - 1]][x[j]] < bestcost || bestcost == max_))
            {
                Swap(x[i], x[j]); //����Ҫȥ�ĵ�i�����е�x[i]�� 
                currentcost += Graph[x[i - 1]][x[i]];//�޸Ĵ�ʱ���ߵ�·��cc
                BackTrack(i + 1);//������һ���� 
                currentcost -= Graph[x[i - 1]][x[i]];//�ָ�ԭ��cc��ֵ
                Swap(x[i], x[j]);
            }
        }
   }
}

int main()
{
	int p1, p2, len;
    cout<<"����������ͱ�����"<<endl;
    cin>>citynum>>edgenum;
    memset(Graph, NoEdge, sizeof(Graph));
    
    cout<<"������������֮��ľ��루p1 p2 l):"<<endl;
    for(int i = 1; i <= edgenum; ++i)
    {
    	cin>>p1>>p2>>len;
        Graph[p1][p2] = Graph[p2][p1] = len;
    }
    
    Initilize();//��ʼ�� 
    
    BackTrack(2);  //���ݺ��� 
	  
    cout<<"���·��Ϊ��"<<bestcost<<endl; 
    cout << "·��Ϊ:" << endl;
    for(int i = 1; i <= citynum; ++i)
        cout << bestx[i] << " ";
    cout << "1" << endl;
}

