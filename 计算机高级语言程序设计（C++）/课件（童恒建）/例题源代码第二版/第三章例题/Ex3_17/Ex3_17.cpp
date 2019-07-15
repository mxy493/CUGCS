//【例3.17】缺省参数。
#include<iostream>
using namespace std;
void delay(int loops=1000){		//延时函数,默认延时1000个时间单位
	for (; loops>0; loops--); 
}
int main(){
	delay(100);
	cout<<"延时100个时间单位"<<endl;
	delay();							//等同于delay(1000)
	cout<<"延时1000个时间单位"<<endl;
	return 0;
}
