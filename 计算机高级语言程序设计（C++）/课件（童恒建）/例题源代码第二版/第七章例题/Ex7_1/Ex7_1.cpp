//【例7.1】动态数组的建立与撤销。
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	char *pc;
	cout<<"请输入动态数组的元素个数"<<endl;
	cin>>n;
	pc=new char[n];  //申请包含25个字符（可装12个汉字和一个结束符）元素的内存空间
	strcpy(pc,"自由存储区内存的动态分配");
	cout<<pc<<endl;
	delete []pc;           // 撤销并释放pc所指向的n个字符的内存空间
	return 0;
}

