//����3.10���Զ�������ֲ���̬����������
#include <iostream>
using namespace std;

st();
at();
int main(){
	 int i;
	 for(i=0;i<5;i++)  cout<<at()<<'\t';
	 cout<<endl;
	 for(i=0;i<5;i++)  cout<<st()<<'\t';
	 cout<<endl;
	 return 0;
}
st(){
	 static int t=100; 			//�ֲ���̬����
	 t++;
	 return t;
}
at(){
	 int t=100; 				//�Զ�����
	 t++;
	 return t;
}
