#include <bits/stdc++.h>
using namespace std;
const int max_ = 0x3f3f3f;
const int NoEdge = -1;
int citynum; //城市数 
int edgenum;//边数 
int currentcost;//当前路程 
int bestcost;//最优路程 
int Graph[100][100];//边距记录 
int x[100];//记录行走顺序 
int bestx[100];//记录最优行走顺序 

//初始化 
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
void BackTrack(int i) //i代表第i步去的城市而不是代号为i的城市
{
    if(i == citynum)//t到达第n层即搜索到叶子结点
    {
    	
        if(Graph[x[i - 1]][x[i]] != NoEdge && Graph[x[i]][x[1]] != NoEdge && (currentcost + Graph[x[i - 1]][x[i]] + Graph[x[i]][x[1]] < bestcost || bestcost == max_))
        {
        	//到最后一个城市与出发城市之间有路径且当前总距离比最优值小 
            bestcost = currentcost + Graph[x[i - 1]][x[i]] + Graph[x[i]][x[1]];//记录最优解 
            for(int j = 1; j <= citynum; ++j)//记录最优值 
                bestx[j] = x[j];
        }
    }
    else   //没有到达叶子节点 
    {
        for(int j = i; j <= citynum; ++j)
        {
        	//城市x[i-1]能达到城市x[j]即这两个城市间有边，并当前所走的路程cc加上这两个城市的距离没有比当前最优值bestc大) 
            if(Graph[x[i - 1]][x[j]] != NoEdge && (currentcost + Graph[x[i - 1]][x[j]] < bestcost || bestcost == max_))
            {
                Swap(x[i], x[j]); //保存要去的第i个城市到x[i]中 
                currentcost += Graph[x[i - 1]][x[i]];//修改此时所走的路程cc
                BackTrack(i + 1);//搜索下一城市 
                currentcost -= Graph[x[i - 1]][x[i]];//恢复原来cc的值
                Swap(x[i], x[j]);
            }
        }
   }
}

int main()
{
	int p1, p2, len;
    cout<<"输入城市数和边数："<<endl;
    cin>>citynum>>edgenum;
    memset(Graph, NoEdge, sizeof(Graph));
    
    cout<<"输入两座城市之间的距离（p1 p2 l):"<<endl;
    for(int i = 1; i <= edgenum; ++i)
    {
    	cin>>p1>>p2>>len;
        Graph[p1][p2] = Graph[p2][p1] = len;
    }
    
    Initilize();//初始化 
    
    BackTrack(2);  //回溯函数 
	  
    cout<<"最短路线为："<<bestcost<<endl; 
    cout << "路线为:" << endl;
    for(int i = 1; i <= citynum; ++i)
        cout << bestx[i] << " ";
    cout << "1" << endl;
}

