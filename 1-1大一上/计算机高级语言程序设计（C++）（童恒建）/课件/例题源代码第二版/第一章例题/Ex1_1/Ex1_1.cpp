//����1.1��һ���򵥵�C++������������������ͨ�����ú������������еĽϴ�ֵ��

# include <iostream>
using namespace std;
 
int max(int i, int j){  // ����max()����									
	if (i>=j) return i; 
	else return j;
}

int main(void){         //����main()����
	cout<<"����i,j��";   						//��ʾ��ʾ��Ϣ
	int i, j;					     			//˵������
	cin>>i>>j;								    //�Ӽ��������������ֵ
	cout<<"������ǣ�"<<max(i, j)<<'\n';		//�����ʾ��Ϣ�ͽ��
	return 0;
}
