/*����2.13������һ���ı���ͳ���ı������������������ַ������ٶ�����֮���Կո��������з������
�ٶ��ı�û�п��С�
*/

#include<iostream>
using namespace std;

int main(){
	char ch;
	int nline=0,nword=0,nch=0;                    //�ַ��������
	int isword=0;
	cout<<"����һ���ı����޿��У���"<<endl;
	do{
		ch=cin.get();
		if(ch=='\n')  nline++;						//�����з�����+1
		if(ch!=' '&& ch!='\t'&&ch!='\n'&&ch!=EOF){  //�����Ǽ����
			if(!isword)  nword++;					//�ڵ��ʵ���ʼ����������+1
			nch++;								//�ַ�����+1
			isword=1;
		}
		else  isword=0;							//���������
	} while(ch!=EOF);							//�����ı�������Ϊֹ
	cout<<"������"<<nline<<endl;		
	cout<<"��������"<<nword<<endl;
	cout<<"�ַ�����"<<nch<<endl;
	return 0;
}
