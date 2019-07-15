//【例5.4】已知矩阵 int mat[8][8]，找出其中的极点与鞍点。如某元素在所在行相邻点中与所在列
//相邻点中均为最大或最小，则为极点；如某元素在所在行（或列）相邻点中为最大，同时该元素在所
//在列（或行）相邻点中为最小，则为鞍点。
#include<iostream>
#include<iomanip>
using namespace std;

int mat[8][8]={0,3,5,7,11,13,17,19,1,2,3,9,16,17,21,18,3,5,4,14,22,19,26,15,5,11,9,6,16,15,
23,12,9,12,8,7,8,9,10,11,7,6,15,14,13,10,9,10,13,4,7,24,20,18,12,12,15,10,9,8,25,19,16,14};
int maxmin(int a,int b,int c){
	if(a>b&&b<c)  return -1;
	else if(a<b&&b>c) return 1;
	else return 0;//b为最大返回1 ，最小返-1，其他为0
}
int main (void){
	int i,j,k,l;
	for(i=1;i<=6;i++)
		for(j=1;j<=6;j++){
			k=maxmin(mat[i][j-1],mat[i][j],mat[i][j+1]);
			if(k==0)  continue;
			l=maxmin(mat[i-1][j],mat[i][j],mat[i+1][j]);
			if(l==0) continue;
			if(k==1&&l==1)
				cout<<"极大点："<<setw(2)<<mat[i][j]<<" ; i="<<i<<" ; j="<<j<<endl;
			else if(k==-1&&l==-1)
				cout<<"极小点："<<setw(2)<< mat[i][j]<<" ; i="<<i<<" ; j="<<j<<endl;
			else cout<<"鞍  点："<<setw(2)<<mat[i][j]<<" ; i="<<i<<" ; j="<<j<<endl;
		}
	return 0;
}
