#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

//建立新文件
void createNewFile(const char* fileName);
//向一个文件中写入内容
void writeData(const char* fileName,const string& s);
//读取一个文件中的内容
void readFile(const char* fileName);
//查看文件权限
void displayPermissions( char* fileName);
//修改文件权限
void changePerminssions( char* fileName);

int main()
{
    while (true)
    {
    int n=0;
   // string s;
    cout<<"请输入对应的功能"<<endl;
    cout<<"1.创建新文件"<<endl;
    cout<<"2.写文件"<<endl;
    cout<<"3.读文件"<<endl;
    cout<<"4.修改文件权限"<<endl;
    cout<<"5.查看当前文件权限"<<endl;
    cout<<"0.退出"<<endl;
    //createNewFile("file.txt");
    //readFile("data.txt");
   // displayPermissions("data.txt");
  //  cout<<~S_IRWXU<<endl;
   // cout<<S_IRWXU<<endl;
   // int s=5*8*8+7*8+7;
   //chmod("hello",(S_IRWXU)|(S_IRWXG)|(~S_IRWXO)&0);
  //  chmod("hello",s);
   // return 0;
        cin>>n;
        if(n==0)
            return 0;
        if(n==1)
        {
            string fileName;
            cout<<"请输入文件名"<<endl;
            cin>>fileName;
            auto p=fileName.c_str();
            createNewFile(p);
        }
        else if(n==2)
        {
            string fileName;
            cout<<"请输入文件名"<<endl;
            cin>>fileName;
            auto p=fileName.c_str();
            cout<<"请输入要输入的内容"<<endl;
            string datas;
            cin>>datas;
            writeData(p,datas);
        }
        else if(n==3)
        {
            cout<<"请输入要读取的文件名"<<endl;
            string fileName;
            cin>>fileName;
            auto p=fileName.c_str();
            readFile(p);
        }
        else if(n==4)
        {
            cout<<"请输入需要更改权限的文件名"<<endl;
            string fileName;
            cin>>fileName;
            auto p=new char[fileName.length()+1];
            strcpy(p,fileName.c_str());
            changePerminssions(p);
        }
        else if(n==5)
        {
            cout<<"请输入需要查看权限的文件名"<<endl;
            string fileName;
            cin>>fileName;
            auto p=new char[fileName.length()+1];
            strcpy(p,fileName.c_str());
//            char sysfile[15] = "/proc/self/exe";
//            int  namelen = 256;
//            char selfname[256];

//          //  memset( selfname, 0, 256 );

//            if ( -1 != readlink( sysfile, selfname,namelen) )
//            {
//                //cout<<selfname<<endl;
//                //printf( " self name = %s\n",selfname );
//                int len=strlen(selfname);
//                for(int i=0;i<len;i++)
//                {
//                   // cout<<(int)selfname[i]<<endl;
//                    if(selfname[i]<=0)
//                        selfname[i]=0;
//                 }
//                selfname[len]=0;
                //cout<<selfname;
                displayPermissions(p);
           // }


        }
    }
    return 0;
}
void createNewFile(const char* fileName)
{
    umask(0000);
    int fd=open(fileName,O_RDWR|O_CREAT|O_EXCL,0666);

    if(fd==-1)
    {
        cout<<"该文件已存在,将退出创建"<<endl;
        return;
    }
    cout<<"已经成功创建该文件，是否向文件中输入内容"<<endl;
    cout<<"如果是，请输入y，否则输入其余任何内容退出"<<endl;
    string s;
    cin>>s;
    if(s=="y")
    {
        //向文件中写入内容
        cout<<"请输入需要写入的内容,以回车结束"<<endl;
        string s;
        cin>>s;
        writeData(fileName,s);
        cout<<"已经成功写入"<<endl;
    }
    close(fd);


}

void writeData(const char* fileName, const string& s)
{
    int fd=open(fileName,O_RDWR|O_APPEND);
    if(fd==-1)
    {
        cout<<"打开文件错误"<<endl;
    }
    //将s写入
    int lenth=s.size();
   // char buff[lenth+1]=s.c_str();
    const char *k=s.c_str();
   //cout<<"长度"<<strlen(k)<<endl;
    int re=write(fd,k,strlen(k));
   // cout<<"**********代码内部测试"<<k<<endl;
    if(re==-1)
    {
        cout<<"写入错误"<<endl;
        return;
    }
    close(fd);
}

