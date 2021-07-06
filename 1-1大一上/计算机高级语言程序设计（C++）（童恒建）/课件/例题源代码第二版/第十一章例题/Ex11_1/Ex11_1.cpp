//【例11.1】寻找数组元素。
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
	int search_value,ia[9]={47,29,37,23,11,7,5,31,41};
	cout<<"请输入需搜索的数："<<endl;
	cin>>search_value;
	int* presult=find(&ia[0],&ia[9],search_value);
	cout<<"数值"<<search_value<<(presult==&ia[9] ?"不存在":"存在")<<endl;
	return 0;
}
