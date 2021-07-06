//����6.9��ֱ��ѡ��������ΪOrderedlist<T,size>��ĳ�Ա������
#include<iostream>
#include<string>
using namespace std;

template <typename T,int size>class Orderedlist{
	int maxsize;
	int last;
	T slist[size];
public:
	Orderedlist(){last=-1;maxsize=size;}
	void SelectSort();
	bool Insert(T & elem,int i);
	void print();
	// �޹س�Ա����ʡ��
};//�ٴ�ָ���ֺŲ�����
template <typename T,int size> bool Orderedlist<T,size>::Insert(T & elem ,int i){
	int j;
	if (i<0||i>last+1||last==maxsize-1) return false;
	else{
		last++;
		for (j=last;j>i;j--) slist[j]=slist[j-1];
		slist[i]=elem;
		return true;
	}
}
template <typename T,int size> void Orderedlist<T,size>::print(){
	int i;
	for(i=0;i<=last;i++){
		slist[i].show();
		if(i%5==4) cout<<endl;
	}
	cout<<endl;
}
template <typename T,int size> void Orderedlist<T,size>::SelectSort(){
	int i,j,k;
	T temp;
	for(i=0;i<last;i++){
		k=i;
		temp=slist[i];
		for(j=i;j<=last;j++)
			if(slist[j]<temp){
				k=j;
				temp=slist[j];
			}
		if(k!=i){
			temp=slist[i];
			slist[i]=slist[k];
			slist[k]=temp;
		}
	}
}
class  student{
	int   id ;           //ѧ��
	string name;         // ����
	char  sex;          // �Ա�
	int   age;          // ����
	string  address;      //��ͥ��ַ
	float  eng, phy, math, electron;     //Ӣ�������ѧ�͵���ѧ�ɼ�
public:
	student(){}
	student(int,string,char,int,string,float,float,float,float);
	bool operator<(student ele){return id<ele.id;}
	void show(){cout<<id<<'\t'<<name<<'\t'<<sex<<'\t'<<age<<'\t'
		<<eng<<'\t'<<phy<<'\t'<<math<<'\t'<<electron<<endl;}
};
student::student(int i,string n,char s,int a,string add,float en,float ph,float ma,float ele){
	id=i;           //ѧ��
	name=n;         // ����
	sex=s;          // �Ա�
	age=a;          // ����
	address=add;      //��ͥ��ַ
	eng=en; phy=ph; math=ma, electron=ele;     //Ӣ�������ѧ�͵���ѧ�ɼ�

}

int main(){
	const int h=4;
	int i;
	Orderedlist<student,100> ordlist;
	student n[h]={student(6004327,"�ŷ�",'m',19,"����·58��",80,85,90,78),
		student(6004121,"����",'w',19,"���·64��",88,75,91,68),
		student(6004118,"����",'w',18,"�Ϻ�·37��",78,95,81,88),
		student(6004219,"����",'m',18,"����·95��",78,95,81,88),
	};
	for(i=0;i<h;i++)  ordlist.Insert(n[i],i); //����˳���
	cout<<"δ�����"<<endl;
	ordlist.print();
	ordlist.SelectSort();
	cout<<"�������"<<endl;
	ordlist.print();
	return 0;
}


