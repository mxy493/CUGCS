//【例11.8】我国部分省份与面积映射关联容器类的演示。
#include<iostream>
#include<string>
#include<functional>
#include<map>
using namespace std;

typedef map<string,double,less<string> > mappro;  //> >之间必须有空格
int main(){
	int  i;
	string provinces[]={"Jiangsu","Zhejiang","Anhui","Henan","Xinjiang"};
	double areas[]={10.26,10.18,13.96,16.7,166};
	mappro mapprovinces;
	mappro::iterator iter;
	for(i=0;i<5;i++) mapprovinces[provinces[i]]=areas[i];
	mapprovinces.insert(mappro::value_type("Guangdong",17.98));
	mapprovinces.insert(mappro::value_type("Shanxi",20.58));
	mapprovinces.insert(mappro::value_type("Heilongjiang",46));
	mapprovinces.insert(mappro::value_type("Taiwan",3.6));
	mapprovinces.insert(mappro::value_type("Yunnan",39.4));
	for(iter=mapprovinces.begin();iter!= mapprovinces.end();iter++)
		cout<<iter->first<<'\t'<<iter->second<<'\n';
	return 0;
}
