/*����2.9�����乫˾�����˻���ʵ�зֶμƷѡ����������Ϊs�����˷Ѵ���������£�
s<250				�����ۿ�
250<=s<500			2%�ۿ�
500<=s<1000			5%�ۿ�
1000<=s<2000		8%�ۿ�
2000<=s<3000		10%�ۿ�
3000<=s				15%�ۿ�
��ÿ����ÿ�ֵĻ����˷�Ϊp����������Ϊw���ۿ�Ϊd�������˷�Ӧ�÷ֶμ��㡣
��Ƴ��򣬵�����p��w��s�󣬼����˷�f��
*/
#include <iostream>
using namespace std;

int main(){
	int c,s;
	double p,w,d,f;
	for(int i=0;i<2;i++){
	cout<<"�������䵥��p������w�����s:"<<endl;
	cin>>p>>w>>s;
	f=0;
	c=s/250;
	switch(c){
		case 0: d=0;break;
		case 1: d=0.02;break;
		case 2: 
		case 3: d=0.05;break;
		case 4: 
		case 5: 
		case 6:  
		case 7: d=0.08;break;
		case 8: 
		case 9: 
		case 10: 
		case 11: d=0.1;break;
		default: d=0.15;
	}
	f=p*w*s*(1-d);
	cout<<"���䵥��:"<<p<<'\t'<<"����:"<<w<<'\t'<<"���:"<<s<<endl;
	cout<<"�ۿ�:"<<d*100<<"%\t"<<"�ۿۺ��˷�:"<<f<<endl<<endl;
	}
	char ch;
	cin.get(ch);
	cin.get(ch);
	return 0;
}
