#include<iostream>  
#include<iomanip>                 
using namespace std;
enum ZHUANGTAI { kongxian, zhanyong }; 
struct distrabuteArea {  
	int qishidizhi;               
    int daxiao;              
    int zuoyehao;             
    ZHUANGTAI state;            // 分区状态
    distrabuteArea *pre;       // 分区前向指针
    distrabuteArea *nxt;       // 分区后向指针
}disHead; 

void intdisArea() 
{  
//分配初始分区内存
	distrabuteArea *fir = (distrabuteArea *)malloc(sizeof(distrabuteArea)); 
    // 给首个分区赋值
    fir->qishidizhi   = 0; 
    fir->daxiao   = 512; 
    fir->state  = kongxian; 
    fir->zuoyehao = -1;  
    fir->pre    = &disHead; 
    fir->nxt    = NULL; 
    // 初始化分区头部信息
    disHead.pre = NULL; 
    disHead.nxt = fir; 
} 


int shoucishiying(int zuoyehao, int daxiao) 
{  
    distrabuteArea *p = disHead.nxt; 
    while(p != NULL) 
    {  
        if(p->state == kongxian && p->daxiao >= daxiao) { 
        // 找到要分配的空闲分区
		{  
        // 分配大小为daxiao的区间
                distrabuteArea *node = (distrabuteArea *)malloc(sizeof(distrabuteArea));  
                node->qishidizhi = p->qishidizhi + daxiao; 
                node->daxiao = p->daxiao - daxiao; 
                node->state = kongxian; 
                node->zuoyehao = -1; 
                // 修改分区链节点指针
                node->pre = p;  
                node->nxt = p->nxt; 
                if(p->nxt != NULL) { 
                    p->nxt->pre  = node; 
                }  
                p->nxt = node; 
                // 分配空闲区间
                p->daxiao = daxiao; 
                p->state = zhanyong; 
                p->zuoyehao = zuoyehao;  

				}  
            cout<<"分配成功"<<endl; 
            return 1; 
        }  
        p = p->nxt; 
    }  
    cout<<"找不到合适的内存分区，分配失败"<<endl; 
    return 0; 
} 

int zuijia(int zuoyehao, int daxiao) 
{  
    distrabuteArea *tar = NULL; 
    int tarSize = 512 + 1;  
    distrabuteArea *p = disHead.nxt; 
    while(p != NULL) 
    {  
       // 寻找最佳空闲区间
        if(p->state == kongxian && p->daxiao >= daxiao && p->daxiao < tarSize) { 
            tar = p;  
            tarSize = p->daxiao; 
        }  
        p = p->nxt; 
    }  

    if(tar != NULL) {  
        // 找到要分配的空闲分区
	{  
                // 分配大小为daxiao的区间
                distrabuteArea *node = (distrabuteArea *)malloc(sizeof(distrabuteArea));  
                node->qishidizhi = tar->qishidizhi + daxiao; 
                node->daxiao = tar->daxiao - daxiao; 
                node->state = kongxian; 
                node->zuoyehao = -1; 
                // 修改分区链节点指针
                node->pre = tar;  
                node->nxt = tar->nxt; 
                if(tar->nxt != NULL) { 
                    tar->nxt->pre  = node;  
                }  
                tar->nxt = node; 
                // 分配空闲区间
                tar->daxiao = daxiao; 
                tar->state = zhanyong; 
                tar->zuoyehao = zuoyehao; 
            }  
            cout<<"分配成功"<<endl; 
            return 1; 
    } else {  
        cout<<"找不到合适的内存分区，分配失败"<<endl; 
        return 0; 
    } 
} 

int zuihuai(int zuoyehao, int daxiao)
{
    distrabuteArea *tar = NULL; 
    int tarSize = 512 + 1;  
    distrabuteArea *p = disHead.nxt; 
	while(p != NULL) 
    {  
       // 寻找最大空闲区间
        int tempsize;
        if(p->state == kongxian && p->daxiao >=tempsize) { 
			 tar = p;  
             tarSize = p->daxiao;
             tempsize=p->daxiao; 
        }  
        p = p->nxt; 
	} 
	if(tar != NULL && tarSize>=daxiao) {  
        // 找到要分配的空闲分区
	{  
                // 分配大小为daxiao的区间
                distrabuteArea *node = (distrabuteArea *)malloc(sizeof(distrabuteArea));  
                node->qishidizhi = tar->qishidizhi + daxiao; 
                node->daxiao = tar->daxiao - daxiao; 
                node->state = kongxian; 
                node->zuoyehao = -1; 
                // 修改分区链节点指针
                node->pre = tar;  
                node->nxt = tar->nxt; 
                if(tar->nxt != NULL) { 
                    tar->nxt->pre  = node;  
                }  
                tar->nxt = node; 
                // 分配空闲区间
                tar->daxiao = daxiao; 
                tar->state = zhanyong; 
                tar->zuoyehao = zuoyehao; 
            }  
            cout<<"分配成功"<<endl; 
            return 1; 
    } else {  
        cout<<"找不到合适的内存分区，分配失败"<<endl; 
        return 0; 
    } 
}

