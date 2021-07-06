/*����6.10��ð�������㷨��Ϊ�˼򵥣����ú���ģ���������д���
����Ԫ��Ϊ���������Զ�����ַ�����mystring��
*/
#include<iostream>
using namespace std;
const n=21; 
class mystring{
	char str[n];        //����ַ�������������
	int maxsize;          //������Ԫ�������ɷ�ֹ������磬��߽�׳��
	int last;              //����Ԫ������±�
public:
	mystring(){
		last=-1;
		maxsize=n;
		str[0]='\0';
	}
	mystring(char *s){//��C�ַ�����������ʼ��ʱ���ý�β����
		last=-1;
		maxsize=n;
		do{
			last++;
			str[last]=s[last];
		}while(s[last]!='\0'&&last<maxsize-1);
		str[last] ='\0'; //��β����ʱ������Ӵ�������
	}
	~mystring(){}
	void show(){//��������<<,����μ�9.3��,��ʱδѧ��,��������Ǹ���show()����
		cout<<str<<'\t';
	}
	bool operator<(mystring &);
	mystring & operator=(char * ms);  //�������ص�=�ǰ�C����ַ�������mystring
};
bool mystring::operator<(mystring & ms){   //����<�����
	int i=0,k;
	do{
		k=str[i]-ms.str[i];
		i++;
	}while(k==0&&i<last&&i<ms.last);
	if(k<0) return true;
	if(i==last&&i!=ms.last) return true;
	return false;
}
mystring & mystring::operator=(char * ms){ //���ﷵ��ֵΪ���ã������ÿ������캯��
	last=-1;	
	do{
		last++;
		str[last]=ms[last];
	}while(ms[last]!='\0'&&last<maxsize-1);
	str[last] ='\0'; //��β����ʱ������Ӵ�������
return *this;
}
template <typename T> void BubbleSort(T* slist,int n){
	bool noswap;
	int i,j;
	T temp;
	for (i=0;i<n-1;i++){             //�����n-1��
		noswap=true;	              //δ������־Ϊ��
		for(j=n-1;j>i;j--){          //��������ð��
			if(slist[j]<slist[j-1]){
				temp=slist[j];
				slist[j]=slist[j-1];
				slist[j-1]=temp;
				noswap=false;
			}			
		}
		if(noswap) break;	         //�����޽���������ֹ�㷨��
	}
}
int main(){
	const int h=10;
	int i;
	mystring list[10]={"cat","book","car","zoo","fish","cab","dog","cap","fox","can"};
	cout<<"δ�������飺"<<endl;
	for(i=0;i<h;i++)  list[i].show(); 
	BubbleSort(list,h);
	cout<<"���������飺"<<endl;
	for(i=0;i<h;i++)  list[i].show(); 
	return 0;
}
