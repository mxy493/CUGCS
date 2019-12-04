#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct PCB
{
    string name;//进程名称
    int needTime=0;//进程需要的时间
    int arriveTime=0;//进程到达的时间
    int finishTime=0;//进程完成的时间
    PCB(string mname,int matime,int mneedtime)
    {
        name=mname;
        arriveTime=matime;
        needTime=mneedtime;
        finishTime=0;
    }
    PCB()=default;
    bool operator <(const PCB &p )
    {
        return arriveTime<p.arriveTime;
    }
    bool operator ==(const PCB &p)
    {
        return p.name==name;
    }
};
//按照进程的运行时间排序
bool sortByNeedTime(PCB pl,PCB pr)
{
    return pl.needTime<=pr.needTime;
}

////按照响应比排序
//bool sortByResponse(PCB pl,PCB pr,int time)
//{
//    double rate1=(double)(time-pl.arriveTime)/pl.needTime;//pl的响应比-1
//    double rate2=(double)(time-pr.arriveTime)/pr.needTime;
//    return rate1<=rate2;
//}
struct Resopnse
{
    //用于计算响应比
    int index=0;//序号
    double response=0;//对应序号的响应比
    bool operator <(const Resopnse& res)
    {
        return response>res.response;
    }//需要注意的是，由于是按照响应比高的优先，所以是>
};

struct Process
{//进程运行结构

    bool isFree=true;//是否闲置
    int needTime=0;//运行完当前进程需要多少时间
    PCB pcb;//当前进程
    void setPCB(const PCB& p)
    {
        needTime=p.needTime;
        isFree=false;
        pcb=p;
    }
    void run(PCB &p)
    {
        needTime--;
        if(needTime==0)
        {
            isFree=true;
            //将运行完毕的PCB取出
            p=pcb;
            PCB nullPcb;
            pcb=nullPcb;

        }
    }
};

class Dispatch
{
public:
    Dispatch()=default;
    Dispatch(const vector<PCB> &all);
    void run(int n);//根据不同算法运行调度，1表示先来先服务，2表示短进程优先，3表示响应比高优先
    void printFinished();//输出运行结果
    //void calTurnoverTime();//用于计算周转时间等信息



private:
    int totalNumProcess=0;
    int time=0;//时间，此时间为系统时间
    Process pro1;//第一个任务处理程序
    Process pro2;//第二个任务处理程序
    vector<PCB> allProcess;//所有任务，存在这里面,当时间变化的时候，里面的元素相应变化
    vector<PCB> waitProcess;//在当前时间，等待处理的任务
    vector<PCB> finishedProcess;//完成了的任务

    double averageTurnoverTime=0;//平均周转时间
    double averageWeightTurnoverTime=0;//带权周转时间

    void updateAllProFIFS();//根据先来先服务算法更新等待任务顺序
    void updateAllProSHORT();//根据运行时间来更新等待任务
    void updateAllProResponse();//根据响应比跟新等待任务
    void calTurnoverTime();//用于计算周转时间等信息

};

Dispatch::Dispatch(const vector<PCB> &all)
{
    allProcess=all;
    sort(allProcess.begin(),allProcess.end());
    time=0;
    totalNumProcess=allProcess.size();
}

void Dispatch::updateAllProFIFS()
{
    //假设当前时间为t,由于allProcess已经按照进程到达时间排序，所以只需要从头部查看即可
    //将从头部开始的，所有进程到达时间在t之前的任务放入waitProcess中
    while(!allProcess.empty())
    {
        if(/*allProcess.front().arrivetime>t*/allProcess.front().arriveTime>time)
            break;
        waitProcess.push_back(allProcess.front());
        allProcess.erase(allProcess.begin());
    }
}

void Dispatch::updateAllProSHORT()
{
    //假设当前时间为t,由于allProcess已经按照进程到达时间排序，所以只需要从头部查看即可
    //将从头部开始的，所有进程到达时间在t之前的任务放入waitProcess中
    while(!allProcess.empty())
    {
        if(/*allProcess.front().arrivetime>t*/allProcess.front().arriveTime>time)
            break;
        waitProcess.push_back(allProcess.front());
        allProcess.erase(allProcess.begin());

    }
    //由于是按照运行时间排序，所以还需更新wait
    sort(waitProcess.begin(),waitProcess.end(),sortByNeedTime);
}
void Dispatch::updateAllProResponse()
{
    //假设当前时间为t,由于allProcess已经按照进程到达时间排序，所以只需要从头部查看即可
    //将从头部开始的，所有进程到达时间在t之前的任务放入waitProcess中
    while(!allProcess.empty())
    {
        if(/*allProcess.front().arrivetime>t*/allProcess.front().arriveTime>time)
            break;
        waitProcess.push_back(allProcess.front());
        allProcess.erase(allProcess.begin());
    }
    //按照响应比排序一次
   // 先获得响应比
    vector<Resopnse> resVec;
    for(int i=0;i<waitProcess.size();i++)
    {
        Resopnse res;
        res.index=i;
        res.response=(double)(time-waitProcess[i].arriveTime)/waitProcess[i].needTime;
        resVec.push_back(res);
    }
    //然后排序
    sort(resVec.begin(),resVec.end());
    //根据响应比顺序排列wait表
    vector<PCB> tempVec;
    for(auto s:resVec)
    {
        tempVec.push_back(waitProcess[s.index]);
    }
    for(int i=0;i<tempVec.size();i++)
    {
        waitProcess[i]=tempVec[i];
    }
}

