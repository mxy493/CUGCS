#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <algorithm>
#include <iomanip>
using namespace std;

#define PRINT false
//产生指令序列
vector<int> createADD()
{
    vector<int> intVec;
    int MIN=1;//最小值
    int MAX=32766;//最大值
    srand (time(NULL));
    while (true)
    {
        //在1到32k-2产生随机数
        int n=rand()%MAX+1;
        intVec.push_back(n);
       // if()
        intVec.push_back(n+1);
        if(intVec.size()==320)
        {
            break;
        }
        int n2=rand()%n;
        intVec.push_back(n2);
        intVec.push_back(n2+1);
        int n3=rand()%(MAX-n2-2)+n2+2;
        intVec.push_back(n3);
        intVec.push_back(n3+1);
    }
    return intVec;

}

//将指令序列转换成页地址
vector<int> getPage(vector<int> intVec)
{

    vector<int> pageVec;
    for(int s:intVec)
    {
        int page=s/1024+1;
        pageVec.push_back(page);
    }
    return pageVec;
}

//获得使用FIFO算法的命中率，pageNum表示分配给用户的内存页块个数，pageVec表示页地址流
double hitFIFO(int pageNum,const vector<int>& pageVec)
{
    int nHitNum=0;//表示没有命中的个数
    vector<int> pageQueue;//内存中用户页块
    for(int s:pageVec)
    {
       // cout<<"FIFO out"<<s<<"      ";
        auto iter=find(pageQueue.begin(),pageQueue.end(),s);
        if(iter!=pageQueue.end())
        {
            //表示在内存块中有这个页面

        }
        else
        {
            //内存块中没有这个页面
            //判断已有页块数是否等于pageNum
            //如果没有直接推入，否则去掉头部再推入
            nHitNum++;
            if(pageQueue.size()==pageNum)
            {
                //pageQueue.push_back(s);
#if PRINT
                cout<<"FIFO out"<<*pageQueue.begin()<<"  ";
#endif
                pageQueue.erase(pageQueue.begin());
            }
            //  else
            //  {

            pageQueue.push_back(s);
            // }
        }
    }
    //return (double)hitNum/pageVec.size();
    return 1-(double)nHitNum/pageVec.size();
}

//定义用于LRU算法的结构
struct LRUStruct
{
    int pageID=0;//页块号
    int hitTime=0;//表示访问这个页块时的时间
    LRUStruct()=default;
    LRUStruct(int mpage,int mtime)
    {
        pageID=mpage;
        hitTime=mtime;
    }
    bool operator <(const LRUStruct& ls)
    {//用于比较排序
        return hitTime<ls.hitTime;
    }
    bool operator ==(int page)
    {
        return page==pageID;
    }
};

//使用LRU算法
double hitLRU(int pageNum,const vector<int>& pageVec)
{
    int nHitNum=0;//用以表示没有命中的次数
    int time=0;//初始时间
    vector<LRUStruct> pageInMem;//内存中的，分给用户的页块区域
    for(int s:pageVec)
    {
        time++;
        //cout<<"LRU out"<<s.pageNum<<endl;
        //sort(pageInMem.begin(),pageInMem.end());//首先排序
        auto iter=find(pageInMem.begin(),pageInMem.end(),s);
        if(iter==pageInMem.end())
        {
            //表示缺页
            nHitNum++;
            //查看是否装满
            if(pageInMem.size()==pageNum)
            {
                //这里表示装满了，所以需要进行替换
                sort(pageInMem.begin(),pageInMem.end());//首先排序
                //然后剔除第一个，再将当前的推入
#if PRINT
                cout<<"LRU out"<<pageInMem.begin()->pageID<<endl;
#endif
                pageInMem.erase(pageInMem.begin());
            }
            //推入
            LRUStruct l(s,time);
            pageInMem.push_back(l);

        }
        else
        {
            //找到了，修改hittime即可
            iter->hitTime=time;
#if PRINT
            cout<<"iter pagenum"<<iter->pageID<<"  "<<"time"<<iter->hitTime<<endl;
#endif
        }
    }
    return 1-(double)nHitNum/pageVec.size();

}

struct OPTStruct
{//定义用于OPT算法的结构
    int pageID=0;//页块号
    int firstHit=0;//表示后面的第一个访问这个页块当到当前的距离
    OPTStruct()=default;
    OPTStruct(int mpage,int mtime)
    {
        pageID=mpage;
        firstHit=mtime;
    }
    bool operator <(const OPTStruct& ls)
    {//用于比较排序
        return firstHit>ls.firstHit;
    }
    bool operator ==(int page)
    {
        return page==pageID;
    }
};

//opt算法
double hitOPT(int pageNum,const vector<int>& pageVec)
{
    int nHitNum=0;//没有命中的序列
    vector<OPTStruct> pageInMem;
    auto iter=pageVec.begin();
    for(;iter!=pageVec.end();iter++)
    {
        int currPage=*iter;
        auto iterOfInMem=find(pageInMem.begin(),pageInMem.end(),currPage);
        if(iterOfInMem==pageInMem.end())
        {
            //没有找到
            nHitNum++;
            //首先考查是不是装满了
            if(pageInMem.size()==pageNum)
            {
                //装满了，就要移出去一个，但是首先需要更新信息
                //对在内存中的每一块都要更新
                for(OPTStruct& s:pageInMem)
                {
                    //在指令队列中找到第一个出现的
                    auto tarIter=find(iter,pageVec.end(),s.pageID);
                    if(tarIter==pageVec.end())
                    {
                        //表示后面没有这个元素，将他的值置为最大
                        s.firstHit=1000;
                    }
                    else
                    {
                        int fi=tarIter-iter;
                       // cout<<fi<<"  "<<s.pageID<<endl;
                        s.firstHit=fi;
                    }
                }
               // cout<<endl;
                //然后排序
                sort(pageInMem.begin(),pageInMem.end());
               //排好序后第一个就是在未来最长时间内不会访问的
#if PRINT
                cout<<"OPT out"<<pageInMem.begin()->pageID<<endl;
#endif
                pageInMem.erase(pageInMem.begin());
            }
            OPTStruct opt(currPage,0);
            pageInMem.push_back(opt);
        }

    }
    return 1-(double)nHitNum/pageVec.size();
}

int main()
{
    vector<int> intVec=createADD();
    vector<int> pageVec=getPage(intVec);
    cout<<"页块数"<<setw(10)<<"FIFO"<<setw(20)<<"LRU"<<setw(20)<<"OPT"<<endl;
    for(int i=4;i<33;i++)
    {
        cout<<i<<setw(15);
        cout<<hitFIFO(i,pageVec)<<setw(20);
        cout<<hitLRU(i,pageVec)<<setw(20);
        cout<<hitOPT(i,pageVec)<<endl;

    }

    return 0;
}

