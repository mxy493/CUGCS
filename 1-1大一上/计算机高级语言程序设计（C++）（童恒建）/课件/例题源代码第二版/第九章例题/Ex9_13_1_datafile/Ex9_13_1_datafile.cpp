/*��9.13_1	 ���̵�Ļ������Ϊһ�����������࣬�������̬��������ʼΪ2��Ԫ�أ�������ʱ����һ����
�ö����������ļ���������Ԫ�ض���Ҫ����ڹ��캯���У����ļ��ı���͹رշ������������С���һ����
��ʱ�������յ������ļ����ɼ������뽨������Ԫ�ض��󣬲�д���ļ��������˳�ʱ���ر��ļ�����һ������
�Ϳ������ļ�������󣬻ָ�ǰһ�������Ĺ�����*/
#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class inventory{
	string Description;//��Ʒ����
	int No;//����
	int Quantity;//����
	double Cost;//�۸�
	double Retail;//����
public:
	inventory(string ="#",int =0,int =0,double =0,double =0);
	void Bdatatofile(fstream & dist);    //����д���ļ�����
	void Bdatafromfile(fstream & sour);  //���ļ������������
	bool operator==(inventory &inven){return No==inven.No;}
	bool operator<=(inventory &inven){return No<=inven.No;}
	friend ostream&operator<<(ostream&dist,inventory&iv);   //���ز��������
	friend istream&operator>>(istream&sour,inventory&iv);   //������ȡ�����
};     //������Ϊ��ʽ��������������
inventory::inventory(string des,int no,int quan,double cost,double ret){
	Description=des;
	No=no;
	Quantity=quan;
	Cost=cost;
	Retail=ret;
}
void inventory::Bdatatofile(fstream & dist){
	dist.write(Description.c_str(),20);//��string���c_str()����תΪchar*
	dist.write((char*)&No,sizeof(int));
	dist.write((char*)&Quantity,sizeof(int));
	dist.write((char*)&Cost,sizeof(double));
	dist.write((char*)&Retail,sizeof(double));
}
void inventory::Bdatafromfile(fstream & sour){
	char Desc[20];
	sour.read(Desc,20);//�������ַ��������
	Description=Desc;
	sour.read((char*)&No,sizeof(int));
	sour.read((char*)&Quantity,sizeof(int));
	sour.read((char*)&Cost,sizeof(double));
	sour.read((char*)&Retail,sizeof(double));
}//�ɴ˿ɼ�����д����ȫ�ԳƵĹ���,��������ܴ�
ostream &operator<<(ostream&dist,inventory&iv){
	dist<<left<<setw(20)<<iv.Description<<setw(10)<<iv.No;
	dist<<right<<setw(10)<<iv.Quantity<<setw(10)<<iv.Cost<<setw(10)<<iv.Retail<<endl;
	return dist;
}
istream&operator>>(istream&sour,inventory&iv){
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
	return sour;
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
	friend ostream&operator<<(ostream&dist,Array&ar);
};
template <typename T> Array<T>::Array(int maxs){
	maxSize=maxs;
	Subscript=-1;//˽�����ݲ�����ֱ�Ӹ���ֵ,�����ڹ��캯���и���ֵ
	T temp;
	elements=new T[maxSize];
	datafile.open("mydatafile.dat",ios::binary|ios::in);
	if(!datafile==0){
		while(!datafile.eof()){
			temp.Bdatafromfile(datafile);
			if(datafile.eof()==0){//���������ݿɶ���,�����벻�ɹ�,eofbitΪ1
				ordinsert(temp);//��ʹԭ�ļ�δ���򣬶���Ҳ���ź���ģ��˳�ʱ���ź�����ش�
			}
		}
		datafile.close();
	}
	datafile.clear(0);//���ñ�׼�ⲻ���٣�ǰ�������������ļ��������޷��ָ�
}
template <typename T> Array<T>::~Array(){
	int i;
	datafile.open("mydatafile.dat",ios::binary|ios::out);
	for(i=0;i<=Subscript;i++) elements[i].Bdatatofile(datafile);
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
template <typename T>ostream&operator<<(ostream&dist,Array<T>&ar){
	int i;
	for(i=0;i<=ar.Subscript;i++) dist<<ar.elements[i];
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