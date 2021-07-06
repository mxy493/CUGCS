#include <iostream>
using namespace std;
/*
int main()
{
   int prize = 80;
   int a,b;
   float c;

   cout<<"请输入您购买的数目：";

   cin>>a;
   
   if(a>5&&a<10)
   {
	   c = 0.9*prize*a;
	   cout<<c<<endl;
   }
   else 
	   if(a>=10)
	   {
		 c = 0.8*prize*a;
		 cout<<c<<endl;
	   }
      else
	  {
		c = a*prize;
        cout<<c<<endl;
	  }
	   
	return 0;
}
*/

int main()
{
   int x;
   cout<<"Please input x:";
   cin>>x;
   if(x%3!=0 && x%7==0)
	  cout<<" The number is OK !"<<endl;
   else
      cout<<" The number is not OK !"<<endl;
   return 1;
}