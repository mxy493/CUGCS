//【例11.11】优先级队列类演示，头文件用<queue>，优先级用数表示，数值越大优先级越高。
#include<iostream>
#include<queue>
#include<functional>
using namespace std;

void main(){
	priority_queue<int> prioque;
	//实例化存放int值的优先级队列，并用deque作为基础数据结构
	prioque.push(7);//压入优先级队列
	prioque.push(12);
	prioque.push(9);
	prioque.push(18);
	cout<<"从优先级队列中弹出"<<endl;
	while(!prioque.empty()){
		cout<<prioque.top()<<'\t';//取最高优先级数据
		prioque.pop();//弹出最高优先级数据
	}
	cout<<endl;
}
