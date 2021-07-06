#include "astar.h"

AStar::AStar()
{
    for (int i = 0; i < 20; i++)
    {
        closeList[i] = false;
        parent[i] = -1;
    }
    initial();
}

bool AStar::initial()
{
    fstream datafile("straight-line.txt", ios::in);
    if(!datafile.is_open())
        return false;
    for (int i = 0; i < 20; i++)
    {
        int j;
        datafile >> j;
        straightLineVec.push_back(j);
       // cout<<i<<" "<<j<<endl;
    }
    romaniaGraph.initiFromFile();
    return true;
}


void AStar::useAStar()
{
    //���ȵ�һ���ڵ���
    numOfNode++;
    int firstVer=romaniaGraph.getPos("Arad");
    int hn = straightLineVec[firstVer];
    searchNOde firstNOde(firstVer, 0, hn);
    expandedNodeVec.push_back(firstNOde);
    parent[firstVer] = -1;//��Ϊ-1���ǵ������
    while (!expandedNodeVec.empty())
    {
        //ȡ���׽ڵ�
        searchNOde currNode = expandedNodeVec.front();
        expandedNodeVec.erase(expandedNodeVec.begin());
        //������ڵ�ŵ�close��
        closeList[currNode.ID] = true;
        //�����Ŀ��ڵ㣬����
        if (romaniaGraph.getNameOfIndex(currNode.ID)== "Bucharest")
        {
            return;
        }
        //��ȡ����ڵ�����ڽڵ�
        vector<int> allNeighbor = romaniaGraph.getAllNeighbor(currNode.ID);
        //���������ڽڵ���
        for (auto s : allNeighbor)
        {
            numOfNode++;
            //�ȼ�ס·��
            pathNode path(currNode.ID,s);
            pathNOdeVec.push_back(path);
            //����ýڵ���close�У�����
            if (closeList[s]==true)
            {
                continue;
            }
            //���Ѿ���չ�ڵ��в��ң�����У����Ƿ����
            auto iter=find(expandedNodeVec.begin(), expandedNodeVec.end(), s);
            if (iter!=expandedNodeVec.end())
            {
                cout<<"currNode  is in expandedVec"<<s<<endl;
                cout<<"the old g is "<<iter->gn<<endl;
                //˵���У���鿴�ǲ�����Ҫ���£������ǰ��Gֵ��С�����Ҫ����g��f,���޸�parent
                int cost = romaniaGraph.getWeight(currNode.ID, s);
                if ((cost+currNode.gn)<iter->gn)
                {
                    iter->gn = cost + currNode.gn;
                    iter->fn = iter->gn + straightLineVec[iter->ID];
                    cout<<"the new gn is"<<iter->gn;
                    cout<<endl;
                    cout<<"the new fn is"<<iter->fn<<endl;
                    parent[iter->ID] = currNode.ID;
                    continue;
                }

            }
            //û��
            int newgn =currNode.gn + romaniaGraph.getWeight(currNode.ID, s);
            cout<<"currNode.gn="<<currNode.gn<<endl;
            cout<<"weight="<<romaniaGraph.getWeight(currNode.ID, s)<<endl;
            int hn = straightLineVec[s];
            searchNOde newNode(s, newgn, newgn + hn);
            expandedNodeVec.push_back(newNode);
            cout<<"new node"<<s<<endl;
            cout<<"its fn is"<<newgn<<"+"<<hn<<"="<<newgn+hn<<endl;
            parent[s] = currNode.ID;
        }
        std::sort(expandedNodeVec.begin(), expandedNodeVec.end());
    }
}

vector<int> AStar::getPath()
{
    vector<int> path;
    int endVer = romaniaGraph.getPos("Bucharest");
    int p = parent[endVer];
    path.push_back(endVer);
    path.push_back(p);
    while (p!=-1)
    {
        p = parent[p];
        path.push_back(p);
    }
    auto iter1=path.begin();
    auto iter2=iter1+1;
    for(;iter2!=path.end()-1;iter1++,iter2++)
    {
        totalCost+=romaniaGraph.getWeight(*iter1,*iter2);
        cout<<romaniaGraph.getWeight(*iter1,*iter2)<<endl;
    }
    return path;
}

int AStar::getFinalCost()
{

    return totalCost;
}