int neicunhuishou(int zuoyehao) 
{  
    int flag = 0;  
    distrabuteArea *p = disHead.nxt, *pp; 
    while(p != NULL) 
    {  
        if(p->state == zhanyong && p->zuoyehao == zuoyehao) { 
            flag = 1;  
            if((p->pre != &disHead && p->pre->state == kongxian)  
                && (p->nxt != NULL && p->nxt->state == kongxian)) { 
                // 上下都是空闲分区
                // 先合并上区间
                pp = p; 
                p = p->pre;  
                p->daxiao =p->daxiao+ pp->daxiao; 
                p->nxt = pp->nxt; 
                pp->nxt->pre = p; 
                free(pp);  
                // 后合并下区间
                pp = p->nxt;  
                p->daxiao = p->daxiao+pp->daxiao; 
                p->nxt = pp->nxt; 
                if(pp->nxt != NULL) { 
                    pp->nxt->pre = p; 
                }  
                free(pp);  
            } else if((p->pre == &disHead || p->pre->state == zhanyong)  
                && (p->nxt != NULL && p->nxt->state == kongxian)) { 
                // 下面是空闲分区
                pp = p->nxt;  
                p->daxiao =p->daxiao +pp->daxiao; 
                p->state = kongxian; 
                p->zuoyehao = -1; 
                p->nxt = pp->nxt; 
                if(pp->nxt != NULL) { 
                    pp->nxt->pre = p; 
                }  
                free(pp);  
            } else if((p->pre != &disHead && p->pre->state == kongxian) 
                && (p->nxt == NULL || p->nxt->state == zhanyong)) { 
                // 上面是空闲分区
                pp = p; 
                p = p->pre;  
                p->daxiao = p->daxiao+pp->daxiao; 
                p->nxt = pp->nxt; 
                if(pp->nxt != NULL) { 
                    pp->nxt->pre = p; 
                }  
                free(pp); 
            } else {  
                // 上下都是占用分区
                p->state = kongxian; 
                p->zuoyehao = -1; 
            } 
        }  
        p = p->nxt; 
    }  
    if(flag == 1) { 
        cout<<"回收成功"<<endl; 
        return 1; 
    } else {  
        cout<<"没有目标作业"<<endl; 
        return 0; 
    } 
} 


void xianshi() 
{  
    cout<<"当前的内存分配情况如下："<<endl; 
    cout<<endl;  
    cout<<"起始地址"<<" "<<"空间大小"<<" "<<"工作状态"<<"         "<<"作业号"<<endl; 
    distrabuteArea *p = disHead.nxt; 
    while(p != NULL) 
    {  
        cout<<endl;  
        cout<<p->qishidizhi<<'\t'; 
        cout<<p->daxiao<<'\t';  
        printf("%s \t        ", p->state == kongxian ? "kongxian" : "zhanyong"); 
        if(p->zuoyehao > 0) {  
            cout<<p->zuoyehao; 
        } else {  
            cout<<"        "; 
        }  
        cout<<endl;  
        p = p->nxt; 
    } 
} 

int main() 
{  
    int option, ope, zuoyehao, daxiao; 
    intdisArea(); 
    while(1) 
    {  
		cout<<"0.首次适应算法"<<endl;
		cout<<"1.最佳适应算法"<<endl;
		cout<<"2.最坏适应算法"<<endl;  
        cin>>option; 
        if(option == 0) {  
            cout<<"首次适应算法"<<endl; 
            break;  
        } else if(option == 1) {  
            cout<<"最佳适应算法"<<endl; 
            break; 
        } else if(option == 2){
			cout<<"最坏适应算法"<<endl;
			break;
		}
		else {  
            cout<<"错误：请输入 0/1"<<endl; 
        } 
    }  
    while(1) 
    {  
        cout<<endl;   
        cout<<"  1: 申请分区       2: 释放分区       0: 退出"<<endl;  
        cin>>ope; 
        if(ope == 0) break; 
        if(ope == 1) {  
            cout<<"请输入作业号："<<endl; 
            cin>>zuoyehao;  
            cout<<"请输入作业申请的内存大小："<<endl; 
			int size0;
            cin>>size0;
			daxiao=size0+1;
            if(daxiao <= 0) {  
                cout<<"错误：分配内存大小必须为正值"<<endl; 
                continue; 
            }  
            if(option == 0) {  
                shoucishiying(zuoyehao, daxiao); 
            } else if(option ==1){  
                zuijia(zuoyehao, daxiao); 
            }  else{
				zuihuai(zuoyehao, daxiao);
			}
            xianshi(); 
        } else if(ope == 2) { 
            cout<<"请输入要回收的作业号："<<endl; 
            cin>>zuoyehao; 
            neicunhuishou(zuoyehao); 
            xianshi(); 
        } else {  
            cout<<"输入错误"<<endl; 
        } 
    }  
    cout<<"结束"<<endl; 
    return 0; 
} 


 
