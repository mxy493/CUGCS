//����7.5���ɼ�������16������������Щ������Ϊ������ݣ�������������һ����ǰ���ɣ�
//һ��������ɣ����������Ȼ�����һ��������һ�������в��ң��ҵ���ɾ�����������
//�ñ���ոñ��ٰ������������������
#include "Ex7_5.h"

int main(){
	const int N =6;  // thj: 16 --> N; 
	Node<int> * P1;
	List<int> list1,list2;
	int a[N],i,j;
	cout<<"������N������"<<endl;
	for(i=0;i<N;i++)cin>>a[i];                   //�������N������
	for(i=0;i<N;i++){
		P1=list1.CreatNode(a[i]);
		list1.InsertFront(P1);//��ǰ����list1
		P1=list2.CreatNode(a[i]);
		list2.InsertRear(P1);                        //�������list2
	}
	list1.PrintList();
	cout<<"list1���ȣ�"<<list1.Length()<<endl;
	list2.PrintList();
	cout<<"������һ��Ҫ��ɾ��������"<<endl;
	cin>>j;
	P1=list1.Find(j);
	if(P1!=NULL){
		P1=list1.DeleteNode(P1);
		delete P1;
		list1.PrintList();
		cout<<"list1���ȣ�"<<list1.Length()<<endl; 
	}
	else cout<<"δ�ҵ�"<<endl;
	list1.MakeEmpty();//���list1
	for(i=0;i<N;i++){
		P1=list1.CreatNode(a[i]);
		list1.InsertOrder(P1);//���򴴽�list1
	}
	list1.PrintList();
	return 0;
}
