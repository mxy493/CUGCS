//【例5.10】C++/C 标准库提供了字符串复制函数 strcpy()，本例显示算法的演变，可以看出指针应用之妙。
#include< iostream>
using namespace std;

void scopy1(char s[],char ct[]){
	int i=0;
	while (ct[i]!='\0'){
		s[i]=ct[i];
		i++;
	}
	s[i]='\0';
}
void scopy2(char *s, char *ct){
	while(*ct != '\0'){
		*s=*ct;
		s=s+1;
		ct=ct+1;
	}
	*s = '\0';
}
void scopy3(char *s, char *ct){
	while(*ct)  *s++=*ct++;
	*s = '\0';
}
void scopy4(char *s, char *ct){
    while( *s++=*ct++);
}
int main(){
	char a[20],b[]={"张成是篮球运动员。"};
	scopy1(a,b);
	cout<<a<<endl;
	scopy2(a,b);
	cout<<a<<endl;
	scopy3(a,b);
	cout<<a<<endl;
	scopy4(a,b);
	cout<<a<<endl;
	return 0;
}
