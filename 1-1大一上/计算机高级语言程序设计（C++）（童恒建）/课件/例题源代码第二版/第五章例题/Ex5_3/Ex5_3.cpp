//【例5.3】八皇后问题：在8×8的国际象棋棋盘上安放八个皇后，为避免她们之间相互攻击，
//要求没有任何两个皇后在棋盘的同一行、同一列及在同一对角线上。
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int queen[8];
	int total = 0;      //方案计数
	int i, j, k;
	for (i=0;i<8;i++)  queen[i] = 0;           //八皇后全放在第0列
	for (i=1;;){                               //首先安放第0行皇后
		if(queen[i]<8){                          //皇后还可调整
			k=0;                                   //检查与第k个皇后是否互相攻击
			while(k<i&&(queen[k]-queen[i])&&(abs(queen[k]-queen[i])-abs(k-i)))  k++;
			if (k<=i-1){                           //与第k个皇后互相攻击
				queen[i]++;                          //第i个皇后右移一列，重测
				continue;
			}
			i++;                                   //无冲突，安置下一行皇后
			if(i<8) continue;
			for(j=0;j<8;j++) cout<<queen[j];       //已完成，输出结果
			cout<<"  ";
			total++;                               //方案数加1
			if(total%5==0) cout<<endl;
			queen[7]++;                            // 将第7个皇后右移一列，前7个不动
			i=7;                           //此处是制造机会，如不成功则回溯，关键一步
		}
		else                                     //当前行皇后无法安置，回溯
		{
			queen[i]=0;                            //当前行皇后回归0列
			i--;                                   //回溯到前一行皇后
			if(i<0){                               //回溯到数组0行之前，结束
				cout<<" 总数:"<<total<<endl;
				return 0;
			}
			else queen[i]++;             //前一行皇后右移一列
		}
	}
}
