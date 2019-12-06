//【例2.25】将百鸡问题计算结果存入文件。

#include<fstream>
#include<iomanip>
using namespace std;
int main(){
	int i,j,k;
	ofstream ofile;               //定义输出文件
	ofile.open("d:\\myfile.txt");     //作为输出文件打开
	ofile<<"   公鸡      母鸡      小鸡"<<endl;   //标题写入文件
	for(i=0;i<=20;i++)
		for(j=0;j<=33;j++){
			k=100-i-j;
			if((5*i+3*j+k/3==100)&&(k%3==0))			//注意(k%3==0)非常重要
			ofile<<setw(6)<<i<<setw(10)<<j<<setw(10)<<k<<endl;   //数据写入文件
		}
	ofile.close();                //关闭文件
	return 0;
}
