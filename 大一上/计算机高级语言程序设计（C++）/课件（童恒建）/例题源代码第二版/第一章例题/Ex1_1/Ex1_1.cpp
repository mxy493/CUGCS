//【例1.1】一个简单的C++程序：输入两个整数，通过调用函数求两个数中的较大值。

# include <iostream>
using namespace std;
 
int max(int i, int j){  // 定义max()函数									
	if (i>=j) return i; 
	else return j;
}

int main(void){         //定义main()函数
	cout<<"输入i,j：";   						//显示提示信息
	int i, j;					     			//说明变量
	cin>>i>>j;								    //从键盘上输入变量的值
	cout<<"最大数是："<<max(i, j)<<'\n';		//输出提示信息和结果
	return 0;
}
