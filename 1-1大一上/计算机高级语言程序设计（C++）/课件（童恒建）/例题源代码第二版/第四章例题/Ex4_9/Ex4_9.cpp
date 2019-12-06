//【例4.9】用静态数据成员对同一类建立的对象的数量进行计数。
#include <iostream>
using namespace std;
class  Ctest{
private:
	static int count;      //注意私有
public:
	Ctest(){
		++count;cout<<"对象数量="<<count<<'\n';
	}
	~Ctest(){
		--count;cout<<"对象数量="<<count<<'\n';
	}
};
int Ctest::count=0;        //A行  对静态数据定义性说明
int main(void){
	Ctest a[3];
	return 0;
}

