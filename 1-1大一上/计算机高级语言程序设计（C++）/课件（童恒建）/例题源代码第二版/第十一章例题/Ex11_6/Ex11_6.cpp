//【例11.6】求和函数对象的定义和测试。
#include<iostream>
using namespace std;

template<typename T>class Sum{
	T res;
public:
	Sum(T i=0):res(i){} //构造函数,即Sum(T i=0){res=i;}
	T operator()(T x){  //累加，重载的调用操作符()
		res+=x;
		return res;
	}
};
template<typename FuncObject,typename T>
T Func1(FuncObject fob,const T &val){  //函数对象作为参数
	return fob(val);                       //调用重载的()，实现加法
}  
template<typename FuncObject,typename T>
T Func2(FuncObject &fob,const T &val){  //参数为引用，建议用此方式
	return fob(val);
} 
int main(){
	Sum<int> sum(10);                  //调用构造函数建立sum。res值为10
	int i=5,j=10;
	cout<<sum(j)<<'\t'<<sum(i)<<endl;  //调用重载的()，实现累加，输出：20  25
	cout<<Func1(sum,i)<<'\t';  
    //Func1参数传值，sum::res保持25，在一份拷贝上完成sum+i，输出：30
	cout<<Func1(sum,j)<<endl;        //在一份拷贝上完成sum+j，未实现累加，输出：35
	cout<<Func2(sum,i)<<'\t';
    //Func2参数为引用，在原sum上完成sum=sum+i，实现累加，输出：30
	cout<<Func2(sum,j)<<endl;            //完成sum=sum+j，实现累加，输出：40
    //以下为函数对象标准用法，每次新建函数对象，Func1和Func2结果无差别
	cout<<Func1(Sum<int>(5),i)<<'\t';     // 5+i，输出：10  
	cout<<Func2(Sum<int>(),j)<<endl;      // 0+j，输出：10
	return 0;
}
