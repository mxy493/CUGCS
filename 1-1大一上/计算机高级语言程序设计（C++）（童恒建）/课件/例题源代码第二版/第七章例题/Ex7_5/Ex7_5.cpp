//【例7.5】由键盘输入16个整数，以这些整数作为结点数据，生成两个链表，一个向前生成，
//一个向后生成，输出两个表。然后给出一个整数在一个链表中查找，找到后删除它，再输出
//该表。清空该表，再按升序生成链表并输出。
#include "Ex7_5.h"

int main(){
	const int N =6;  // thj: 16 --> N; 
	Node<int> * P1;
	List<int> list1,list2;
	int a[N],i,j;
	cout<<"请输入N个整数"<<endl;
	for(i=0;i<N;i++)cin>>a[i];                   //随机输入N个整数
	for(i=0;i<N;i++){
		P1=list1.CreatNode(a[i]);
		list1.InsertFront(P1);//向前生成list1
		P1=list2.CreatNode(a[i]);
		list2.InsertRear(P1);                        //向后生成list2
	}
	list1.PrintList();
	cout<<"list1长度："<<list1.Length()<<endl;
	list2.PrintList();
	cout<<"请输入一个要求删除的整数"<<endl;
	cin>>j;
	P1=list1.Find(j);
	if(P1!=NULL){
		P1=list1.DeleteNode(P1);
		delete P1;
		list1.PrintList();
		cout<<"list1长度："<<list1.Length()<<endl; 
	}
	else cout<<"未找到"<<endl;
	list1.MakeEmpty();//清空list1
	for(i=0;i<N;i++){
		P1=list1.CreatNode(a[i]);
		list1.InsertOrder(P1);//升序创建list1
	}
	list1.PrintList();
	return 0;
}
