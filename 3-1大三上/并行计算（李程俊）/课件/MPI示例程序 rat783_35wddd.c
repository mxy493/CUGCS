//把散乱的if else 整个连起来，完全分成独立的结构。以后想怎么改都可以。
//这里的全局和局部不在同一个时刻发生，分开了
//第几次 总值 平均分值 最大分值 最小分值 分值方差 当前最好解：文本文档的内容
#include "mpi.h"
#include <math.h>
#include <time.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define NPROC 64//进程数量（主从各一个宏定义）@@@@@@@@@@@@@
#define N_COLONY   100// N_COLONY>=xColony300
#define CITY 783 
#define TWOGRP 21//实际是20：1^1
#define GRPSCALE 8//组的规模@@@@@@@@@@@@
#define grpnum (NPROC/GRPSCALE)//组的个数
///////////////////////////////////////////////slave
int     xColony=N_COLONY;     //##//  个体数
int     xCity=CITY;//（问题相关）
double  edgeSpeed=5000;    //##//  临界速度
////////////////////////
double  edgeSpeed2=10;
////////////////////////
double  PROBAB1=0.02;    //##//  变异概率 0.02!
double  PROBAB2=0.05;    //##//  映射概率 //0.04(80) 0.03(50) 0.015(80)  0.05(50);
long    Ni,NOCHANGE=200000;  //##//  最大停止改变代数
long loopcounter=0;
long MAXGEN =735000000;//5
long INTERVAL =350000;//
int     colony[N_COLONY][CITY];//所有个体的染色体
double  cityXY[CITY][2];
double  city_dis[CITY][CITY];
double  dis_p[N_COLONY];//所有个体的评估值
///////////////////////////////////
double  tempdis;//传回的个体的评估值
int     tempcol[CITY];//传回的个体的染色体
///////////////////////////////////
double  sumbest,sumTemp,sumworst;
double  speed;
int     temp[CITY],ibest;
clock_t timeStart,timeNow,timeTemp;
time_t Start,End;
double tttts;//!!!!!!!!!!!!!!!!!!!!!!!!!!!tttt->tttts
FILE *fpme;
char filepath[100],filepath2[100],filepath3[100];
///////////////////////////////////阿光
//int   Edge=5;
//double probab=0.3;
//int     next[CITY][CITY];
//int count;
///////////////////////////////////阿光
void initm();
void    init();
int     position(int *tmp,int C);
void    invert(int pos_start,int pos_end);
void    printBest(long GenNum,long Ni);
void    tempTest(int i);
void    mapped();
void    LastCP();
double  path(int tmp[],int k1,int k2);
//阿光的函数
//int Cross_over(int);   //变异
//void check();      //检查是否有相同，完成第一个功能
//double standard(); //返回的一个接受标准
//void Next();  //建立城市的近邻矩阵   ......可删
//int  change_same(int);    //对相同的个体进行处理
//void differ();  //异化，完成第二个功能
//int in_mapped(int);
int in_mapped(int tmp[],double dis);  //外部映射算子
int move_map(int tmp[],double dis,int same);

