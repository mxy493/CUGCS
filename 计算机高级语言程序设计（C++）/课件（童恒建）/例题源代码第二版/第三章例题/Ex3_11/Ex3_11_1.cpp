//【例3.11】外部存储类型的例子。假定程序包含两个源程序文件Ex3_11_1.cpp和Ex3_11_2.cpp，程序结构如下：
/* Ex3_11_1.cpp ，由main()组成*/
# include <iostream>
using namespace std;

void fun2();				//外部函数声明，等价于extern void fun2();
int n;						//全局变量定义
int main(){
	n=1;
	fun2();					// fun2()定义在文件Ex3_11_2.cpp中
	cout<<"n="<<n<<endl;
	return 0;
}
