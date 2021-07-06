//����8.10��ͨ�õ����������ࡣ���ȸ��졾��7.4����ͷ�ļ���������ģ���࣬
//�������麯��ʵ�ֶ�̬�ԣ��ﵽͨ�õ�Ŀ�ġ�
#include "Ex8_10.h"
#include<string>
using namespace std;

class StringObject:public Object{
	string sptr;
public:
	StringObject();
	StringObject(string);
	~StringObject();
	bool operator>(Object &);
	bool operator!=(Object &);
	void Print();
};
StringObject::StringObject(){sptr="";}
StringObject::StringObject(string s){sptr=s;}
StringObject::~StringObject(){cout<<"����������"<<endl;} //�Զ���һ������string��������
bool StringObject::operator>(Object & obj){//�麯��
	StringObject & temp=(StringObject &)obj;//����ת��
	return sptr>temp.sptr;
}
bool StringObject::operator!=(Object & obj){//�麯��
	StringObject & temp=(StringObject &)obj;//����ת��
	return sptr!=temp.sptr;
}
void StringObject::Print(){cout<<sptr<<'\t';}//�麯��

int main(){
	Node * P1;
	StringObject* p;
	List list1,list2,list3;
	char *a[5]={"dog","cat","bear","sheep","ox"},*sp="cat";
	int i;
	for(i=0;i<5;i++){
		p=new StringObject(a[i]);              //�������ݶ���
		P1=list1.CreatNode();                  //�������
		P1->Linkinfo(p);                       //���ݶ������ӵ����
		list1.InsertFront(P1);                 //��ǰ����list1
		p=new StringObject(a[i]);              //����Node�������������ͷ�
		P1=list2.CreatNode();
		P1->Linkinfo(p);
		list2.InsertRear(P1);                  //�������list2
	}
	list1.PrintList();
	cout<<"list1���ȣ�"<<list1.Length()<<endl;
	list2.PrintList();
	cout<<"Ҫ��ɾ�����ַ���\"cat\""<<endl;
	p=new StringObject(sp);                    //Ϊ�˳����ͨ����ֻ�ܶ�һ��ת��
	P1=list1.Find(*p);
	delete p;
	if(P1!=NULL){
		cout<<"ɾ��cat"<<endl;
		P1=list1.DeleteNode(P1);
		delete P1;
		list1.PrintList();
		cout<<"list1���ȣ�"<<list1.Length()<<endl; 
	}
	else cout<<"δ�ҵ�"<<endl;
	cout<<"���list1"<<endl;
	list1.MakeEmpty();                         //���list1
	list1.PrintList();
	for(i=0;i<5;i++){
		p=new StringObject(a[i]);
		P1=list3.CreatNode();
		P1->Linkinfo(p);
		list3.InsertOrder(P1);//���򴴽�list3
	}
	list3.PrintList();
	cout<<"�������"<<endl;
	return 0;
}
