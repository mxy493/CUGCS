//¡¾Àı3.12¡¿¼ÆËã4£¡ 
#include <iostream>
using namespace std;

int fac(int n){
	int y;
	cout<<n<<'\t';                //A
	if(n==0||n==1) y=1; 
	else y=n*fac(n-1);
	cout<<y<<'\t';                //B
	return y;
}
int main(){
	cout<<"\n4!="<<fac(4)<<endl;
	return 0;
}
