//����9.1�������������
#include<iostream>
using namespace std;
int main(void){
	int inum=255;
	cout<<"ʮ���Ʒ�ʽ"<<inum<<'\t';
	cout.flags(ios::oct|ios::showbase);//�˽��ƴ����ƻ������ǰ���0;������Ч0x00a0
	cout<<"�˽��Ʒ�ʽ"<<inum<<'\t';
	cout.setf(ios::hex);               //��Ч0x0040,���ǻ��ϵ,�Դ������,��ʽΪ0x...
	cout<<"ʮ�����Ʒ�ʽ"<<inum<<endl;
	return 0;
}