//void Dispatch::runWithFIFS()
void Dispatch::run(int n)
{
    while(true)
    {
        //if(allProcess.empty()&&allProcess.empty)
        if(totalNumProcess==finishedProcess.size())
        {
            //表示运行完毕
            break;
        }
        //首先更新等待队列
        //updateAllProFIFS();
       // updateAllProSHORT();
       // updateAllProResponse();
        if(n==1)
            updateAllProFIFS();
        else if(n==2)
            updateAllProSHORT();
        else if(n==3)
            updateAllProResponse();
        //fun();
        time++;
        //对第一个任务处理程序，首先判断是否闲置
        if(pro1.isFree==true)
        {
            //在等待任务不为空的时候，取等待任务
            if(!waitProcess.empty())
            {
                pro1.setPCB(waitProcess.front());
                waitProcess.erase(waitProcess.begin());

            }

        }
        if(pro1.isFree==false)
        {
            PCB p;
            pro1.run(p);
            if(p.name!="")
            {
                p.finishTime=time;
                finishedProcess.push_back(p);
            }

        }
        //对第二个任务处理程序
        if(pro2.isFree==true)
        {
            //在等待任务不为空的时候，取等待任务
            if(!waitProcess.empty())
            {
                pro2.setPCB(waitProcess.front());
                waitProcess.erase(waitProcess.begin());

            }

        }
        if(pro2.isFree==false)
        {
            PCB p;
            pro2.run(p);
            if(p.name!="")
            {
                p.finishTime=time;
                finishedProcess.push_back(p);
            }

        }
        //time++;
    }
    calTurnoverTime();
}

void Dispatch::printFinished()
{
    for(auto s:finishedProcess)
    {
        cout<<"进程名称："<<s.name<<"\t进程完成时间："<<s.finishTime<<endl;
    }
    cout<<"平均周转时间："<<averageTurnoverTime<<endl;
    cout<<"平均带权周转时间： "<<averageWeightTurnoverTime<<endl;
}

void Dispatch::calTurnoverTime()
{
    //首先计算各个任务的周转时间
   // vector<double> weightYurTimeVec;
    int totalTurTime=0;
    double totalWeiTurTime=0;
    for(auto s:finishedProcess)
    {
        int tmp=s.finishTime-s.arriveTime;
        double weight=(double)tmp/s.needTime;
        //weightYurTimeVec.push_back(weight);
        totalTurTime+=tmp;
        totalWeiTurTime+=weight;
    }
    averageTurnoverTime=(double)totalTurTime/finishedProcess.size();
    averageWeightTurnoverTime=(double)totalWeiTurTime/finishedProcess.size();

}

int main()
{
    //先读出所有的进程信息，存放到容器中
    vector<PCB> PCBVec;
    fstream dataFile("data.txt",ios::in);
    if(!dataFile.is_open())
    {
        cout<<"文件打开失败！"<<endl;
        return 1;
    }
    //文件格式  进程名 到达时间 运行时间
    int total=10;
    while (total>0)
    {
        string name="";
        int arriveTime=0;
        int needTime=0;
        dataFile>>name>>arriveTime>>needTime;
     //   cout<<name<<" "<<arriveTime<<" "<<needTime<<endl;
        PCB proc(name,arriveTime,needTime);
        PCBVec.push_back(proc);
        total--;
    }
    //按照到达时间排序
   sort(PCBVec.begin(),PCBVec.end());
//   for(auto s:PCBVec)
//   {
//       cout<<s.arriveTime<<endl;
//   }
    //开始进程的调度×××××××××××××××××××××××××××
   cout<<"采用先来先服务算法："<<endl;
    Dispatch fcfs(PCBVec);
    //dis.runWithFIFS();
    fcfs.run(1);
    fcfs.printFinished();
    //cout << "Hello World!" << endl;
    cout<<endl;
    cout<<"采用短进程优先调度算法："<<endl;
    Dispatch sfs(PCBVec);
    //dis.runWithFIFS();
    sfs.run(2);
    sfs.printFinished();
    cout<<endl;
    cout<<"采用响应比高者优先算法："<<endl;
    Dispatch rfs(PCBVec);
    //dis.runWithFIFS();
    rfs.run(3);
    rfs.printFinished();
    cout<<endl;
    return 0;
}
