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
    //首先第一个节点入
    numOfNode++;
    int firstVer=romaniaGraph.getPos("Arad");
    int hn = straightLineVec[firstVer];
    searchNOde firstNOde(firstVer, 0, hn);
    expandedNodeVec.push_back(firstNOde);
    parent[firstVer] = -1;//当为-1则是到达起点
    while (!expandedNodeVec.empty())
    {
        //取出首节点
        searchNOde currNode = expandedNodeVec.front();
        expandedNodeVec.erase(expandedNodeVec.begin());
        //把这个节点放到close中
        closeList[currNode.ID] = true;
        //如果是目标节点，结束
        if (romaniaGraph.getNameOfIndex(currNode.ID)== "Bucharest")
        {
            return;
        }
        //获取这个节点的相邻节点
        vector<int> allNeighbor = romaniaGraph.getAllNeighbor(currNode.ID);
        //对所有相邻节点有
        for (auto s : allNeighbor)
        {
            numOfNode++;
            //先记住路径
            pathNode path(currNode.ID,s);
            pathNOdeVec.push_back(path);
            //如果该节点在close中，忽略
            if (closeList[s]==true)
            {
                continue;
            }
            //在已经扩展节点中查找，如果有，看是否更新
            auto iter=find(expandedNodeVec.begin(), expandedNodeVec.end(), s);
            if (iter!=expandedNodeVec.end())
            {
                cout<<"currNode  is in expandedVec"<<s<<endl;
                cout<<"the old g is "<<iter->gn<<endl;
                //说明有，则查看是不是需要更新，如果当前的G值更小则就需要更新g和f,并修改parent
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
            //没有
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

