#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
/*
用于图的存储，这里采用邻接表存储
*/
//边的定义
struct Edge
{
	int dest=-1;
	int cost = 0;
	Edge* link = nullptr;
	Edge() = default;
    Edge(int tdest, int tcost) :dest(tdest), cost(tcost){}

};

//定点定义
struct Vertex
{
	string name;//定点名称
	Edge* ptr = nullptr;//指向边表的指针
	Vertex() = default;
    Vertex(string mname) :name(mname) {}
};

//图的定义
class MyGraph
{
public:
	MyGraph();
	~MyGraph();
	//获得顶点表中第i个顶点名称，i从0计
	string getNameOfIndex(int i);
	//获得定点v1到v2的边的权值，如果返回-1表示没有找到这一条边
	int getWeight(int v1, int v2);
	////获得名字为name的顶点在顶点表中的索引，从0计
	//int getIndexOfName(string name);

	//插入一个名为name的顶点
	void insertVertex(string name);
	//插入一条从v1到v2的边，权值为cost
	bool insertEdge(int v1, int v2, int cost);
	//获得某一个节点的第一个邻接点,没有则返回-1
	int getFirstNeighbor(int v);
	//获得某一个节点的下一个邻接点，v是该节点，nv是v的一个邻接点，没有则返回-1
	int getNextNeighbor(int v, int nv);
	//从文件中建立一个图，文件名默认是：graphdata.txt,格式如下：
	//第一行是各个顶点的名称，之后则是一个矩阵，若数值为1000则是两点之间不连通
	bool initiFromFile();
    //获得某一个节点的所有邻接节点，以vector返回
    vector<int> getAllNeighbor(int v);
    int getPos(string verName)
    {
        for (int  i = 0; i < NodeTable.size(); i++)
        {
            if (NodeTable[i].name==verName)
            {
                return i;
            }
        }
        return -1;
    }

private:
	vector<Vertex> NodeTable;//定点表
	//获取某个一名字所对应的定点在顶点表中的索引，从0计，-1表示没有找到

};