//阿光的函数
////////////////////////////////////////////////slave
int main( int argc, char *argv[] )
{
    int mytid,numprocs;
    MPI_Status status;
 ///////////////////////////////////////////////master
	FILE *fp;
	int sign=1,tids[NPROC],ccs[NPROC],n,nproc,i,who,msgtype,i1,j1,tempi=0;
	double temps=0.0,result,fk[NPROC][N_COLONY];
	int hao[NPROC];
	//int cru1,cru2;
	double data[NPROC],data2[NPROC],tempdata,tempfk[N_COLONY],*ptrdata[NPROC],*ptrfk[NPROC],dt,databest[NPROC],*ptrtemp,*ptrfktemp;//指针数组用来存放精英的顺序
	int chrom[NPROC][CITY],tempchr[CITY],*ptrchrom[NPROC],chrombest[NPROC][CITY],*ptrctemp;//（问题相关）第一维是进程数，第二维比城市数大。
	int j,k,m,x,tt;//用于交换，m用来做记录组别的变量
	int times=0,timeslave=0;//times是提交的次数
	int cru[grpnum],wcru[grpnum],maxccs[grpnum];//cru表示的是位置
	int p[grpnum];
	double best;
	clock_t timeStartm,timeNowm,timeTempm;
//!!
	int mbest_i,PDi=0,PDi0=0,intr_best[100];
	float MSTD[NPROC],MlSTD[NPROC],MlSTDagain[NPROC],TMSTD,AMlSTD,PD[100],PD0[100],SPAD0[100],SPAD[100],Maxtemp,MaxMlSTD0[100],MaxMlSTD[100],Mintemp,MinMlSTD0[100],MinMlSTD[100],SD0[100],SD[100],tempSD;
//!!
///////////////////////////////////////////////master
////////////////////////////////////////////////slave
 /*原来的*/
	int issubmit,kk;
	double t,probab1=PROBAB1, probab2=PROBAB2;
	double  dis_p2[N_COLONY],dis_p3[N_COLONY];//p2为处理后的本地适应值，p3为外地传来的适应值
	int dis_count[N_COLONY];
	int multid,i3,j3;
//阿光
	int ia,ib;
	int all_same=0;
	int ibest2,iworst,ipass;
//阿光
/*原来的*/
///////////////////////////
	register int C1,js,ks,pos_C,pos_C1;
	int k1,k2,l1,l2,pos_flag,icount,sendyet;
	register double disChange;
	static int is=0;
///////////////////////////
	int sm=0;//by me to 标志插入与否
	char mname[30];
	int r,in=0;
	FILE *fppp;
	char nameofm[NPROC][30];
//!!矩阵相关
  int xx,yy,zz;
  int mat[CITY][CITY]={0},matbest[CITY][CITY]={0},matlocalbest[CITY][CITY]={0};
  int best_i,count_of_1;
  float D[N_COLONY],STD,lD[N_COLONY],lSTD;
//!!矩阵相关
//////////////////////////////////
	//for(xx=0;xx<100;xx++)
	//	MaxMlSTD[xx]=0.0;
////////////////////////////////////////////////slave  !!!!!is js ks!!!!!!!
	MPI_Init(&argc,&argv);/**//*程序初始化*/
	MPI_Comm_rank(MPI_COMM_WORLD,&mytid);/**//*得到当前进程号*/
	//MPI_Comm_size(MPI_COMM_WORLD,&numprocs);/**//*得到总的进程数*/
	MPI_Get_processor_name(mname,&r);
 	srand((unsigned)time(NULL)+mytid);
	nproc=NPROC;
	strcpy(filepath,argv[1]);
	strcpy(filepath3,argv[3]);
	fppp=fopen(filepath3,"a");
//这次对话，对全部子进程进行注册
	if(mytid==0)
	{
		for(i=0;i<NPROC;i++)
		{
			MPI_Recv(nameofm[i],30,MPI_CHAR,i+1,99,MPI_COMM_WORLD,&status);////////
			fprintf(fppp,"王兄，机器%s上有%d进程\n",nameofm[i],i+1);
		}
		fclose(fppp);
	}
	else
	{
		MPI_Send(mname,sizeof(mname),MPI_CHAR,0,99,MPI_COMM_WORLD);
	}
//这次对话，对全部子进程进行注册
//这次对话，读出坐标，送子进程，再算出边
	if(mytid==0)
	{
		printf("要读的文件是：%s\n",filepath);
		strcpy(filepath2,argv[2]);
		//初始化指针数组
		for(i=0;i<NPROC;i++)
		{
			ptrdata[i]=&data[i];
			ptrchrom[i]=chrom[i];
			ptrfk[i]=fk[i];
		}
		//初始化指针数组
		//初始化x
		for(i=0;i<NPROC;i++)
		{
			hao[i]=i;
		}
		timeStartm=timeNowm=timeTempm=clock();
		time(&Start);
		printf("Start...There is %d gropes.\n",GRPSCALE);
		initm();
		for(i=1;i<=NPROC;i++)
			MPI_Send(*cityXY,CITY*2,MPI_DOUBLE,i,99,MPI_COMM_WORLD);
		printf("\n");
	}
	else
	{
		MPI_Recv(*cityXY,CITY*2,MPI_DOUBLE,0,99,MPI_COMM_WORLD,&status);
		init();
	}
//这次对话，读出坐标，送子进程，再算出边
//进入主循环
	for(loopcounter=0;loopcounter<=MAXGEN;loopcounter++)
	{
		if(loopcounter%INTERVAL==0 &&loopcounter!=0)
			times++;
		if(mytid==0)//主进程
		{
			if(loopcounter%INTERVAL==0 &&loopcounter!=0)//当迁移开始
			{
				printf("Time(s)=%d,The generation is %ld",times,loopcounter);
				if(times%TWOGRP==0)//当全局迁移开始
				{
					//接收各个子种群的最好解
					for(i=0;i<NPROC;i++)
					{
						MPI_Recv(&data[i],1,MPI_DOUBLE,i+1,99,MPI_COMM_WORLD,&status);
						MPI_Recv(chrom[i],CITY,MPI_INT,i+1,99,MPI_COMM_WORLD,&status);
  					}
					//接收各个子种群的最好解
					//找出最好解
					best=data[0];
					for(i=0;i<NPROC;i++)
					{
						if(data[i]<best)
						{
							best=data[i];
							mbest_i=i;
						}
					}
					intr_best[PDi0]=(int)best;
					//找出最好解











//主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1
					//送全群体最好解至每个子种群%%%%%%%%%%%%%%%%%%%%%%%%%%%%
					for(i=0;i<NPROC;i++)
					{
						MPI_Send(&data[mbest_i],1,MPI_DOUBLE,i+1,99,MPI_COMM_WORLD);
						MPI_Send(chrom[mbest_i],CITY,MPI_INT,i+1,99,MPI_COMM_WORLD);
					}
					//送全群体最好解至每个子种群%%%%%%%%%%%%%%%%%%%%%%%%%%%%
					TMSTD=0.0;
					AMlSTD=0.0;
					Maxtemp=0.0;
					Mintemp=30000.0;
					SD0[PDi0]=0.0;
					for(i=0;i<NPROC;i++)
					{
						MPI_Recv(&MSTD[i],1,MPI_FLOAT,i+1,99,MPI_COMM_WORLD,&status);
						MPI_Recv(&MlSTD[i],1,MPI_FLOAT,i+1,99,MPI_COMM_WORLD,&status);						
						//here
						if(MlSTD[i]>Maxtemp)
							Maxtemp=MlSTD[i];
						if(MlSTD[i]<Mintemp)
							Mintemp=MlSTD[i];
						TMSTD+=MSTD[i];
						AMlSTD+=MlSTD[i];
  					}
					MaxMlSTD0[PDi0]=Maxtemp/(1.0*N_COLONY);//最大子种群多样性
					MinMlSTD0[PDi0]=Mintemp/(1.0*N_COLONY);//最小子种群多样性
					PD0[PDi0]=TMSTD/(1.0*NPROC*N_COLONY);
					SPAD0[PDi0]=AMlSTD/(1.0*NPROC*N_COLONY);//平均多样性
					tempSD=0.0;
					for(i=0;i<NPROC;i++)
					{
						tempSD+=(MlSTD[i]/(1.0*N_COLONY)-SPAD0[PDi0])*(MlSTD[i]/(1.0*N_COLONY)-SPAD0[PDi0]);
					}
					SD0[PDi0]=sqrt(tempSD/NPROC);
					//printf("%f %f",TMSTD,AMlSTD);
					printf("\ntotal:%f average:%f max:%f min:%f SD:%f\n",PD0[PDi0],SPAD0[PDi0],MaxMlSTD0[PDi0],MinMlSTD0[PDi0],SD0[PDi0]);
					PDi0++;
//主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1主1















///////////////////////////////////////////////////////////////////////////////////////////////
/*					for(i=0;i<NPROC;i++)
					{
						if(i%GRPSCALE==0)
							printf("\n");
						printf("%d ",hao[i]+1);
					}
					printf("\n");*/
/////////////////////////////////////两种算法由此不同
//移动号表
					tempi=hao[0+in];
					for(i=0;i<grpnum-1;i++)
					{
						hao[i*GRPSCALE+in]=hao[i*GRPSCALE+GRPSCALE+in];
					}
					hao[(grpnum-1)*GRPSCALE+in]=tempi;
/*					printf("以下为传递进行的表");
					for(i=0;i<NPROC;i++)
					{
						if(i%GRPSCALE==0)
							printf("\n");
						printf("%d ",hao[i]+1);
					}*/
//移动号表
//移动种群的排列顺序
					ptrtemp=ptrdata[0+in];
					ptrctemp=ptrchrom[0+in];

					for(i=0;i<grpnum-1;i++)
					{
						ptrdata[i*GRPSCALE+in]=ptrdata[i*GRPSCALE+GRPSCALE+in];
						ptrchrom[i*GRPSCALE+in]=ptrchrom[i*GRPSCALE+GRPSCALE+in];
					}
					ptrdata[(grpnum-1)*GRPSCALE+in]=ptrtemp;
					ptrchrom[(grpnum-1)*GRPSCALE+in]=ptrctemp;
					in++;
					if(in==GRPSCALE)
						in=0;
//移动种群的排列顺序
/////////////////////////////////////两种算法由此不同

					//送全群体最好解至每个子种群%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*					for(i=0;i<NPROC;i++)
					{
						MPI_Send(&data[mbest_i],1,MPI_DOUBLE,i+1,99,MPI_COMM_WORLD);
						MPI_Send(chrom[mbest_i],CITY,MPI_INT,i+1,99,MPI_COMM_WORLD);
					}
					//送全群体最好解至每个子种群%%%%%%%%%%%%%%%%%%%%%%%%%%%%
					TMSTD=0.0;
					AMlSTD=0.0;
					Maxtemp=0.0;
					Mintemp=30000.0;
					//接收每个子种群的情况%%%%%%%%%%%%%%%%%%%%%%%%%%%%
					for(i=0;i<NPROC;i++)
					{
						MPI_Recv(&MSTD[i],1,MPI_FLOAT,i+1,99,MPI_COMM_WORLD,&status);
						MPI_Recv(&MlSTD[i],1,MPI_FLOAT,i+1,99,MPI_COMM_WORLD,&status);						
						//here
						if(MlSTD[i]>Maxtemp)
							Maxtemp=MlSTD[i];
						if(MlSTD[i]<Mintemp)
							Mintemp=MlSTD[i];
						TMSTD+=MSTD[i];
						AMlSTD+=MlSTD[i];
  					}
					//接收每个子种群的情况%%%%%%%%%%%%%%%%%%%%%%%%%%%%
////////////////////////////
					MaxMlSTD[PDi]=Maxtemp/(1.0*N_COLONY);//最大子种群多样性
					MinMlSTD[PDi]=Mintemp/(1.0*N_COLONY);//最小子种群多样性
					PD[PDi]=TMSTD/(1.0*NPROC*N_COLONY);
					SPAD[PDi]=AMlSTD/(1.0*NPROC*N_COLONY);//平均多样性
					//printf("%f %f",TMSTD,AMlSTD);
					printf("\ntotal:%f average:%f max:%f min:%f SD:%f\n",PD[PDi],SPAD[PDi],MaxMlSTD[PDi],MinMlSTD[PDi],SD[PDi]);
					//printf("\ntotal:%f average:%f max:%f min:%f SD:%f\n",PD0[PDi0],SPAD0[PDi0],MaxMlSTD0[PDi0],MinMlSTD0[PDi0],SD0[PDi0]);
////////////////////////////

					PDi++;*/








//主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2
					//送全群体最好解至每个子种群%%%%%%%%%%%%%%%%%%%%%%%%%%%%
					for(i=0;i<NPROC;i++)
					{
						MPI_Send(&data[mbest_i],1,MPI_DOUBLE,i+1,99,MPI_COMM_WORLD);
						MPI_Send(chrom[mbest_i],CITY,MPI_INT,i+1,99,MPI_COMM_WORLD);
					}
					//送全群体最好解至每个子种群%%%%%%%%%%%%%%%%%%%%%%%%%%%%
					TMSTD=0.0;
					AMlSTD=0.0;
					Maxtemp=0.0;
					Mintemp=30000.0;
					SD[PDi]=0.0;
					for(i=0;i<NPROC;i++)
					{
						MPI_Recv(&MSTD[i],1,MPI_FLOAT,i+1,99,MPI_COMM_WORLD,&status);
						MPI_Recv(&MlSTD[i],1,MPI_FLOAT,i+1,99,MPI_COMM_WORLD,&status);						
						//here
						if(MlSTD[i]>Maxtemp)
							Maxtemp=MlSTD[i];
						if(MlSTD[i]<Mintemp)
							Mintemp=MlSTD[i];
						TMSTD+=MSTD[i];
						AMlSTD+=MlSTD[i];
  					}
					MaxMlSTD[PDi]=Maxtemp/(1.0*N_COLONY);//最大子种群多样性
					MinMlSTD[PDi]=Mintemp/(1.0*N_COLONY);//最小子种群多样性
					PD[PDi]=TMSTD/(1.0*NPROC*N_COLONY);
					SPAD[PDi]=AMlSTD/(1.0*NPROC*N_COLONY);//平均多样性
					tempSD=0.0;
					for(i=0;i<NPROC;i++)
					{
						tempSD+=(MlSTD[i]/(1.0*N_COLONY)-SPAD[PDi])*(MlSTD[i]/(1.0*N_COLONY)-SPAD[PDi]);
					}
					SD[PDi]=sqrt(tempSD/NPROC);
					//printf("%f %f",TMSTD,AMlSTD);
					printf("\ntotal:%f average:%f max:%f min:%f SD:%f\n",PD[PDi],SPAD[PDi],MaxMlSTD[PDi],MinMlSTD[PDi],SD[PDi]);
					PDi++;
//主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2主2
















				}//当全局迁移开始
				else//如果是局部迁移
				{
					for(i=0;i<NPROC;i++)
					{
						MPI_Recv(&data[i],1,MPI_DOUBLE,i+1,99,MPI_COMM_WORLD,&status);
						MPI_Recv(chrom[i],CITY,MPI_INT,i+1,99,MPI_COMM_WORLD,&status);
  					}
///////////////////////////////////////////////////////////////////////////////////////!!!!!!!!局部迁移
					for(m=0;m<grpnum;m++)
					{
						tempdata=*ptrdata[GRPSCALE*m];//tempdata=data[grpnum*m];!!!!!!!!!!!!!
						for(k=0;k<CITY;k++)//（问题相关）存放本组第0个进程到temp变量
							tempchr[k]=ptrchrom[GRPSCALE*m][k];//tempchr[k]=chrom[grpnum*m][k];!!!!!!!!!!!!!!!
						for(j=GRPSCALE*m;j<GRPSCALE+GRPSCALE*m-1;j++)//除本组最后一个进程之外，其它全部进程等于它的下一个
						{
							*ptrdata[j]=*ptrdata[j+1];//data[j]=data[j+1];
							for(k=0;k<CITY;k++)
								ptrchrom[j][k]=ptrchrom[j+1][k];//chrom[j][k]=chrom[j+1][k];
						}
						*ptrdata[GRPSCALE+GRPSCALE*m-1]=tempdata;//本组的最后一个进程等于第0个进程data[grpnum+grpnum*m-1]=tempdata;
						for(k=0;k<CITY;k++)//（问题相关）
							ptrchrom[GRPSCALE+GRPSCALE*m-1][k]=tempchr[k];
					}
					printf("\n");
 					for(i=0;i<NPROC;i++)
					{
						MPI_Send(&data[i],1,MPI_DOUBLE,i+1,99,MPI_COMM_WORLD);
						MPI_Send(chrom[i],CITY,MPI_INT,i+1,99,MPI_COMM_WORLD);
						//printf("I send %f to %d\n",data[i],i+1);
					}
 					printf("\n");
				}//如果是局部迁移
///////////////////////////////////////////////////////////////////////////////////////!!!!!!!!局部迁移
//主循环中第二次主从对话
			}//当迁移开始
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}//		if(mytid==0)
		else//子进程程序
		{

			if(loopcounter%INTERVAL==0 &&loopcounter!=0)//当迁移开始
			{
  //发
				iworst=0;
				ibest2=0;
				ipass=rand()%xColony;
				for(j1=1;j1<xColony;j1++)
	   				{
						if(dis_p[j1]>dis_p[iworst])
							iworst=j1;
						if(dis_p[j1]<dis_p[ibest2])
							ibest2=j1;
	   				}
//主循环中第一次主从对话				
				if(times%TWOGRP==0)//当全局迁移开始
				{
//从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1
					//发送子种群最好解
					MPI_Send(&dis_p[ibest2],1,MPI_DOUBLE,0,99,MPI_COMM_WORLD);
					MPI_Send(colony[ibest2],CITY,MPI_INT,0,99,MPI_COMM_WORLD);
					//发送子种群最好解
					//接收群体最好解%%%%%%%%%%%%%%%%%%%%%%%%%%
					MPI_Recv(&tempdis,1,MPI_DOUBLE,0,99,MPI_COMM_WORLD,&status);
					MPI_Recv(tempcol,CITY,MPI_INT,0,99,MPI_COMM_WORLD,&status);
					//接收群体最好解%%%%%%%%%%%%%%%%%%%%%%%%%%
					for(xx=0;xx<xCity;xx++)
					{
						matbest[tempcol[xx]][tempcol[(xx+1)%xCity]]=1;///!!!!!!!!!!
					}
					//int     colony[N_COLONY][CITY];//所有个体的染色体
					for(xx=0;xx<xCity;xx++)
					{
						matlocalbest[colony[ibest2][xx]][colony[ibest2][(xx+1)%xCity]]=1;
					}
					STD=0.0;
					lSTD=0.0;
					for(zz=0;zz<N_COLONY;zz++)
					{
						for( xx=0;xx<CITY;xx++)   //ci chu gui 0
						{
							for(yy=0;yy<CITY;yy++)
								mat[xx][yy]=0;
						}
						for(xx=0;xx<xCity;xx++)
						{
							mat[colony[zz][xx]][colony[zz][(xx+1)%xCity]]=1;//!!!!!!!!!!!!!!!!  
						}

						count_of_1=0;
						for(xx=0;xx<xCity;xx++)
						{
							for(yy=0;yy<xCity;yy++)
							{
								if(matbest[xx][yy]==1&&mat[xx][yy]==1)
								{
									break;
								}
							}
							if(yy<xCity)
								count_of_1++;
						}
						D[zz]=1.0*(xCity-count_of_1)/xCity;
						STD+=D[zz];

						count_of_1=0;
						for(xx=0;xx<xCity;xx++)
						{
							for(yy=0;yy<xCity;yy++)
							{
								if(matlocalbest[xx][yy]==1&&mat[xx][yy]==1)
								{
									break;
								}
							}
							if(yy<xCity)
								count_of_1++;
						}						
						lD[zz]=1.0*(xCity-count_of_1)/xCity;
						lSTD+=lD[zz];
					}//for zz
					//lSTD/=N_COLONY;
					MPI_Send(&STD,1,MPI_FLOAT,0,99,MPI_COMM_WORLD);//这是搞总和
					MPI_Send(&lSTD,1,MPI_FLOAT,0,99,MPI_COMM_WORLD);//这是搞总和
					//here
					//ipass=rand()%xColony;
					//MPI_Send(&fkk,1,MPI_DOUBLE,0,99,MPI_COMM_WORLD);
//从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1从1
//////////////////////////////迁移前先来一次。
/*					//接收群体最好解%%%%%%%%%%%%%%%%%%%%%%%%%%
					MPI_Recv(&tempdis,1,MPI_DOUBLE,0,99,MPI_COMM_WORLD,&status);
					MPI_Recv(tempcol,CITY,MPI_INT,0,99,MPI_COMM_WORLD,&status);
					//接收群体最好解%%%%%%%%%%%%%%%%%%%%%%%%%%
					for(xx=0;xx<xCity;xx++)
					{
						matbest[tempcol[xx]][tempcol[(xx+1)%xCity]]=1;///!!!!!!!!!!
					}
					STD=0.0;
					for(zz=0;zz<N_COLONY;zz++)
					{
						for( xx=0;xx<CITY;xx++)   //ci chu gui 0
						{
							for(yy=0;yy<CITY;yy++)
								mat[xx][yy]=0;
						}
						for(xx=0;xx<xCity;xx++)
						{
							mat[colony[zz][xx]][colony[zz][(xx+1)%xCity]]=1;//!!!!!!!!!!!!!!!!  
						}

						count_of_1=0;
						for(xx=0;xx<xCity;xx++)
						{
							for(yy=0;yy<xCity;yy++)
							{
								if(matbest[xx][yy]==1&&mat[xx][yy]==1)
								{
									break;
								}
							}
						if(yy<xCity)
						count_of_1++;
						}
						D[zz]=1.0*(xCity-count_of_1)/xCity;
						STD+=D[zz];
					}//for zz
					MPI_Send(&STD,1,MPI_FLOAT,0,99,MPI_COMM_WORLD);//这是搞总和*/













//从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2
					//接收群体最好解%%%%%%%%%%%%%%%%%%%%%%%%%%
					MPI_Recv(&tempdis,1,MPI_DOUBLE,0,99,MPI_COMM_WORLD,&status);
					MPI_Recv(tempcol,CITY,MPI_INT,0,99,MPI_COMM_WORLD,&status);
					//接收群体最好解%%%%%%%%%%%%%%%%%%%%%%%%%%
					for(xx=0;xx<xCity;xx++)
					{
						matbest[tempcol[xx]][tempcol[(xx+1)%xCity]]=1;///!!!!!!!!!!
					}
					//int     colony[N_COLONY][CITY];//所有个体的染色体
					for(xx=0;xx<xCity;xx++)
					{
						matlocalbest[colony[ibest2][xx]][colony[ibest2][(xx+1)%xCity]]=1;
					}
					STD=0.0;
					lSTD=0.0;
					for(zz=0;zz<N_COLONY;zz++)
					{
						for( xx=0;xx<CITY;xx++)   //ci chu gui 0
						{
							for(yy=0;yy<CITY;yy++)
								mat[xx][yy]=0;
						}
						for(xx=0;xx<xCity;xx++)
						{
							mat[colony[zz][xx]][colony[zz][(xx+1)%xCity]]=1;//!!!!!!!!!!!!!!!!  
						}

						count_of_1=0;
						for(xx=0;xx<xCity;xx++)
						{
							for(yy=0;yy<xCity;yy++)
							{
								if(matbest[xx][yy]==1&&mat[xx][yy]==1)
								{
									break;
								}
							}
							if(yy<xCity)
								count_of_1++;
						}
						D[zz]=1.0*(xCity-count_of_1)/xCity;
						STD+=D[zz];

						count_of_1=0;
						for(xx=0;xx<xCity;xx++)
						{
							for(yy=0;yy<xCity;yy++)
							{
								if(matlocalbest[xx][yy]==1&&mat[xx][yy]==1)
								{
									break;
								}
							}
							if(yy<xCity)
								count_of_1++;
						}						
						lD[zz]=1.0*(xCity-count_of_1)/xCity;
						lSTD+=lD[zz];
					}//for zz
					//lSTD/=N_COLONY;
					MPI_Send(&STD,1,MPI_FLOAT,0,99,MPI_COMM_WORLD);//这是搞总和
					MPI_Send(&lSTD,1,MPI_FLOAT,0,99,MPI_COMM_WORLD);//这是搞总和
					//here
//从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2从2













				}//if 全局TWOGRP当全局迁移开始
				else// 局部迁移
				{
					//MPI_Send(&fkk,1,MPI_DOUBLE,0,99,MPI_COMM_WORLD);
					MPI_Send(&dis_p[ipass],1,MPI_DOUBLE,0,99,MPI_COMM_WORLD);
					MPI_Send(colony[ipass],CITY,MPI_INT,0,99,MPI_COMM_WORLD);

//主循环中第一次主从对话
//在这里把主进程的内容要回  这里是每次迁移都要做的接受主进程??????????????????????????????????????????????????????????????????????????????????????????????????????????
					MPI_Recv(&tempdis,1,MPI_DOUBLE,0,99,MPI_COMM_WORLD,&status);
					MPI_Recv(tempcol,CITY,MPI_INT,0,99,MPI_COMM_WORLD,&status);
					for(j1=1;j1<xColony;j1++)
					{
						if(dis_p[j1]==tempdis)
						{
							sm=1;
							break;
						}
					}
					if(!sm)//和这个种群中所有都不同的
					{
						if(times%TWOGRP==0)
						{
							dis_p[iworst]=tempdis;
							for(j1=0;j1<xCity;j1++)
								colony[iworst][j1]=tempcol[j1];
						}
						else
						{
							dis_p[iworst]=tempdis;
							for(j1=0;j1<xCity;j1++)
								colony[iworst][j1]=tempcol[j1];
						}
					}
					sendyet=1;
					sm=0;
				}//else 局部迁移
			}//迁移发生的内容
  ////////////////////////////
					for(js=0;js<xCity;js++)temp[js]=colony[is][js];
					disChange=0;pos_flag=0;
					pos_C=rand()%xCity;
  ////////////////////////////
					for(;;)
					{//内for
						if((rand()*1.0/RAND_MAX)<probab1)     //内变异算子
						{
							do pos_C1=rand()%xCity;while (pos_C1==pos_C);
							C1=colony[is][pos_C1];
						}//if
						else
						{
							do js=rand()%xColony;while(js==is);
							ks=position(colony[js],temp[pos_C]);
							C1=colony[js][(ks+1)%xCity];
							pos_C1=position(temp,C1);
						}//else
						if( speed>edgeSpeed && pos_C1<pos_C+2)break;         ///////////////////////
						if((pos_C+1)%xCity==pos_C1 || (pos_C-1+xCity)%xCity==pos_C1 )break;
						k1=temp[pos_C]; k2=temp[(pos_C+1)%xCity]; l1=temp[pos_C1]; l2=temp[(pos_C1+1)%xCity];
						disChange+=city_dis[k1][l1]+city_dis[k2][l2]-city_dis[k1][k2]-city_dis[l1][l2];
						invert(pos_C,pos_C1); pos_flag++;if(pos_flag>xCity-1)break;  ////////////
						pos_C++; if(pos_C>=xCity)pos_C=0;                 /**********************/
						if( speed<edgeSpeed && disChange<0) { dis_p[is]+=disChange; disChange=0; tempTest(is);}     //每有改变就计算
					}//内for ??
					if(speed>=edgeSpeed && disChange<0 )	{dis_p[is]+=disChange;disChange=0; tempTest(is);}  /////speed>=1500 &&
					is++;
					if(is>=xColony)
					{
						Ni++;
						is=0;
						sendyet=0;
				//loopcounter++;
	     //check();                    //此处增加一个函数，完成第一个功能，正确！！！！
		 	 			probab1=PROBAB1*(1-loopcounter*0.5/MAXGEN);        //内逆转概率逐渐减小
						if( (rand()*1.0/RAND_MAX<probab2) )   // speed<edgeSpeed &&
						{
							mapped();
							probab2=PROBAB2*(loopcounter*2.0/MAXGEN+1);    //部分交换概率逐渐增大
						}
		 //if(NOCHANGE-Ni<1) { LastCP(); /*loopcounter=MAXGEN;*/}  //5可改
		//by me if(GenNum>=maxGen || Ni>=NOCHANGE ) { printf("\n-------------------");printBest(GenNum,Ni);exit(1); }
					}
//CountGen++;
			/////////////////////////////////////////////}//外for
		}
	}//while(loopcounter++<=MAXGEN);
	if(mytid==0)
	{
		fpme=fopen(filepath2,"a");
		fprintf(fpme,"This is a result of %d:%lf\n",CITY,best);
		for(xx=0;xx<100;xx++)
		{
			//fprintf(fpme,"%d %f %f %d\n",xx,PD0[xx],PD[xx],intr_best[xx]);
			fprintf(fpme,"%d %f %f %f %f %f %d\n",xx,PD0[xx],SPAD0[xx],MaxMlSTD0[xx],MinMlSTD0[xx],SD0[xx],intr_best[xx]);
			//fprintf(fpme,"PD%d:%f\n",xx,PD[xx]);
		}
							//第几次 总值 平均分值 最大分值 最小分值 分值方差 当前最好解
		fclose(fpme);
	}
	MPI_Finalize();
    return 0;
	//getchar();
}
void initm()
{
  int i;
  double x,y;
  FILE *fp;
  int ffff,eeee;
  if((fp=fopen(filepath,"r"))==NULL){
	  MPI_Finalize();
	  exit(0);}
  //printf("hello");
  fscanf(fp,"%d",&xCity);
  for(i=0;i<xCity;i++)      /*  init cityXY[][]  */
  { //fscanf(fp,"%*d%Lg%Lg",&x,&y);//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
    fscanf(fp,"%*d%d%d",&ffff,&eeee);
          printf("\nffff=%d eeee=%d",ffff,eeee);
    x=ffff;
    y=eeee;
    cityXY[i][0]=x;
    cityXY[i][1]=y;
  }
  fclose(fp);
 /* fp=fopen("c:\\123.txt","w");
  for(i=0;i<xCity;i++)
	  fprintf(fp,"\n%d: %f %f",i+1,cityXY[i][0],cityXY[i][1]);
  
  //getchar();
  fclose(fp);*/

}

