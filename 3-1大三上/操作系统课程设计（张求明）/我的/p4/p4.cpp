#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

pid_t pid1;
pid_t pid2;
int fd[2];

void ChildOne(int s)
{
    cout<<"Child Process 1 is killed by Parent! "<<endl;
    exit(0);
}

void ChildTwo(int s)
{
    cout<<"Child Process 2 is killed by Parent! "<<endl;
    exit(0);
}

void ParentKill(int s)
{
    int status1;
    int status2;

    kill(pid1,SIGTERM);
    wait(&status1);
    kill(pid2,SIGTERM);

    wait(&status2);
    close(fd[0]);
    close(fd[1]);
    cout<<"Parent Process is Killed!"<<endl;
    exit(0);
}

int main()
{
//    int status1;
//    int status2;
   // int fd[2];
    if(pipe(fd)==-1)
    {
        cout<<"创建管道错误"<<endl;
        return 1;
    }
    /*pid_t*/ pid1=fork();
    //pid_t pid2=fork();
    //if(pid1==-1||pid2==-1)
  //  {
  //      cout<<"子进程创建失败"<<endl;
   //     return 1;
  //  }

    //int n=1;
    if(pid1==0)
    {
        int n=1;
        signal(SIGINT,SIG_IGN);
        signal(SIGTERM,ChildOne);
        close(fd[0]);
        while(true)
        {

            string str="I send message "+to_string(n)+" times";
            const char *p=str.c_str();
            // char *p="I send message x times";
            write(fd[1],p,strlen(p));
            sleep(1);
            n++;
           // cout<<str<<"888888888"<<endl;
            //printf("%d\n",n);
            //cout<<"pid1"<<getpid()<<endl;

        }
        close(fd[1]);

            exit(0);
    }
    /*pid_t */pid2=fork();
     if(pid2==0)
    {
         signal(SIGINT,SIG_IGN);
         signal(SIGTERM,ChildTwo);
         close(fd[1]);
         while(true)
         {

             char p[100];
             int len=read(fd[0],p,sizeof(p));
             cout<<p<<endl;
            // sleep(1);
             //cout<<"pid2"<<getpid()<<endl;

         }
         close(fd[0]);
         exit(0);
    }
    else
     {
         sleep(1);
         signal(SIGINT,SIG_IGN);
         while(1)
             signal(SIGINT,ParentKill);

    }


    return 0;
}


