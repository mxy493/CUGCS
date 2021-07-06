//【例11.5】双端队列类与矢量类一样，有一个成员函数insert()，注意不是插入迭代子适配器函数insert()。
//本例演示该函数的使用，最后输出字符串：“STL功能强使用方便。”
#include<iostream>
#include<iterator>
#include<deque>
using namespace std;

typedef deque<char> char_deque;
void print_string(char_deque);
int main(){
	char arr1[]="功能强",arr2[]="使用方便。";
	char_deque  chdeq(arr1,arr1+6);
	print_string(chdeq);
	cout<<endl;
	chdeq.insert(chdeq.begin(),'L');            //逆序
	chdeq.insert(chdeq.begin(),'T');
	chdeq.insert(chdeq.begin(),'S');
	print_string(chdeq);
	cout<<endl;
	chdeq.insert(chdeq.end(),arr2,arr2+10);
	print_string(chdeq);
	cout<<endl;
	return 0;
}
void print_string(char_deque  deq){
	ostream_iterator<char>output(cout);
	cout<<"生成的字符串是：";
	copy(deq.begin(),deq.end(),output);
}