void init()
{ int i,j,t,sign,mod,array[CITY];
  double d;
/* FILE *fp;
  //if((fp=fopen(FILE_PATH))==NULL){ exit(0);}
  if((fp=fopen(filepath,"r"))==NULL){ exit(0);}
  fscanf(fp,"%d",&xCity);
  for(i=0;i<xCity;i++)
  { fscanf(fp,"%*d%Lf%Lf",&x,&y);//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
    cityXY[i][0]=x;
    cityXY[i][1]=y;
  }
  fclose(fp);*/
  for(i=0;i<xCity;i++)
  for(j=0;j<xCity;j++)
  { if(j>i)
    { d=(cityXY[i][0]-cityXY[j][0])*(cityXY[i][0]-cityXY[j][0])*1.0+
        (cityXY[i][1]-cityXY[j][1])*(cityXY[i][1]-cityXY[j][1])*1.0;
      city_dis[i][j]=(int)(sqrt(d)+0.5);
      continue;
    }
    if(j==i) {city_dis[i][j]=0;continue;}
    if(j<i)  city_dis[i][j]=city_dis[j][i];
  }
  mod=xCity;
  for(i=0;i<xCity;i++)array[i]=i;     //    init colony[][]
  for(i=0;i<xColony;i++,mod=xCity)
  for(j=0;j<xCity;j++)
  { sign=rand()%mod;
    colony[i][j]=array[sign];
    t=array[mod-1];
    array[mod-1]=array[sign];
    array[sign]=t;
    mod--;
    if(mod==1) colony[i][++j]=array[0];
   }

   for(i=0;i<xColony;i++)		    /*    init dis_p[]       */
   { dis_p[i]=0;
     for(j=0;j<xCity-1;j++)
       dis_p[i]=dis_p[i]+city_dis[*(*(colony+i)+j)][*(*(colony+i)+j+1)];
     dis_p[i]=dis_p[i]+city_dis[**(colony+i)][*(*(colony+i)+xCity-1)];
   }

   ibest=0;sumbest=dis_p[0];	    /*  init ibest & sumbest */
   sumTemp=sumbest*5;
   speed=100000000;
   loopcounter=0;	Ni=0;               /*   initialize GunNum & Ni    */

   //printf("init success!!!\n");
}

