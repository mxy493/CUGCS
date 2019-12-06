/*【例2.9】运输公司对所运货物实行分段计费。设运输里程为s，则运费打折情况如下：
s<250				不打折扣
250<=s<500			2%折扣
500<=s<1000			5%折扣
1000<=s<2000		8%折扣
2000<=s<3000		10%折扣
3000<=s				15%折扣
设每公里每吨的基本运费为p，货物重量为w，折扣为d，则总运费应该分段计算。
设计程序，当输入p、w和s后，计算运费f。
*/
#include <iostream>
using namespace std;

int main(){
	int c,s;
	double p,w,d,f;
	for(int i=0;i<2;i++){
	cout<<"输入运输单价p，重量w和里程s:"<<endl;
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
	cout<<"运输单价:"<<p<<'\t'<<"重量:"<<w<<'\t'<<"里程:"<<s<<endl;
	cout<<"折扣:"<<d*100<<"%\t"<<"折扣后运费:"<<f<<endl<<endl;
	}
	char ch;
	cin.get(ch);
	cin.get(ch);
	return 0;
}
