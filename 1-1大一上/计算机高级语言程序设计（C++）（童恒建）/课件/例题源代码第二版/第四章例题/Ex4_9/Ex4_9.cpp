//����4.9���þ�̬���ݳ�Ա��ͬһ�ཨ���Ķ�����������м�����
#include <iostream>
using namespace std;
class  Ctest{
private:
	static int count;      //ע��˽��
public:
	Ctest(){
		++count;cout<<"��������="<<count<<'\n';
	}
	~Ctest(){
		--count;cout<<"��������="<<count<<'\n';
	}
};
int Ctest::count=0;        //A��  �Ծ�̬���ݶ�����˵��
int main(void){
	Ctest a[3];
	return 0;
}