void invert(int pos_start,int pos_end)
{ int j,k,t;
  if(pos_start<pos_end)
  {  j=pos_start+1; k=pos_end;
     for(;j<=k;j++,k--)
	 { t=temp[j]; temp[j]=temp[k]; temp[k]=t;  }
  }
  else
  {
	if(xCity-1-pos_start<=pos_end+1)
	{  j=pos_end;k=pos_start+1;
	   for(;k<xCity;j--,k++)
	   { t=temp[j];temp[j]=temp[k];temp[k]=t;   }
	   k=0;
	   for(;k<=j;k++,j--)
	   {  t=temp[j]; temp[j]=temp[k];temp[k]=t; }
    }
	else
	{  j=pos_end;k=pos_start+1;
	   for(;j>=0;j--,k++)
	   {  t=temp[j];temp[j]=temp[k];temp[k]=t;  }
       j=xCity-1;
	   for(;k<=j;k++,j--)
	   {  t=temp[j];temp[j]=temp[k]; temp[k]=t; }
    }
  }
}


int position(int *tmp,int C)
{ int j;
  for(j=0;j<xCity;j++)
  if(*(tmp+j)==C)break;
  return(j);
}

void tempTest(int i)
{  int j; double dt;
   for(j=0;j<xCity;j++)colony[i][j]=temp[j];
   if((int)sumbest>(int)dis_p[i])
   { sumbest=dis_p[i];ibest=i;Ni=0;
     timeNow=clock();
	 dt=(double)(timeNow-timeTemp)/CLOCKS_PER_SEC;;
     if(dt>0.1)
	 {  speed=(sumTemp-sumbest)/dt;
		sumTemp=sumbest;
		timeTemp=timeNow;
     }
	 //printf("\n%f   %4.2f  %10.1f",sumbest,(double)(timeNow-timeStart)/CLOCKS_PER_SEC,speed);
   }
}

