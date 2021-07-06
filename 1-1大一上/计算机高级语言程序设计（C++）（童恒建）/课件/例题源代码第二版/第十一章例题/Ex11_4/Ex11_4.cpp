//【例11.4】展示列表类怎样进行链表操作。
#include<iostream>
#include<iterator>
#include<list>
using namespace std;

int main(){
	int i;
	list<int> list1,list2;
	list<int>::iterator iter;       //iter是list用的迭代子，自动建为双向访问迭代子
	int arr1[]={5,7,17,19,23,43};
	int arr2[]={3,9,13,29,41};
	for(i=0;i<6;i++)  list1.push_back(arr1[i]);
	for(i=0;i<5;i++)  list2.push_front(arr2[i]);
	for(iter=list1.begin();iter!=list1.end();iter++)  cout<<*iter<<'\t'; //输出5,7,17,19,23,43
	cout<<endl;
	for(iter=list2.begin();iter!=list2.end();iter++)  cout<<*iter<<'\t'; //输出41,29,13,9,3
	cout<<endl;
	list2.reverse();                               //反转为3,9,13,29,41
	list1.merge(list2);                           //list2归并到list1,方式缺省为升序
	while(!list1.empty()){                        //表空结束
		cout<<list1.front()<<'\t';     //读链表头一项，输出3,5,7,9,13,17,19,23,29,41,43
		list1.pop_front();                        //从链表首删去一项
	}
	cout<<endl;
	return 0;
}
