//#include "stdafx.h"
#include "mygraph.h"


MyGraph::MyGraph()
{
}

MyGraph::~MyGraph()
{
}

string MyGraph::getNameOfIndex(int i)
{
	return (i>=0&&i<NodeTable.size())?NodeTable[i].name:"";
}

int MyGraph::getWeight(int v1, int v2)
{
	if (v1 == -1 || v2 == -1)
		return -1;
	if (v1 < NodeTable.size())
	{
		Edge *ptr = NodeTable[v1].ptr;
		while (ptr!=nullptr&&ptr->dest!=v2)
		{
			ptr = ptr->link;
		}
        if (ptr!=nullptr)
		{
			return ptr->cost;
		}
	}
	return -1;
	
	return 0;
}

void MyGraph::insertVertex(string name)
{
	Vertex newver(name);
	NodeTable.push_back(newver);
}

bool MyGraph::insertEdge(int v1, int v2, int cost)
{
    if (v1>-1 && v1<NodeTable.size() && v2>-1 && v2<NodeTable.size())
    {
        Edge* ptr1 = NodeTable[v1].ptr;
        while (ptr1 != nullptr&&ptr1->dest != v2)
        {
            ptr1 = ptr1->link;
        }
        if (ptr1 != nullptr)
        {
            //delete ptr1;
            return false;//֤���Ѿ����ڣ�������
        }
        Edge* newEdge1 = new Edge(v2, cost);
        newEdge1->link = NodeTable[v1].ptr;
        NodeTable[v1].ptr = newEdge1;
        //ptr1 = newEdge1;
        //����һ���ڵ�ı߱��в���
        Edge* newEdge2 = new Edge(v1, cost);
        //��Ϊ������ͼ������ǰ���Ѿ�֤��û�������ߣ����Կ���ֱ�Ӳ���
        newEdge2->link = NodeTable[v2].ptr;
        NodeTable[v2].ptr = newEdge2;
        return true;
    }
    return false;
}

int MyGraph::getFirstNeighbor(int v)
{
	if (v>-1&&v<NodeTable.size())
	{
		if (NodeTable[v].ptr!=nullptr)
		{
			return NodeTable[v].ptr->dest;
		}
	}
	return -1;
}

int MyGraph::getNextNeighbor(int v, int nv)
{
	if (v>-1&&v<NodeTable.size())
	{
		Edge* ptr = NodeTable[v].ptr;
		while (ptr!=nullptr&&ptr->dest!=nv)
		{
			ptr = ptr->link;
		}
		if (ptr!=nullptr&&ptr->link!=nullptr)
		{
			return ptr->link->dest;
		}
	}
	return -1;
}

bool MyGraph::initiFromFile()
{
	fstream datafile("graphdata.txt", fstream::in);
	if (!datafile.is_open())
	{
		return false;
	}
	//�ȶ�������
    //cout << "duchudingdain" << endl;
	string allName;
	getline(datafile, allName);//ʹ��string������ĺ�����������ʹ��IO������ĺ���
	vector<string> nameVec(allName.size());
	istringstream iss(allName), end;
	//����һ�е����ִ���������
    //cout << allName << endl;
	copy(istream_iterator<string>(iss), istream_iterator<string>(end), nameVec.begin());
	//�ڶ�����в��붥��
	int i = 0;
	for (auto s : nameVec)
	{
		if (s=="")
		{
			break;
		}
		i++;
		insertVertex(s);
		//cout << s << " " << i << endl;;
	}
	nameVec.erase(nameVec.begin() + i, nameVec.end());
	//cout << nameVec.size() << endl;
	//���ļ��ĵڶ��п�ʼ�����

	for (int i = 0; i < nameVec.size(); i++)
	{
		for (int j = 0; j < nameVec.size(); j++)
		{
			int cost;
			datafile >> cost;
           // cout << cost << "		" << j << endl;;
			if (i==j)
			{
				continue;
			}
			if (cost==1000)
			{
				continue;
			}
            insertEdge(i, j, cost);
//			if (!insertEdge(i, j, cost))
//			{
//				datafile.close();
//				return false;
//			}
			
		}
		//cout << endl;
	}
	datafile.close();
	return true;
	
}

vector<int> MyGraph::getAllNeighbor(int v)
{
    vector<int> allNeighbor;
    int firstNeghbor = getFirstNeighbor(v);
    if (firstNeghbor==-1)
    {
        return vector<int>();
    }
    allNeighbor.push_back(firstNeghbor);
    int neighbor = firstNeghbor;
    while (true)
    {
        neighbor = getNextNeighbor(v, neighbor);
        if (neighbor==-1)
        {
            return allNeighbor;
        }
        allNeighbor.push_back(neighbor);
    }
}
