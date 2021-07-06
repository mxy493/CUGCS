//����9.13�����̵�Ļ������Ϊһ�����������ࡣ�������̬��������ʼΪ2��Ԫ�أ�
//������ʱ����һ�������ı������ļ���������Ԫ�ض���Ҫ����ڹ��캯���У������ݵ�
//������ļ��Ĺرշ������������С���һ������ʱ�������յ������ļ����ɼ������뽨��
//����Ԫ�ض��󣬲�д���ļ��������˳�ʱ���ر��ļ�����һ�������ɸ��ļ�������󣬻�
//��ǰһ�������Ĺ�����
#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class inventory{
	string Description;//��Ʒ����
	string No;//����
	int Quantity;//����
	double Cost;//�۸�
	double Retail;//����
public:
	inventory(string ="#",string="#",int =0,double =0,double =0);
	friend ostream&operator<<(ostream&dist,inventory&iv);//���ز��������
	friend istream&operator>>(istream&sour,inventory&iv);//������ȡ�����
	bool operator==(inventory &);//����Ϊ�ؼ���
	bool operator<=(inventory &);
};
inventory::inventory(string des,string no,int quan,double cost,double ret){
	Description=des;
	No=no;
	Quantity=quan;
	Cost=cost;
	Retail=ret;
}
ostream &operator<<(ostream&dist,inventory&iv){
	dist<<left<<setw(20)<<iv.Description<<setw(10)<<iv.No;
	dist<<right<<setw(10)<<iv.Quantity<<setw(10)<<iv.Cost<<setw(10)<<iv.Retail<<endl;
	return dist;
}
istream&operator>>(istream&sour,inventory&iv){     //�ļ�������Ϊ��ʽ��������������
	if(sour==cin){
		cout<<"������������ƣ�"<<endl;
		sour>>iv.Description;
		cout<<"��������ţ�"<<endl;
		sour>>iv.No;
		cout<<"���������������"<<endl;
		sour>>iv.Quantity;
		cout<<"���������۸�"<<endl;
		sour>>iv.Cost;
		cout<<"������������ۼ۸�"<<endl;
		sour>>iv.Retail;
	}
	else sour>>iv.Description>>iv.No>>iv.Quantity>>iv.Cost>>iv.Retail;
	return sour;
}
bool inventory::operator==(inventory & inven){
	return No==inven.No;
}
bool inventory::operator<=(inventory & inven){//Ϊ�������������ع�ϵ�����
	return No<=inven.No;
}
template <typename T>class Array{
	T *elements;
	int Subscript;           //��������±�ֵ
	int maxSize;
	fstream datafile;
public:
	Array(int=2);           //Ϊ�˱��ڼ���,ȱʡԪ������Ϊ2
	~Array();
	bool IsFull() const{return Subscript==maxSize-1;}
	void renews();         //�ڴ�����һ��
	void show(){
		cout<<"��������±�ֵ"<<Subscript<<'\t'<<"����Ԫ����"<<maxSize<<endl;
	}
	void ordinsert(T&);    //����ʱ�Ի���Ϊ�ؼ�������
	friend ostream&operator<<(ostream&dist,Array&ar);//���ز��������
};
template <typename T> Array<T>::Array(int maxs){
	maxSize=maxs;
	Subscript=-1;//˽�����ݲ�����ֱ�Ӹ���ֵ,�����ڹ��캯���и���ֵ
	T temp;
	elements=new T[maxSize];
	datafile.open("mydatafile.txt",ios::in);          //���ļ������ڣ���ʧ��
	if(!datafile==0){
		while(!datafile.eof()){
			datafile>>temp;
			if(datafile.eof()==0){//���������ݿɶ���,�����벻�ɹ�,eofbitΪ1
				ordinsert(temp);//��ʹԭ�ļ�δ���򣬶���Ҳ���ź���ģ��˳�ʱ���ź�����ش�
			}
		}
		datafile.close();//����Ŵ˴����򿪳ɹ����ܹر�
	}
	datafile.clear(0);//���ñ�׼�ⲻ���٣�ǰ�����������ļ��������ļ���ʧ�ܣ����޷��ָ�
}
template <typename T> Array<T>::~Array(){
	int i;
	datafile.open("mydatafile.txt",ios::out);
	for(i=0;i<=Subscript;i++) datafile<<elements[i];
	datafile.close();
	delete[]elements;
}
template <typename T> void Array<T>::renews(){
	int i;	
	T *temp=elements;
	maxSize*=2;
	elements=new T[maxSize];
	for(i=0;i<=Subscript;i++) elements[i]=temp[i];
	delete[]temp;
}
template <typename T> void Array<T>::ordinsert(T & elem){//����ʱ�Ի���Ϊ�ؼ�������
	int i,j;
	if(IsFull()) renews();
	for(i=0;i<=Subscript;i++) if(elem<=elements[i]) break;
	if(!(elem==elements[i])){
		for(j=Subscript;j>=i;j--) elements[j+1]=elements[j];
		Subscript++;
	}
	elements[i]=elem;
	show();
}
template <typename T> ostream&operator<<(ostream&dist,Array<T>&ar){
	int i;
	for(i=0;i<=ar.Subscript;i++) cout<<ar.elements[i];
	return dist;
}

int main(){
	Array<inventory> mylist;
	inventory temp;
	char ch;
	cout<<"�Ƿ���������Ʒ��Y or N"<<endl;
	cin>>ch;
	while(ch=='Y'||ch=='y'){
		cin.get();//���ջس�
		cin>>temp;
		mylist.ordinsert(temp);		
		cout<<"�Ƿ�������룿Y or N"<<endl;
		cin>>ch;
	}
	cout<<mylist;
	return 0;
}