void printBest(long GenNum,long Ni)
{
/*  int i;
  printf("\n   CITY      %d\t\tN_COLONY  %d",CITY,N_COLONY);
  printf("\n   maxGen    %d\t\ttime      %4.2f  seconds",MAXGEN,(double)(timeNow-timeStart)/CLOCKS_PER_SEC);
  //printf("\n   probab    %g\t\tdistance  %f",probab2,sumbest);
  printf("\n   GenNum    %d\t\tNo change %Ld\n\n",GenNum,Ni);
  for(i=0;i<xCity;i++)
  { if(i%10==0 && i!=0){ printf("\n");}
	printf("%5d",colony[ibest][i]+1);//no use
  }
  printf("\n\n");*/
  //printf("dhgkdhgkdh");by me
/*  if((fpme=fopen("result.txt","a"))==NULL)exit(0);
    fprintf(fpme,"\n   CITY      %d\t\tN_COLONY  %d",CITY,N_COLONY);
    fprintf(fpme,"\n   maxGen    %d\t\ttime      %4.2f  seconds",MAXGEN,(double)(timeNow-timeStart)/CLOCKS_PER_SEC);
    //fprintf(fpme,"\n   probab    %g\t\tdistance  %f",probab2,sumbest);
    fprintf(fpme,"\n   GenNum    %d\t\tNo change %Ld\n\n",GenNum,Ni);
  fclose(fpme);*/
  //printf("dhgkdhgkdh");by me
}


