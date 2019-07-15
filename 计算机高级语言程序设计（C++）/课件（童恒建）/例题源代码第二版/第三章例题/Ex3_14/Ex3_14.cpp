/*【例3.14】输入一个整数，用递归的算法实现将整数倒序输出。
分析：在递归过程的递推步骤中用求余运算将整数的各个位分离，并打印出来。*/
#include<iostream>
using namespace std;

void backward(int);
int main(){
	int n;
	cout<<"输入整数："<<endl;
	cin>>n;
	cout<<"原整数："<<n<<endl;
	cout<<"反向数：";
	backward(n);
	cout<<endl;
	return 0;
}
void backward(int n){
	cout<<n%10;
	if(n<10) return; 
	else backward(n/10);
}
