//����1.2��һ��ʹ������ļ����ӡ�
# include <iostream >
using namespace std;

int main(){
	int int_array[4];
	int_array[0]=1;
	int_array[1]=1; 
	int_array[2]=2;
	int_array[3]=int_array[1]+int_array[2];
	cout<<int_array[3]<<'\n';
	return 0;
}
