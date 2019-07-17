//【例6.1】求数组元素中最大值的函数模板。
#include <iostream>
#include <string>
using namespace std; 
template <typename Groap>Groap max(const Groap *r_array,int size){
//这里const所放位置表示指针所指的对象不可改变，可防止误改了实参
	Groap max_val=r_array[0];
	for (int i=1;i<size; ++i)
		if(r_array[i]>max_val) max_val=r_array[i];
	return  max_val;
}
int ia[5]={10,7,14,3,25};
double da[6]={10.2,7.1,14.5,3.2,25.6,16.8};
string sa[5]={"上海","北京","沈阳","广州","武汉"};
int main() {
	int  i=max(ia,5);
	cout <<"整数最大值为："<<i<<endl;
	double  d=max(da,6);
	cout <<"实数最大值为："<<d<<endl;
	string  s=max(sa,5);
	cout <<"字典排序最大为："<<s<<endl;
	return 0;
}
