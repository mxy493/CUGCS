#include <iostream>
using namespace std;
/*
int main()
{
    int i;
	int a,b,c;

	for(i=100;i<=999;i++)
	{
		a=i%10;
		b=i/10%10;
		c=i/100;
		if(i==a*a*a + b*b*b +c*c*c)
			cout<<i<<endl;

	}

	return 1;
}
*/

int main()
{
   // int i;
	int a,b,c;

	for(a=1;a<=9;a++)
			for(b=0;b<=9;b++)
					for(c=0;c<=9;c++)
	{
	
		if(a*100+b*10+c ==a*a*a + b*b*b +c*c*c)
			cout<<a*100+b*10+c<<endl;

	}

	return 1;
}