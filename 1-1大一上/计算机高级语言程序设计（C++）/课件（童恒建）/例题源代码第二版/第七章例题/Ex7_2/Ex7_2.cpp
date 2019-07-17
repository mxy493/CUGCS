//【例7.2】 动态创建和删除一个m*n个元素的数组。采用指针数组方式来完成二维数组的动态创建
#include <iostream>
#include<cstdlib>
using namespace std;

void display(double **);
void de_allocate(double **);
int m=4;                               //行数
int n=6;                               //列数

int main(){
	int i,j;
	double **data;
	data = new double*[m];//设置行
	if ((data)==0){
		cout<<"Could not allocate. Bye ...";
		return -1;
	}
	for(j=0;j<m;j++){
		data[j] = new double[n];//设置列
		if (data[j] == 0){
			cout << "Could not allocate. Bye ...";
			return -1;
		}
	}
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			data[i][j]=i*n+j;//初始化数组元素
	display(data);
	de_allocate(data);
	return 0;
}

void display(double **data){
	int i,j;
	for (i=0;i<m;i++){
		for (j=0;j<n;j++) cout<<data[i][j]<<"\t";
	cout << endl;
	}
}

void de_allocate(double **data){
	int i;
	for (i=0;i<m;i++) delete[] data[i];  //注意撤销次序，先列后行，与设置相反
	delete[] data;
}
