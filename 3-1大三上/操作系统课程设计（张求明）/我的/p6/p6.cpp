#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/shm.h>
using namespace std;

//采用管道通信
void pipeCon()
{
    int status;
    int fd[2];
    if(pipe(fd)==-1)
    {
        cout<<"创建管道错误"<<endl;
        return ;
    }
    pid_t pid=fork();
    if(pid==-1)
    {
        cout<<"创建子进程失败"<<endl;
        return ;
    }
    else if(pid==0)
    {
        auto id=getpid();
        string s=to_string(id);
        s+=" is sending a message to parent";
        //char *m="is sending a message to parent";
        char *m=new char[s.size()+2];
        s.copy(m,s.size(),0);
        m[s.size()]=0;
        close(fd[0]);
        write(fd[1],m,strlen(m));
        close(fd[1]);
        return ;
        //exit(0);
    }
    else
    {
        close(fd[1]);
        char p[100];
        int len=read(fd[0],p,sizeof(p));
        p[len]=0;
        cout<<p<<endl;
        close(fd[0]);
        wait(&status);
    }
    return ;
}

#define MAX_TEXT 512
struct msg_st
{
    long int msg_type;
    char text[MAX_TEXT];
};

//采用消息队列
void client();
void server();
void messQue()
{

    //client();
    pid_t pid=fork();
    if(pid==0)
        client();
    else
    {
        sleep(1);
        server();
        wait(NULL);
    }
    return ;
}

void client()
{
    int running = 1;
    struct msg_st data;
    //data.msg_type=1;
    char buffer[BUFSIZ];
    int msgid = -1;

    //建立消息队列
    msgid = msgget((key_t)75, 0666 | IPC_CREAT);
    if(msgid == -1)
    {
        cout<<"建立消息队列出现错误"<<endl;
        exit(1);
    }

    string s=to_string(getpid());
    //cout<<s;
    s.copy(data.text,s.size(),0);
    //cout<<data.text;
    data.msg_type = 1;
    //向队列发送数据
    if(msgsnd(msgid, (void*)&data, MAX_TEXT, IPC_NOWAIT) == -1)
    {
        cout<< "消息发送失败"<<endl;;
        exit(1);
    }
    struct msg_st receve;
    long int msgtype=getpid();
    if(msgrcv(msgid, (void*)&receve, BUFSIZ, msgtype, 0) == -1)
    {
        cout<<"消息接收失败"<<endl;
        exit(1);
    }
    else
    {
        cout<<"receive reply from: "<<receve.text<<endl;
    }

    sleep(1);

    exit(0);

}

void server()
{
    int running = 1;
    int msgid = -1;
    struct msg_st data;
    long int msgtype = 1;

    //建立消息队列
    msgid = msgget((key_t)75, 0666|IPC_CREAT);
    if(msgid == -1)
    {
        cout<<"消息队列建立失败"<<endl;
        exit(1);
    }

        if(msgrcv(msgid, (void*)&data, BUFSIZ, msgtype, 0) == -1)
        {
            cout<<"获取消息失败"<<endl;
            exit(1);
        }
        else
        {
            cout<<"serving for client: "<<data.text<<endl;

            int remsgid=stoi((string)data.text);
            //cout<<remsgid;
             struct msg_st reply;
             reply.msg_type=remsgid;
             string s=to_string(getpid());
             //cout<<s;
             s.copy(reply.text,s.size(),0);
             //reply.text
             if(msgsnd(msgid,&reply,MAX_TEXT, IPC_NOWAIT)==-1)
             {
                cout<<"server发送应答消息错误"<<endl;
                exit(1);
             }
        }



  //  }
 //   //删除消息队列
    if(msgctl(msgid, IPC_RMID, 0) == -1)
    {
       cout<<"消息队列删除错误"<<endl;
        exit(1);
    }
    exit(0);

}

//采用共享内存方式
void createMem();
void writeMem();
void shareMem()
{
    pid_t pid=fork();
    if(pid==-1)
    {
        cout<<"创建进程错误"<<endl;
        return ;
        //exit(1);
    }
    else if(pid==0)
    {
        createMem();
    }
    else
    {
        writeMem();
        wait(NULL);
    }
    return ;
}

void createMem()
{
    int shmID=shmget((key_t)233,512,IPC_CREAT|0600);
    if(shmID==-1)
    {
        cout<<"createMem:共享内存创建失败"<<endl;
        exit(1);
    }
    sleep(1);
    char *shmADD=(char*)shmat(shmID,NULL,0);
    char *p;
    cout<<shmADD<<endl;
    shmdt(shmADD);
    shmctl(shmID, IPC_RMID, NULL) ;
    exit(0);

}

void writeMem()
{
    int shmID=shmget((key_t)233,512,IPC_CREAT|0600);
    if(shmID==-1)
    {
        cout<<"writeMem:共享内存创建失败"<<endl;
        exit(1);
    }
    char *shmADD=(char*)shmat(shmID,NULL,0);
    char *p="进程B向共享内存中写入数据";
    strcpy( shmADD, p);
    cout<<p<<endl;
    shmdt( shmADD );
    return ;
    //exit(0);
}

int main()
{
    //cout << "Hello World!" << endl;
    //pipeCon();
    //messQue();
    //shareMem();
    cout<<"请选择通信方式："<<endl;
    cout<<"1.通过管道"<<endl<<"2.通过消息队列"<<endl<<"3.通过共享内存"<<endl<<"0.退出"<<endl;
    int n;
    while(1){
        cout<<"请输入：";
        cin>>n;
        if(n==1)
        {
            pipeCon();
        }
        else if(n==2)
        {
            messQue();
        }
        else if(n==3)
        {
            shareMem();
        }
        else if(n==0)
        {
            break;
        }
        else
        {
            cout<<"输入有误，请重新输入：";
            continue;
        }
    }
    return 0;
}
