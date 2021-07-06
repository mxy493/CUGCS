#include<stdexcept>
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
const DefaultArraySize=10;//����ȱʡΪ����

template<typename elemType>class Array{
public:
	explicit Array(int sz=DefaultArraySize){
		size=sz;
		ia=new elemType [size];
	}
	~ Array(){delete [] ia;}
	elemType & operator[](int ix) const{//���±������[ ]����
		if(ix<0||ix>=size){//�����쳣�׳�,��ֹ����ֵԽ��
			string eObj="out_of_range error in Array< elemType >::operator[]()";
			throw out_of_range(eObj);
		}
		return  ia[ix];//����ԭ��[ ]������������ʽ
	}
private:
	int  size;
	elemType * ia;
};
int main(){
	int i;
	Array<int> arr;
	try{
		for(i=0;i<=DefaultArraySize;i++){
			arr[i]=i+1;//д��ia[10]ʱ����
			cout<<setw(5)<<arr[i];
		}
		cout<<endl;
	}
	catch(const out_of_range & excp){
		cerr<<'\n'<<excp.what()<<'\n'; //��ӡ"out_of_range error in Array<elemType>::operator[]()"
		return -1;
	}
	return 0;
}
