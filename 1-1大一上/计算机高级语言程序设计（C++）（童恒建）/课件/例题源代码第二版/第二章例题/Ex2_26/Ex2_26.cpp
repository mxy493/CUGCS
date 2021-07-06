//【例2.26】读出存放百鸡问题计算结果的文件。

#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	char a[28];
	ifstream ifile;               //定义输入文件
	ifile.open("d:\\myfile.txt");     //作为输入文件打开
	int i=0,j,k;
	while(ifile.get(a[i])){      //读标题,请对比cin.get(),不可用>>,它不能读白字符
		if(a[i]=='\n') break;
		i++;
	}
	a[i]='\0';
	cout<<a<<endl;
	while(1){
		ifile>>i>>j>>k;                                 //由文件读入数据
		if(ifile.eof()!=0) break;            //当读到文件结束时，ifile.eof()为真
		cout<<setw(6)<<i<<setw(10)<<j<<setw(10)<<k<<endl;     //屏幕显示	    
	}
	ifile.close();                 //关闭文件
	return 0;
}
