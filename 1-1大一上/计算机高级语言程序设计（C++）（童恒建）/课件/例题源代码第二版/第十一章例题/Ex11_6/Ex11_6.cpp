//����11.6����ͺ�������Ķ���Ͳ��ԡ�
#include<iostream>
using namespace std;

template<typename T>class Sum{
	T res;
public:
	Sum(T i=0):res(i){} //���캯��,��Sum(T i=0){res=i;}
	T operator()(T x){  //�ۼӣ����صĵ��ò�����()
		res+=x;
		return res;
	}
};
template<typename FuncObject,typename T>
T Func1(FuncObject fob,const T &val){  //����������Ϊ����
	return fob(val);                       //�������ص�()��ʵ�ּӷ�
}  
template<typename FuncObject,typename T>
T Func2(FuncObject &fob,const T &val){  //����Ϊ���ã������ô˷�ʽ
	return fob(val);
} 
int main(){
	Sum<int> sum(10);                  //���ù��캯������sum��resֵΪ10
	int i=5,j=10;
	cout<<sum(j)<<'\t'<<sum(i)<<endl;  //�������ص�()��ʵ���ۼӣ������20  25
	cout<<Func1(sum,i)<<'\t';  
    //Func1������ֵ��sum::res����25����һ�ݿ��������sum+i�������30
	cout<<Func1(sum,j)<<endl;        //��һ�ݿ��������sum+j��δʵ���ۼӣ������35
	cout<<Func2(sum,i)<<'\t';
    //Func2����Ϊ���ã���ԭsum�����sum=sum+i��ʵ���ۼӣ������30
	cout<<Func2(sum,j)<<endl;            //���sum=sum+j��ʵ���ۼӣ������40
    //����Ϊ���������׼�÷���ÿ���½���������Func1��Func2����޲��
	cout<<Func1(Sum<int>(5),i)<<'\t';     // 5+i�������10  
	cout<<Func2(Sum<int>(),j)<<endl;      // 0+j�������10
	return 0;
}
