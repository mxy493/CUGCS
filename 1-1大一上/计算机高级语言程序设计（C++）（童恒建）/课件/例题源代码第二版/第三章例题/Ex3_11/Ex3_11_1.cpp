//����3.11���ⲿ�洢���͵����ӡ��ٶ������������Դ�����ļ�Ex3_11_1.cpp��Ex3_11_2.cpp������ṹ���£�
/* Ex3_11_1.cpp ����main()���*/
# include <iostream>
using namespace std;

void fun2();				//�ⲿ�����������ȼ���extern void fun2();
int n;						//ȫ�ֱ�������
int main(){
	n=1;
	fun2();					// fun2()�������ļ�Ex3_11_2.cpp��
	cout<<"n="<<n<<endl;
	return 0;
}
