#ifndef ASTAR_H
#define ASTAR_H
#include "mygraph.h"

struct searchNOde
{
    int ID;
    int gn;//ʵ�ʴ���
    int fn;//����������fn=gn+hn,hn��Դ��ֱ�߾�������
    //* father = nullptr;//ָ�򸸽ڵ��ָ��
    searchNOde() = default;
    searchNOde(int mID,int mgn,int mfn):ID(mID),gn(mgn),fn(mfn){}
    bool operator<(const searchNOde& node)
    {
        return fn < node.fn;
    }
    bool operator==(int id)
    {
        //�����������ж��Ѿ���չ�Ľڵ����Ƿ�����ȵ�
        return ID == id;
    }
};

struct pathNode
{
    //��������ʱ��·��������������·��������������QT��ͼ
    int start;
    int end;
    pathNode(int s,int e):start(s),end(e){}
};

class AStar
{
public:
    AStar();
    ~AStar()=default;
    //�㷨���
    void useAStar();
    //����������
    vector<pathNode> getPathNodeVec()
    {
        return pathNOdeVec;
    }
    //���·��
    vector<int> getPath();
    //�����ͼ
    MyGraph romaniaGraph;
    //���̽���ڵ���
    int getNumOfNode(){return numOfNode;}
    //�������·������
    int getFinalCost();
private:

    //���ڴ洢ֱ�߾��������
    vector<int> straightLineVec;
    //��չ�ڵ�
    vector<searchNOde> expandedNodeVec;
    bool closeList[20];
    int parent[20];
    //�㷨����·��
    vector<pathNode> pathNOdeVec;
    //��ʼ�������������ж��Ƿ��ʼ������
    bool initial();
    //̽���ڵ���
    int numOfNode=0;
    //��·������
    int totalCost=0;

};



#endif // ASTAR_H
