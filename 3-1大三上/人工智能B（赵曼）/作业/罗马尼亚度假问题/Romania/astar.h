#ifndef ASTAR_H
#define ASTAR_H
#include "mygraph.h"

struct searchNOde
{
    int ID;
    int gn;//实际代价
    int fn;//评估函数，fn=gn+hn,hn来源于直线距离容器
    //* father = nullptr;//指向父节点的指针
    searchNOde() = default;
    searchNOde(int mID,int mgn,int mfn):ID(mID),gn(mgn),fn(mfn){}
    bool operator<(const searchNOde& node)
    {
        return fn < node.fn;
    }
    bool operator==(int id)
    {
        //该重载用于判断已经拓展的节点中是否有相等的
        return ID == id;
    }
};

struct pathNode
{
    //定义搜索时的路径，将所搜索的路劲存起来，用于QT作图
    int start;
    int end;
    pathNode(int s,int e):start(s),end(e){}
};

class AStar
{
public:
    AStar();
    ~AStar()=default;
    //算法求解
    void useAStar();
    //返回求解过程
    vector<pathNode> getPathNodeVec()
    {
        return pathNOdeVec;
    }
    //获得路径
    vector<int> getPath();
    //求解用图
    MyGraph romaniaGraph;
    //获得探索节点数
    int getNumOfNode(){return numOfNode;}
    //获得最终路径长度
    int getFinalCost();
private:

    //用于存储直线距离的容器
    vector<int> straightLineVec;
    //拓展节点
    vector<searchNOde> expandedNodeVec;
    bool closeList[20];
    int parent[20];
    //算法搜索路径
    vector<pathNode> pathNOdeVec;
    //初始化函数，用于判断是否初始化正常
    bool initial();
    //探索节点数
    int numOfNode=0;
    //总路径长度
    int totalCost=0;

};



#endif // ASTAR_H
