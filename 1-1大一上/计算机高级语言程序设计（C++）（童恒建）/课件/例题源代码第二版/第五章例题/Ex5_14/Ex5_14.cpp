//����5.14������ָ���ά�������Ԫ�ص�ָ�����������ָ����ɶ�ά�����
//һά�����ָ����������ά����ȫ������Ԫ�ء�
#include< iostream>
using namespace std;
int main( ){
	int a[3][6]={{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18}};
	int  * ptr,i,j;
	ptr=&a[0][0] ;       //�� ptr = *a; ������ptr = a;
	for(i=0;i<18;i++){
		cout<<*(ptr+i)<<'\t';
		if(i%6==5) cout<<endl;
	}
	cout<<endl;
	int  (* ptr1)[6];       //ע�� ptr1��ָ�����6������Ԫ�ص�һά�����ָ��
	ptr1=a; 
	for(i=0;i<3;i++){
		for(j=0;j<6;j++) cout<<*(*(ptr1+i)+j)<<'\t';
		cout<<endl;
	}
	return 0;
}