void mapped()
{ int start,end,i,j,k,kt,t,disPlace,kDC,kC;
  double temp_dis=0;
  i=rand()%xColony;
  j=rand()%xColony;
  if(i==j)return;
  if(dis_p[i]<dis_p[j])
  { t=i;i=j;j=t; }
  for(k=0;k<xCity;k++)temp[k]=colony[i][k];
  /////////////////

  start=rand()%xCity;
  end=(start+rand()%180+20)%xCity; //rand()%xCity;
  kt=position(temp,colony[j][start]);                //部分映射一二位同
  disPlace=kt-start;
  if(temp[(kt+1)%xCity]==colony[j][(start+1)%xCity])
  {
	if(start<end)
	 for(k=start;k<=end;k++)
     { kDC=(k+disPlace)%xCity;
	   if(temp[kDC]==colony[j][k])continue;
	   t=position(temp,colony[j][k]);
	   temp[t]=temp[kDC];
       temp[kDC]=colony[j][k];
     }
    else
	 for(k=start;k<=xCity+end;k++)
     { kDC=(k+disPlace)%xCity; kC=k%xCity;
	   if(temp[kDC]==colony[j][kC])continue;
	   t=position(temp,colony[j][kC]);
	   temp[t]=temp[kDC];
       temp[kDC]=colony[j][kC];
     }
  }
  else
  { if(temp[(kt-1+xCity)%xCity]==colony[j][(start+1)%xCity])
    { if(start<end)
	    for(k=kt=start;k<=end;k++,kt--)
		{ kDC=(kt+xCity+disPlace)%xCity;
		  if(temp[kDC]==colony[j][k])continue;
	      t=position(temp,colony[j][k]);
	      temp[t]=temp[kDC];
          temp[kDC]=colony[j][k];
		}
	  else
	    for(k=kt=start;k<=end+xCity;k++,kt--)
		{ kDC=(kt+xCity+disPlace)%xCity; kC=k%xCity;
		  if(temp[kDC]==colony[j][kC])continue;
	      t=position(temp,colony[j][kC]);
	      temp[t]=temp[kDC];
          temp[kDC]=colony[j][kC];
		}
    }
    else return;
  }
/*
  start=rand()%xCity;  end=rand()%xCity;             //部分映射找第一位同
  if(start>end){t=start;start=end;end=t;}
  disPlace=position(temp,colony[j][start])-start;
  for(k=start;k<=end;k++)
  { if(temp[(k+disPlace)%xCity]==colony[j][k])continue;
	t=position(temp,colony[j][k]);
	temp[t]=temp[(k+disPlace)%xCity];
    temp[(k+disPlace)%xCity]=colony[j][k];
  }

  start=rand()%(xCity/2);                         //部分映射  ////////////
  end=rand()%(xCity/2)+xCity/2;
  for(k=start;k<=end;k++)
  { if(temp[k]==colony[j][k])continue;
	t=position(temp,colony[j][k]);
	temp[t]=temp[k];
    temp[k]=colony[j][k];
  }
  */
  for(j=0;j<xCity-1;j++)
    temp_dis=temp_dis+city_dis[temp[j]][temp[j+1]];
  temp_dis=temp_dis+city_dis[temp[0]][temp[xCity-1]];
  dis_p[i]=temp_dis;
  /*********/
  tempTest(i);
}
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
void LastCP()
{ int i,k,j1,j2,k1,k2,turn,length,sign[CITY]; double dc,temp_dis=0,change=0;
  printf("+");
  for(k=0;k<xCity;k++)temp[k]=colony[ibest][k];//no use
  for(turn=0;turn<xCity/10;turn++)      //可改
  {   for(k1=0;k1<xCity-1;k1+=rand()%4+1)     // rand()%9+1可改
      {  for(i=1;i<xColony;i++)
	     {  if(i==ibest)continue;//no use
		    for(k=0;k<xCity;k++)sign[k]=0;
	        j1=position(colony[i],temp[k1]);
			k2=k1;j2=j1;
			for(length=0;length<xCity/2;length++)    // 70 xCity/3+10可改
			{  k2=(++k2)%xCity; j2=(++j2)%xCity;
			   sign[temp[k2]]=1;
			   if(temp[k2]==colony[i][j2] && length>1)break;  // 5 xCity/10可改
			}
            if(temp[k2]!=colony[i][j2])continue;
            k=j1;
            do k=(k+1)%xCity;
			while (sign[colony[i][k]]==1);
            if( (j1<j2 && k<j2) || (j1>j2 && (k>j1 || k<j2)) )continue;
		    temp_dis=path(temp,k1,k2);
		    dc=path(colony[i],j1,j2);
		    if(temp_dis>dc)
			{  for(k=1;k<=length;k++)
		         temp[(k1+k)%xCity]=colony[i][(j1+k)%xCity];
			   change+=dc-temp_dis;
			}
	     }
     }
  }
  if(change<0)
  {  for(k=0;k<xCity;k++)colony[ibest][k]=temp[k];//no use
     dis_p[ibest]+=change;//no use
	 sumbest=dis_p[ibest];//no use
     printf("\n%f  O K !!!",sumbest);
  }
}

