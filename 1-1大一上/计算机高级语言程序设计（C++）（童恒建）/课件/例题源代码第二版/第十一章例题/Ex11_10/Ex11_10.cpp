//【例11.10】演示队列的入队和出队。
#include<iostream>
#include<queue>
using namespace std;

int main(){
const int size=10;
int i,ia[10]={0,1,2,3,4,5,6,7,8,9};
	queue<int> intque;
	for(i=0;i<size;i++) intque.push(ia[i]);
	while(intque.empty()==false){
		cout<< intque.front()<<'\t';
		intque.pop();
	}
	cout<<endl;
	return 0;
}