void readFile(const char *fileName)

{
    int fd=open(fileName,O_RDONLY);
    if(fd==-1)
    {
        cout<<"读取文件错误"<<endl;
    }
    cout<<"文件内容是："<<endl;
    char buf[1024];
    //memset(buf,0,1024);
    int re=read(fd,buf,1024);
   // cout<<"读取长度"<<re<<endl;
    close(fd);
    for(int i=0;i<re;i++)
    {
       // cout<<(int)buf[i]<<endl;
        if(buf[i]<=0)
            buf[i]=0;
    }
    buf[re]=0;
    //cout<<buf;
    printf("%s",buf);
    cout<<endl;
}

void displayPermissions( char *fileName)
{
    int status;
    pid_t pid=fork();
    if(pid==0)
    {
        char* pargv[4]={"ls","-l",fileName,NULL};
        if(execv("/bin/ls",pargv)<0)
            cout<<"文件未找到"<<endl;
    }
    else
        wait(&status);

}

void changePerminssions( char *fileName)
{
    cout<<"当前文件权限是"<<endl;
    displayPermissions(fileName);
    mode_t mode;
d:  cout<<"请输入新的权限，计算方式同shell中的chmod命令"<<endl;
    cout<<"例如：777表示为所有用户添加所有读写执行权限"<<endl;
    string ins;
    cin>>ins;
    int u=stoi(ins.substr(0,1));
    int g=stoi(ins.substr(1,1));
    int  o=stoi(ins.substr(2,1));
    if(u<0||u>7||g<0||g>7||o<0||o>7)
    {
        cout<<"输入错误"<<endl;
        goto d;
    }
    bool u0=false;
    bool g0=false;
    bool o0=false;
    if(u==0)
    {
        mode=~S_IRWXU ;
        u0=true;
    }
    else
    {
        if(u-4>=0)
        {

            mode=mode|S_IRUSR;
            u=u-4;
        }
        if(u-2>0)
        {
            mode=mode|S_IWUSR;
            u=u-2;
        }
        if(u==1)
        {
            mode=mode|S_IXUSR;
            u--;
        }
    }

    if(g==0)
    {
        if(u0)
        {
            mode=mode&(~S_IRWXG);
            u0=false;

        }
        else
            mode=mode|~S_IRWXG;
        g0=true;

    }
    else
    {
        if(g-4>=0)
        {
            if(u0)
            {
                mode=mode&S_IRGRP;
                u0=false;
            }
            else
                mode=mode|S_IRGRP;
            g=g-4;
        }
        if(g-2>=0)
        {
            if(u0)
            {
                mode=mode&S_IWGRP;
                u0=false;
            }
            else
                mode=mode|S_IWGRP;
            g=g-2;
        }
        if(g==1)
        {
            if(u0)
            {
                mode=mode&S_IXGRP;
                u0=false;
            }
            else
                mode=mode|S_IXGRP;
            g--;
        }
    }
    if(o==0)
    {
        if(g0)
        {
            mode=mode&(~S_IRWXO);
            g0=false;
        }
        else
            mode=mode|~S_IRWXO;
        o0=true;
    }
    else
    {

        if(o-4>=0)
        {
            if(g0)
            {
                mode=mode&S_IROTH;
                g0=false;
            }
            else
                mode=mode|S_IROTH;
            o=o-4;
        }
        if(o-2>=0)
        {
            if(g0)
            {
                mode=mode&S_IWOTH;
                g0=false;
            }
            else
                mode=mode|S_IWOTH;
            o=o-2;
        }
        if(o==1)
        {
            if(g0)
            {
                mode=mode&S_IXOTH;
                g0=false;
            }
            else
                mode=mode|S_IXOTH;
            o--;
        }
    }
    if(o0)
    {
        mode=mode&0;
    }
    //以上行为很傻逼，直接转成8进制对应的数就好了
    chmod(fileName,mode);
    cout<<"修改后文件权限是"<<endl;
    displayPermissions(fileName);

}
