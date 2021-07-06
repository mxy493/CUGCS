//����6.3��˳�����ģ�塣
#include<iostream>
using namespace std;
template <typename T,int size>class seqlist{
	T slist[size];                                     //���˳��������
	int Maxsize;                                       //������������ 
	int last;                                          //�Ѵ��������λ��
public:
	seqlist(){last=-1;Maxsize=size;}                   //��ʼ��Ϊ�ձ�
	int Length() const{return last+1;}                 //�������
	int Find(T & x)const;                              //Ѱ��x�ڱ���λ�ã��±꣩
	bool IsIn(T & x);                                  //�ж�x�Ƿ��ڱ���
	bool Insert(T & x,int i);                          //x���뵽�б��е�i��λ�ô����±꣩
	bool Remove(T & x);                                //ɾ��x
	int Next(T & x);                                   //Ѱ��x�ĺ��λ��
	int Prior(T & x);                                  //Ѱ��x��ǰ��λ��
	bool IsEmpty(){return last==-1;}                   //�жϱ��Ƿ��
	bool IsFull(){return last==Maxsize -1;}            //�жϱ��Ƿ���
	T Get(int i){return i<0||i>last?NULL:slist[i];}    //ȡ��i��Ԫ��ֵ֮
	T& operator[](int i);                              //�����±������[]
};
template <typename T,int size> int seqlist<T,size>::Find(T & x)const{
  //ע���ʽ��const��ʾ�ú�����thisָ��Ϊconst���������ʶ�������ݲ��ܱ��޸ġ�
  //�类�޸ģ��������ᾯ�棬��ֹ���ʱʧ��
	int i=0;
	while(i<=last && slist[i]!=x) i++;  //˳������Ƿ���x 
	if (i>last) return -1;              //δ�ҵ�������-1
	else return i;                      //�ҵ��������±�
}
template <typename T,int size> bool seqlist<T,size>::IsIn(T & x){
	int i=0;
	bool found=0;
	while(i<=last && !found)            //����һ�ַ���������
		if (slist[i]!=x) i++;
		else found=1;                       //�ҵ�
		return found;
}
template <typename T,int size> bool seqlist<T,size>::Insert(T & x, int i){
	int j;
	if (i<0||i>last+1||last==Maxsize -1) return false;  //����λ�ò��������ܲ��루��׳�ԣ�
	else{
		last++;
		for(j=last;j>i;j--) slist[j]=slist[j-1];    //�ӱ����λ����ǰ���κ��ƣ��ճ�ָ��λ��
		slist[i]=x;
		return true;
	}
}
template <typename T,int size> bool seqlhst<T,size>::Remove(T & x){
	int i=Find(x),j;                                        //��ȥ��x���ĸ�λ��
	if(i>=0){
		last--;
		for(j=i;j<=last;j++) slist[j]=slist[j+1];         //����ǰ�ƣ���֤������
		return true;
	}
	return false;                                         //���в�����x
}
template <typename T,int size> int seqlist<T,size>::Next(T & x){
	int i=Find(x);
	if(i>=0 && i<last) return i+1;                        //x�s��λ��
	else return -1;                                       //x���ڱ��У����ڱ�D�β
}
template <typename T,int size> int seqlist<T,size>::Prior(T & x){
	int i=Find(x);
	if(i>0 && i<=last)  return i-1;                       //xǰ����λ��
	else return -1;
}
template <typename T,int size> T& seqlist<T,size>::operator[](int i){
	if(i>last+1||i<0||i>=Maxsize){
		cout<<"�±���磡"<<endl;
		exit(1);
	}
	if(i>last) last++;  //�±������[]��ֻ�\���ӱ��Ԫ�أ����ܼ���
	return slist[i];
}

int main(){
	seqlist <int,100> seqlisti;                         //˳��i����seqlisti��ԪK�Ϊ����
	int i,j,k,a[10]={2,3,5,7,11,13,17,19,23,29};
	for(j=0;j<10;j++)
		if (!seqlisti.Insert(a[j],j)){                      //������д��
			cout<<"��̫��Ų�����!"<<endl;
			break;
		}
	j=seqlisti.Length();
	for(i=0;i<j;i++) cout<<seqlisti.Get(i)<<' ';        //��ӡ��seqlisti.slist[]-������
	cout<<endl ;
	for(j=0;j<10;j++) seqlisti[j]=0;                    //�����±����������
	for(j=0;j<10;j++) cout<<seqlisti[j]<<' ';
	cout<<endl;
	for(j=0;j<10;j++) seqlisti[j]=a[j];
	seqlisti[10]=31;                                    //ʵ���ܷ�����Ԫ��
	for(j=0;j<11;j++) cout<<seqlisti[j]<<' ';
	cout<<endl;

	k=7;
	if (seqlisti.IsIn(k)) cout<<"����7��˳�����"<< endl;
	//���β�Ϊ���ã�����J��β����C��������7
	else cout <<"����7����˳�����"<<endl;
	k=17;
	if (seqlisti.Remove (k)) cout<<"ɾ������17"<<endl;  //ɾ������17
	else cout<<"�Ҳ�������17���޷�ɾ��";
	j=seqlisti.Length( ) ;
	for (i=0;i<j;i++) cout<<seqlisti.Get(i)<<' ';      //��ӡʣ�µ�����
	cout<<endl;
	if (seqlisti.Insert(k,j-1)){                       // ������17װ��ȥ,�ɹ����ӡ
		j=seqlisti.Length ( );
		for (i=0;i<j;i++)  cout<<seqlisti.Get(i)<<' '; 
		cout<<endl;
	}
	cout<<"��ӡ17��һ��������"<<seqlisti.Get(seqlisti.Next(k)) <<endl;
	cout<<"��ӡ17ǰһ��������"<<seqlisti.Get(seqlisti.Prior(k))<<endl;
	cout<<"����17�ڱ���λ�ã��±꣩Ϊ��"<<seqlisti.Find(k)<<endl;
	if(seqlisti.IsEmpty( ))  cout<<"���ǿյ�"<<endl;
	else cout<<"����"<<endl;
	if (seqlisti.IsFull())  cout<<"��������"<<endl; 
	else cout<<"��Ҳ����"<<endl;
	if (seqlisti.IsIn(k))  cout<<"����17�ڱ���"<<endl;
	return 0;
}
