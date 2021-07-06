//����7.2�� ��̬������ɾ��һ��m*n��Ԫ�ص����顣����ָ�����鷽ʽ����ɶ�ά����Ķ�̬����
#include <iostream>
#include<cstdlib>
using namespace std;

void display(double **);
void de_allocate(double **);
int m=4;                               //����
int n=6;                               //����

int main(){
	int i,j;
	double **data;
	data = new double*[m];//������
	if ((data)==0){
		cout<<"Could not allocate. Bye ...";
		return -1;
	}
	for(j=0;j<m;j++){
		data[j] = new double[n];//������
		if (data[j] == 0){
			cout << "Could not allocate. Bye ...";
			return -1;
		}
	}
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			data[i][j]=i*n+j;//��ʼ������Ԫ��
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
	for (i=0;i<m;i++) delete[] data[i];  //ע�⳷���������к��У��������෴
	delete[] data;
}
