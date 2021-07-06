#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

//定义磁道请求结构
struct Request
{
    string name;//名字
    int track;//磁道号
    Request(string m,int n){
        name=m;
        track=n;
    }
    bool operator <(const Request req)
    {
        return track<req.track;
    }

};

//磁道节点


//定义处理结构
class DiskSchedule
{
public:
    DiskSchedule()=default;
    DiskSchedule(const vector<Request>& vec);
    //先来先服务法处理请求
    void runWithFCFS();
    //最短
    void runWithSFS();
    //电梯
    void runWithEle();
    void print();
private:
    int currTrack=90;//读写头位置
    vector<Request> waitReqVec;//当前还剩余的读写请求
    int totalReq;//总的请求个数
    int totalTracks=0;//调度过程中经过的所有的磁道数
    vector<Request> finishedReq;//处理了的请求
};


DiskSchedule::DiskSchedule(const vector<Request>& vec)
{
    waitReqVec=vec;
    totalReq=vec.size();
}

void DiskSchedule::runWithFCFS()
{
    while (!waitReqVec.empty())
    {
        //计算第一个节点与当前读写头的距离即可
        //然后更新读写头位置
        Request req=waitReqVec.front();
        finishedReq.push_back(req);
        waitReqVec.erase(waitReqVec.begin());
        totalTracks+=abs(currTrack-req.track);
        currTrack=req.track;
    }

}

void DiskSchedule::runWithSFS()
{
    //首先将当前队列排序
    sort(waitReqVec.begin(),waitReqVec.end());
    while (!waitReqVec.empty())
    {
        //首先找到第一个大于等于当前磁道位置的请求
        int index=0;
        int disFront;//index之前的磁道与当前位置的距离
        int dis;//index与当前的距离
        for(int i=0;i<waitReqVec.size();i++)
        {
            if(waitReqVec[i].track>=currTrack)
            {
                index=i;
                break;
            }
        }
        //然后判断这个和其之前的谁更近
        if(index==0)
        {
            int i=waitReqVec.size()-1;
            if(waitReqVec[i].track<currTrack)
            {
                //这时当前到了最大的磁道号，所以处理最后一个，否则处理第一个
            }
            else
            {
                i=0;
            }
            //currTrack=waitReqVec[0].track;
            Request req=waitReqVec[i];
            waitReqVec.erase(waitReqVec.begin()+i);
            finishedReq.push_back(req);
            totalTracks+=abs(req.track-currTrack);
            currTrack=req.track;
        }
        else
        {
            disFront=abs(currTrack-waitReqVec[index-1].track);
            dis=abs(currTrack-waitReqVec[index].track);
            if(disFront<dis)
            {
                index--;
            }
             Request req=waitReqVec[index];
            waitReqVec.erase(waitReqVec.begin()+index);
            finishedReq.push_back(req);
            totalTracks+=abs(req.track-currTrack);
            currTrack=req.track;
        }

    }
}

void DiskSchedule::runWithEle()
{
    if(waitReqVec.size()==0)
    {
        return;
    }
    //题目已经默认当前磁盘位置在90,并且向磁道号增大的地方移动
    sort(waitReqVec.begin(),waitReqVec.end());
    //同样先找到第一个大于等于当前位置的索引
    int index=0;//索引
    bool up=true;//电梯向上运行
    for(int i=0;i<waitReqVec.size();i++)
    {
        if(waitReqVec[i].track>=currTrack)
        {
            index=i;
            break;
        }
    }
    if(index==0)
    {
        //这时需要判断是不是所有的都大于当前位置还是小于
        if(waitReqVec[0].track<currTrack)
        {
            up=false;
            index=waitReqVec.size()-1;
        }
    }
    while(!waitReqVec.empty())
    {
         if(up)
         {
             //电梯上行
             Request req=waitReqVec[index];
             waitReqVec.erase(waitReqVec.begin()+index);
             finishedReq.push_back(req);
             totalTracks+=abs(req.track-currTrack);
             currTrack=req.track;
             if(index=waitReqVec.size()-1)
             {
                 up=false;
             }

         }
         else
         {
             Request req=waitReqVec[index];
             waitReqVec.erase(waitReqVec.begin()+index);
             finishedReq.push_back(req);
             totalTracks+=abs(req.track-currTrack);
             currTrack=req.track;
             index--;
         }
    }
}

void DiskSchedule::print()
{
    double averageTrack=(double)(totalTracks)/totalReq;
    cout<<"平均移动道数："<<averageTrack<<endl;
    cout<<"访问顺序：";
    for(auto s:finishedReq)
    {
        cout<<s.name<<" ";
    }
}

int main()
{
    vector<Request> reqVec;
    fstream dataFile("request.txt",ios::in);
    if(!dataFile.is_open())
    {
        cout<<"文件读取错误！"<<endl;
        return 0;
    }
    else
    {
        for(int i=0;i<14;i++)
        {
            string name;
            int track;
            dataFile>>name>>track;
            Request req(name,track);
            reqVec.push_back(req);
        }
    }
 //   sort(reqVec.begin(),reqVec.end());
    for(auto s:reqVec)
    {
        cout<<"请求名："<<s.name<<"\t磁道号："<<s.track<<endl;
    }
    DiskSchedule dis1(reqVec);
    DiskSchedule dis2(reqVec);
    DiskSchedule dis3(reqVec);
    cout<<"\n先来先服务算法："<<endl;
    dis1.runWithFCFS();
    dis1.print();
    cout<<endl;
    cout<<"\n最短寻道优先算法："<<endl;
    dis2.runWithSFS();
    dis2.print();
    cout<<endl;
    cout<<"\n电梯调度算法："<<endl;
    dis3.runWithEle();
    dis3.print();
    cout<<endl;
    //dis.runWithFCFS();
     //dis.runWithSFS();
    //dis.runWithEle();
    //dis.print();
    return 0;
}
