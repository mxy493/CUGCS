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
����ͼ�Ĵ洢����������ڽӱ�洢
*/
//�ߵĶ���
struct Edge
{
	int dest=-1;
	int cost = 0;
	Edge* link = nullptr;
	Edge() = default;
    Edge(int tdest, int tcost) :dest(tdest), cost(tcost){}

};

//���㶨��
struct Vertex
{
	string name;//��������
	Edge* ptr = nullptr;//ָ��߱��ָ��
	Vertex() = default;
    Vertex(string mname) :name(mname) {}
};

//ͼ�Ķ���
class MyGraph
{
public:
	MyGraph();
	~MyGraph();
	//��ö�����е�i���������ƣ�i��0��
	string getNameOfIndex(int i);
	//��ö���v1��v2�ıߵ�Ȩֵ���������-1��ʾû���ҵ���һ����
	int getWeight(int v1, int v2);
	////�������Ϊname�Ķ����ڶ�����е���������0��
	//int getIndexOfName(string name);

	//����һ����Ϊname�Ķ���
	void insertVertex(string name);
	//����һ����v1��v2�ıߣ�ȨֵΪcost
	bool insertEdge(int v1, int v2, int cost);
	//���ĳһ���ڵ�ĵ�һ���ڽӵ�,û���򷵻�-1
	int getFirstNeighbor(int v);
	//���ĳһ���ڵ����һ���ڽӵ㣬v�Ǹýڵ㣬nv��v��һ���ڽӵ㣬û���򷵻�-1
	int getNextNeighbor(int v, int nv);
	//���ļ��н���һ��ͼ���ļ���Ĭ���ǣ�graphdata.txt,��ʽ���£�
	//��һ���Ǹ�����������ƣ�֮������һ����������ֵΪ1000��������֮�䲻��ͨ
	bool initiFromFile();
    //���ĳһ���ڵ�������ڽӽڵ㣬��vector����
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
	vector<Vertex> NodeTable;//�����
	//��ȡĳ��һ��������Ӧ�Ķ����ڶ�����е���������0�ƣ�-1��ʾû���ҵ�

};

