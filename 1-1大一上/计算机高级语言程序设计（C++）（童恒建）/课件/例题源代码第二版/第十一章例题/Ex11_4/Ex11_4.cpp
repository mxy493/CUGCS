//����11.4��չʾ�б��������������������
#include<iostream>
#include<iterator>
#include<list>
using namespace std;

int main(){
	int i;
	list<int> list1,list2;
	list<int>::iterator iter;       //iter��list�õĵ����ӣ��Զ���Ϊ˫����ʵ�����
	int arr1[]={5,7,17,19,23,43};
	int arr2[]={3,9,13,29,41};
	for(i=0;i<6;i++)  list1.push_back(arr1[i]);
	for(i=0;i<5;i++)  list2.push_front(arr2[i]);
	for(iter=list1.begin();iter!=list1.end();iter++)  cout<<*iter<<'\t'; //���5,7,17,19,23,43
	cout<<endl;
	for(iter=list2.begin();iter!=list2.end();iter++)  cout<<*iter<<'\t'; //���41,29,13,9,3
	cout<<endl;
	list2.reverse();                               //��תΪ3,9,13,29,41
	list1.merge(list2);                           //list2�鲢��list1,��ʽȱʡΪ����
	while(!list1.empty()){                        //��ս���
		cout<<list1.front()<<'\t';     //������ͷһ����3,5,7,9,13,17,19,23,29,41,43
		list1.pop_front();                        //��������ɾȥһ��
	}
	cout<<endl;
	return 0;
}
