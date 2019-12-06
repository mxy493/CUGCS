/*【例6.10】冒泡排序算法。为了简单，采用函数模版对数组进行处理，
数据元素为第五章中自定义的字符串类mystring。
*/
#include<iostream>
using namespace std;
const n=21; 
class mystring{
	char str[n];        //存放字符串的数组容器
	int maxsize;          //最大可用元素数，可防止数组出界，提高健壮性
	int last;              //已用元素最大下标
public:
	mystring(){
		last=-1;
		maxsize=n;
		str[0]='\0';
	}
	mystring(char *s){//当C字符串过长，初始化时采用截尾处理
		last=-1;
		maxsize=n;
		do{
			last++;
			str[last]=s[last];
		}while(s[last]!='\0'&&last<maxsize-1);
		str[last] ='\0'; //截尾处理时，必须加串结束符
	}
	~mystring(){}
	void show(){//如需重载<<,则请参见9.3节,暂时未学到,替代方法是改用show()函数
		cout<<str<<'\t';
	}
	bool operator<(mystring &);
	mystring & operator=(char * ms);  //这里重载的=是把C风格字符串赋给mystring
};
bool mystring::operator<(mystring & ms){   //重载<运算符
	int i=0,k;
	do{
		k=str[i]-ms.str[i];
		i++;
	}while(k==0&&i<last&&i<ms.last);
	if(k<0) return true;
	if(i==last&&i!=ms.last) return true;
	return false;
}
mystring & mystring::operator=(char * ms){ //这里返回值为引用，不调用拷贝构造函数
	last=-1;	
	do{
		last++;
		str[last]=ms[last];
	}while(ms[last]!='\0'&&last<maxsize-1);
	str[last] ='\0'; //截尾处理时，必须加串结束符
return *this;
}
template <typename T> void BubbleSort(T* slist,int n){
	bool noswap;
	int i,j;
	T temp;
	for (i=0;i<n-1;i++){             //最多做n-1趟
		noswap=true;	              //未交换标志为真
		for(j=n-1;j>i;j--){          //从下往上冒泡
			if(slist[j]<slist[j-1]){
				temp=slist[j];
				slist[j]=slist[j-1];
				slist[j-1]=temp;
				noswap=false;
			}			
		}
		if(noswap) break;	         //本趟无交换，则终止算法。
	}
}
int main(){
	const int h=10;
	int i;
	mystring list[10]={"cat","book","car","zoo","fish","cab","dog","cap","fox","can"};
	cout<<"未排序数组："<<endl;
	for(i=0;i<h;i++)  list[i].show(); 
	BubbleSort(list,h);
	cout<<"已排序数组："<<endl;
	for(i=0;i<h;i++)  list[i].show(); 
	return 0;
}
