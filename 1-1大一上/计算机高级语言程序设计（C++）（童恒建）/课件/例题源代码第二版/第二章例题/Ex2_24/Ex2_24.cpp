/*����2.24�� �ڴ����к졢�ơ������ס���������ɫ�������ɸ���ÿ�δӿڴ���ȡ������ͬ��ɫ����
ͳ�Ʋ�������е�ȡ����
*/
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	enum color_set {red,yellow,blue,white,black};
	color_set color;
	int i,j,k,counter=0,loop;
	for(i=red;i<=black;i++)
		for(j=red;j<=black;j++)
			if(i!=j){						//ǰ��������ɫ��ͬ
				for(k=red;k<=black;k++)
					if(k!=i&&k!=j){		//��������ͬ��ǰ����������Ҫ��
						counter++;
						if((counter)%22==0){ //ÿ����ʾ22��
							cout<<"�밴�س�������";
							cin.get();
						}
						cout<<setw(15)<<counter;
						/*�������ÿ��ȡ����һ��Ϊһ��ȡ����������ɫ*/
						for(loop=1;loop<=3;loop++){
							switch(loop){
							case 1: color=(color_set) i; break;	//��һ����i
							case 2: color=(color_set) j; break;	//�ڶ�����j
							case 3: color=(color_set) k; break;	//��������k
							}
							switch(color){
							case red:   cout<<setw(15)<<"red";   break;
							case yellow:cout<<setw(15)<<"yellow";break;
							case blue:  cout<<setw(15)<<"blue";  break;
							case white:	cout<<setw(15)<<"white"; break;
							case black: cout<<setw(15)<<"black"; break;
							}
						}
						cout<<endl;			//���һ��ȡ������
					}
			}
	cout<<"���У�"<<counter<<"��ȡ��"<<endl;
	return 0;
}
