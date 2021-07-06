//【例9.1】整型数输出。
#include<iostream>
using namespace std;
int main(void){
	int inum=255;
	cout<<"十进制方式"<<inum<<'\t';
	cout.flags(ios::oct|ios::showbase);//八进制带数制基输出是前面加0;参数等效0x00a0
	cout<<"八进制方式"<<inum<<'\t';
	cout.setf(ios::hex);               //等效0x0040,因是或关系,仍带基输出,格式为0x...
	cout<<"十六进制方式"<<inum<<endl;
	return 0;
}