double path(int tmp[],int k1,int k2)
{ 	int j,t1,t2; double temp_dis=0;
    if(k2>k1)
		for(j=k1;j<k2;j++)
			temp_dis+=city_dis[tmp[j]][tmp[j+1]];
    else
		for(j=k1;j<k2+xCity;j++)
		{   t1=j%xCity; t2=(j+1)%xCity;
		    temp_dis+=city_dis[tmp[t1]][tmp[t2]];
		}
	return temp_dis;
}
//***********************************************************************************
//**********************************************************************第一个功能实现
/*double standard()
{

   return (sumworst-sumbest)/sumworst;
}
int  Cross_over(int number)
{
	int C,C1,D,D1,k,m,mem,count,Flag=1;
	double change,differ,newdis;
	for(mem=0;mem<xCity;mem++)
		temp[mem]=colony[number][mem];    //首先进行复制
    k=rand()%xCity;                      //任选一个城市位置
	C=temp[k];
	C1=temp[(k+1)%xCity];
	if((rand()/32768.0)<probab)
	{
	   do
		{
			m=rand()%xCity;
		}while(m==k);
		D=temp[m];
		D1=temp[(m+1)%xCity];     //在同一个体内选择不同的城市
	}
	else                         //#####################可删
	{
	   do
		{
		D=next[C][rand()%Edge+1];  //此处是选择最近的几个城市之一
		}while(C1==D);
		m=position(temp,D);
		D1=temp[(m+1)%xCity];
	}

    invert(k,m);  //进行逆转操作
	change=city_dis[C][D]+city_dis[C1][D1]-city_dis[C][C1]-city_dis[D][D1];//计算变化的值
	differ=standard();   //计算标准值
	newdis=dis_p[number]+change;
	dis_p[number]=newdis;
	if(change<0||(change/newdis)<differ)   //比较能否接受
	{
		for(count=0;count<xCity;count++)
		{
	     if((int)newdis==(int)dis_p[count])//如果和原来的相同，说明结果仍不符合
		 Flag=0;
		}
		if(Flag)
		{

		tempTest(number);
		return 1;
		}
	}
	tempTest(number);
	return 0;



}
void check()    //逐个进行检查
{
  int num,j,k;
  for(num=0;num<N_COLONY;num++)
  {
	  for(j=num+1;j<N_COLONY;j++)
	  {
		  if((int)dis_p[j]==(int)dis_p[num])
			  for(k=0;k<3;k++)
			  {

				  if(Cross_over(j)==1)break;

			  }
	  }
  }

}*/
//***********************************************************************************××
//**********************************************************//第二个功能实现

