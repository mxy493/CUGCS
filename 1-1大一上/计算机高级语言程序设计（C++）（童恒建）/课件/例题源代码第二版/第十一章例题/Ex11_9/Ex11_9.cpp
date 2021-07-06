//【例11.9】演示堆栈的压入和弹出。
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
const int size=10;
int i,ia[10]={0,1,2,3,4,5,6,7,8,9};
	stack<int,vector<int> > intvestack;
	for(i=0;i<size;i++) intvestack.push(ia[i]);
	while(intvestack.empty()==false){
		cout<< intvestack.top()<<'\t';
		intvestack.pop();
	}
	cout<<endl;
	return 0;
}
