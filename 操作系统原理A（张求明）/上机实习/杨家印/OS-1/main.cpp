//
//  main.cpp
//  OS-1
//
//  Created by 杨 on 2018/5/25.
//  Copyright © 2018年 杨. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
struct LinkNode{                           //定义链表结点
    string name;                           //进程名
    int need;                              //需运行时间
    int turn;                              //周转时间
    struct LinkNode *link;
};

LinkNode *RQ1,*RQ2;
int main() {
    int i=0,j=0;
    string A[3][6];
    string B[3][6];
    LinkNode *p,*q,*s=new LinkNode;
    int clock=0;                         //时钟
    int pie=7;                           //时间片
    
    ifstream ifile;
    ifile.open("/Users/yang/Desktop/RQ1.txt");        //将文档中的数据存入数组A，方便将其插入链表RQ1中
    string sline;
    string out;
    string s1,s2,s3,s4,s5,s6;
    while(getline(ifile,sline))
    {
        istringstream sin(sline);
        sin>>s1>>s2>>s3>>s4>>s5>>s6;
        A[i][0]=s2;A[i][1]=s3;A[i][2]=s4;A[i][3]=s5;A[i][4]=s6;
        i++;
    }
    ifile.close();
    ifile.open("/Users/yang/Desktop/RQ2.txt");        //将文档中的数据存入数组B，方便将其插入链表RQ2中
    while(getline(ifile,sline))
    {
        istringstream sin(sline);
        sin>>s1>>s2>>s3>>s4>>s5>>s6;
        B[j][0]=s2;B[j][1]=s3;B[j][2]=s4;B[j][3]=s5;B[j][4]=s6;
        j++;
    }
    RQ1=(LinkNode*)malloc(sizeof(LinkNode));           //建立RQ1链表
    RQ1->name=A[0][0];
    RQ1->need=atoi(A[1][0].c_str());
    RQ1->turn=atoi(A[2][0].c_str());
    RQ1->link=NULL;
    p=RQ1;
    for(int j=1;j<5;j++){
        q=(LinkNode*)malloc(sizeof(LinkNode));
        q->name=A[0][j];
        q->need=atoi(A[1][j].c_str());
        q->turn=atoi(A[2][j].c_str());
        p->link=q;
        q->link=NULL;
        p=p->link;
    }
    RQ2=(LinkNode*)malloc(sizeof(LinkNode));           //建立RQ2链表
    RQ2->name=B[0][0];
    RQ2->need=atoi(B[1][0].c_str());
    RQ2->turn=atoi(B[2][0].c_str());
    RQ2->link=NULL;
    p=RQ2;
    for(int j=1;j<5;j++){
        q=(LinkNode*)malloc(sizeof(LinkNode));
        q->name=B[0][j];
        q->need=atoi(B[1][j].c_str());
        q->turn=atoi(B[2][j].c_str());
        p->link=q;
        q->link=NULL;
        p=p->link;
    }
    p=RQ1;                                               //利用轮转法处理RQ1
    int a=0;
    while(p!=NULL){
        while(p!=NULL&&p->need>0){                       //RQ1未处理完毕
            q=p;
            while(q->link!=NULL)q=q->link;               //处理当前进程
            if(p->need>pie){                             //进程需求时间大于时间片
                clock+=pie;                              //时钟增加一个时间片的时间
                p->need-=pie;                            //该进程须运行时间减去一个时间片的时间
                if(s!=NULL) s->link=p->link;             //进程未运行完的部分存入表尾
                q->link=p;
                p=p->link;
                q->link->link=NULL;
            }
            else{                                        //进程需求时间小于时间片
                a++;
                clock+=p->need;                          //时钟增加该进程的需运行时间
                p->need=0;                               //该进程处理完毕
                p->turn+=clock;                          //进程周转时间加上之前的未单次处理完毕的进程数时间片及此次进程须运行时间
                if(a==1) RQ1=p;                          //进程成为RQ1链表的头结点
                s=p;
                p=p->link;                               //处理下一进程
            }
        }
        while(p!=NULL&&p->need==0){                      //跳过已处理完毕的进程
            p=p->link;
        }
    }
    for(int b=0;b<5;b++){                               //用短进程优先调度处理RQ2
        q=RQ2;
        p=(LinkNode*)malloc(sizeof(LinkNode));
        p->need=1000;
        p->link=NULL;
        while(q!=NULL){
            if(q->need!=0&&q->need < p->need) p=q;
            q=q->link;
        }
        clock+=p->need;
        p->turn+=clock;
        p->need=0;
    }
    
    p=RQ1;
    cout<<"RQ1各进程运行时间"<<endl;
    while(p!=NULL){
        cout<<p->name<<":"<<p->turn<<endl;
        p=p->link;
    }
    q=RQ2;
    cout<<"RQ2各进程运行时间"<<endl;
    while(q!=NULL){
        cout<<q->name<<":"<<q->turn<<endl;
        q=q->link;
    }
    return 0;
}