int  change_same(int number)     //对相同的个体进行变异
{
	int C,C1,D,D1,k,m,mem,count;
	double change;
//***********************************************此处进行变异
	for(mem=0;mem<xCity;mem++)
		temp[mem]=colony[number][mem];    //首先进行复制
    k=rand()%xCity;                      //任选一个城市位置
	C=temp[k];
	C1=temp[(k+1)%xCity];

	do
	{
		m=rand()%xCity;
	}while(m==k);
	D=temp[m];
	D1=temp[(m+1)%xCity];     //在同一个体内选择不同的城市

    invert(k,m);  //进行逆转操作
	change=city_dis[C][D]+city_dis[C1][D1]-city_dis[C][C1]-city_dis[D][D1];//计算变化的值
	dis_p[number]+=change;
//************************************************变异结束
	for(count=0;count<number;count++)    //检查变异是否成功
		if((int)dis_p[number]==(int)dis_p[count])  //不成功
		{
			tempTest(number);
			return 0;     //返回0

		}

   tempTest(number);
	return 1;    //成功返回1
}

void differ()    //异化
{
	int mem,k,flag;
	for(mem=0;mem<N_COLONY-1;mem++)
	{
		flag=0;
		for(k=0;k<=mem;k++)
		{
		  if((int)dis_p[mem+1]==(int)dis_p[k])  //后面的和前面的进行比较，相同的话进行处理
			for(;;)
				{
				if(change_same(mem+1)==1) {flag=1;break;}  //变异直到符合条件为止

				}
			if(flag) break;
		}
	}
}
//******************************************************************************************************
//建立近邻矩阵 *************已删
/*void Next(void)
{
	int mem,j,k,m,temp;
	double a[CITY],t;

	for(mem=0;mem<xCity;mem++)
	{
		for(j=0;j<xCity;j++)
		{
			next[mem][j]=j;
			a[j]=city_dis[mem][j];
		}

		{
			for(k=1;k<xCity;k++)
				for(m=0;m<xCity-k;m++)
					if((int)a[m]>(int)a[m+1])
					{
						t=a[m];
						a[m]=a[m+1];
						a[m+1]=t;

						temp=next[mem][m];
						next[mem][m]=next[mem][m+1];
						next[mem][m+1]=temp;
					}
		}
	}
}*/
//*****************************************************************************
int in_mapped(int tmp[],double dis)  //bool
{
  int start,end,i,k,kt,t,disPlace,kDC,kC,m,flag,jian=0;
  //int count=0;
  double temp_dis=0,cmp;
  i=rand()%xColony;
  while ((int)dis_p[i]==(int)dis&&jian<=100)
  {
	i=(i+1)%xColony;
	jian++;

  } //while ((int)dis_p[i]==(int)dis);//

  /*if(i==j)return;
  if(dis_p[i]<dis_p[j])   // 需改动
  { t=i;i=j;j=t; }
  for(k=0;k<xCity;k++)temp[k]=colony[i][k];*/
  if(dis_p[i]<dis)
  {
	  for(k=0;k<xCity;k++) {temp[k]=tmp[k];tmp[k]=colony[i][k];cmp=dis_p[i];dis_p[i]=dis;dis=cmp;}
  }
  else
      for(k=0;k<xCity;k++)temp[k]=colony[i][k];
  /////////////////

  start=rand()%xCity;
  end=(start+rand()%180+20)%xCity; //rand()%xCity;
  kt=position(temp,tmp[start]);                //部分映射一二位同
  disPlace=kt-start;
  if(temp[(kt+1)%xCity]==tmp[(start+1)%xCity])
  {
	if(start<end)
	 for(k=start;k<=end;k++)
     { kDC=(k+disPlace)%xCity;
	   if(temp[kDC]==tmp[k])continue;
	   t=position(temp,tmp[k]);
	   temp[t]=temp[kDC];
       temp[kDC]=tmp[k];
     }
    else
	 for(k=start;k<=xCity+end;k++)
     { kDC=(k+disPlace)%xCity; kC=k%xCity;
	   if(temp[kDC]==tmp[kC])continue;
	   t=position(temp,tmp[kC]);
	   temp[t]=temp[kDC];
       temp[kDC]=tmp[kC];
     }
	 flag=1;
  }


  else
  { if(temp[(kt-1+xCity)%xCity]==tmp[(start+1)%xCity])
    { if(start<end)
	    for(k=kt=start;k<=end;k++,kt--)
		{ kDC=(kt+xCity+disPlace)%xCity;
		  if(temp[kDC]==tmp[k])continue;
	      t=position(temp,tmp[k]);
	      temp[t]=temp[kDC];
          temp[kDC]=tmp[k];
		}
	  else
	    for(k=kt=start;k<=end+xCity;k++,kt--)
		{ kDC=(kt+xCity+disPlace)%xCity; kC=k%xCity;
		  if(temp[kDC]==tmp[kC])continue;
	      t=position(temp,tmp[kC]);
	      temp[t]=temp[kDC];
          temp[kDC]=tmp[kC];
		}
	  flag=1;
    }


    else flag=0;
  }
/*
  start=rand()%xCity;  end=rand()%xCity;             /部分映射找第一位同
  if(start>end){t=start;start=end;end=t;}
  disPlace=position(temp,colony[j][start])-start;
  for(k=start;k<=end;k++)
  { if(temp[(k+disPlace)%xCity]==colony[j][k])continue;
	t=position(temp,colony[j][k]);
	temp[t]=temp[(k+disPlace)%xCity];
    temp[(k+disPlace)%xCity]=colony[j][k];
  }

  start=rand()%(xCity/2);                         //部分映射  ////////////
  end=rand()%(xCity/2)+xCity/2;
  for(k=start;k<=end;k++)
  { if(temp[k]==colony[j][k])continue;
	t=position(temp,colony[j][k]);
	temp[t]=temp[k];
    temp[k]=colony[j][k];
  }
  */
  if(flag==1)
  {
	  //printf("\n Success!!\n");
  for(m=0;m<xCity-1;m++)
  temp_dis=temp_dis+city_dis[temp[m]][temp[m+1]];
  temp_dis=temp_dis+city_dis[temp[0]][temp[xCity-1]];
  dis_p[i]=temp_dis;
  /*********/
	tttts=temp_dis;
  /*********/
  tempTest(i);

  }
  return flag;
/*  else {

			if(count>100)
				return;//这里要把问题解决。无返回值
			else
			{
				count++;
			in_mapped(tmp,dis);  //递归不成功，无法进行
			}
		}*/

}
/***************************************************/
int move_map(int tmp[],double dis,int same)
{
	int flag,k,i1,j1,count=0;
	//if(same==0||same==1&&dis!=dis_p[0])
	//{
		do
		{
		flag=in_mapped(tmp,dis);
		if(flag)
			return 1;
		count++;

		}while(count<=100);
		return 0;
	//}
	//else return 0;
	//return 0;
}
