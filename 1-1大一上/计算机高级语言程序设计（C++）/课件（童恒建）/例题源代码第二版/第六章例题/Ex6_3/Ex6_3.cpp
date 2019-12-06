//¡¾Àı6.3¡¿Ë³Ğò±íÀàÄ£°å¡£
#include<iostream>
using namespace std;
template <typename T,int size>class seqlist{
	T slist[size];                                     //´æ·ÅË³Ğò±íµÄÊı×é
	int Maxsize;                                       //×î´ó¿ÉÈİÄÉÏîÊı 
	int last;                                          //ÒÑ´æ±íÏîµÄ×îºóÎ»ÖÃ
public:
	seqlist(){last=-1;Maxsize=size;}                   //³õÊ¼»¯Îª¿Õ±í
	int Length() const{return last+1;}                 //¼ÆËã±í³¤¶È
	int Find(T & x)const;                              //Ñ°ÕÒxÔÚ±íÖĞÎ»ÖÃ£¨ÏÂ±ê£©
	bool IsIn(T & x);                                  //ÅĞ¶ÏxÊÇ·ñÔÚ±íÖĞ
	bool Insert(T & x,int i);                          //x²åÈëµ½ÁĞ±íÖĞµÚi¸öÎ»ÖÃ´¦£¨ÏÂ±ê£©
	bool Remove(T & x);                                //É¾³ıx
	int Next(T & x);                                   //Ñ°ÕÒxµÄºó¼ÌÎ»ÖÃ
	int Prior(T & x);                                  //Ñ°ÕÒxµÄÇ°ÇıÎ»ÖÃ
	bool IsEmpty(){return last==-1;}                   //ÅĞ¶Ï±íÊÇ·ñ¿Õ
	bool IsFull(){return last==Maxsize -1;}            //ÅĞ¶Ï±íÊÇ·ñÂú
	T Get(int i){return i<0||i>last?NULL:slist[i];}    //È¡µÚi¸öÔªËØÖ®Öµ
	T& operator[](int i);                              //ÖØÔØÏÂ±êÔËËã·û[]
};
template <typename T,int size> int seqlist<T,size>::Find(T & x)const{
  //×¢Òâ¸ñÊ½£¬const±íÊ¾¸Ãº¯ÊıµÄthisÖ¸ÕëÎªconst£¬¼´±»·ÃÎÊ¶ÔÏóµÄÊı¾İ²»ÄÜ±»ĞŞ¸Ä¡£
  //Èç±»ĞŞ¸Ä£¬±àÒëÆ÷»á¾¯¸æ£¬·ÀÖ¹±à³ÌÊ±Ê§Îó¡£
	int i=0;
	while(i<=last && slist[i]!=x) i++;  //Ë³Ğò²éÕÒÊÇ·ñÓĞx 
	if (i>last) return -1;              //Î´ÕÒµ½£¬·µ»Ø-1
	else return i;                      //ÕÒµ½£¬·µ»ØÏÂ±ê
}
template <typename T,int size> bool seqlist<T,size>::IsIn(T & x){
	int i=0;
	bool found=0;
	while(i<=last && !found)            //»»ÁËÒ»ÖÖ·½·¨À´²éÕÒ
		if (slist[i]!=x) i++;
		else found=1;                       //ÕÒµ½
		return found;
}
template <typename T,int size> bool seqlist<T,size>::Insert(T & x, int i){
	int j;
	if (i<0||i>last+1||last==Maxsize -1) return false;  //²åÈëÎ»ÖÃ²»ºÏÀí£¬²»ÄÜ²åÈë£¨½¡×³ĞÔ£©
	else{
		last++;
		for(j=last;j>i;j--) slist[j]=slist[j-1];    //´Ó±í×îºóÎ»ÖÃÏòÇ°ÒÀ´ÎºóÒÆ£¨¿Õ³öÖ¸¶¨Î»ÖÃ
		slist[i]=x;
		return true;
	}
}
template <typename T,int size> bool seqlhst<T,size>::Remove(T & x){
	int i=Find(x),j;                                        //ÏÈÈ¥ÕÒxÔÚÄÄ¸öÎ»ÖÃ
	if(i>=0){
		last--;
		for(j=i;j<=last;j++) slist[j]=slist[j+1];         //ÒÀ´ÎÇ°ÒÆ£¬±£Ö¤±íÁ¬Ğø
		return true;
	}
	return false;                                         //±íÖĞ²»´æÔÚx
}
template <typename T,int size> int seqlist<T,size>::Next(T & x){
	int i=Find(x);
	if(i>=0 && i<last) return i+1;                        //xºs¼ÌÎ»ÖÃ
	else return -1;                                       //x²»ÔÚ±íÖĞ£¬»òÔÚ±íD©Î²
}
template <typename T,int size> int seqlist<T,size>::Prior(T & x){
	int i=Find(x);
	if(i>0 && i<=last)  return i-1;                       //xÇ°ÇıµÄÎ»ÖÃ
	else return -1;
}
template <typename T,int size> T& seqlist<T,size>::operator[](int i){
	if(i>last+1||i<0||i>=Maxsize){
		cout<<"ÏÂ±ê³ö½ç£¡"<<endl;
		exit(1);
	}
	if(i>last) last++;  //ÏÂ±êÔËËã·û[]£¬Ö»Ä\Ôö¼Ó±íµÄÔªËØ£¬²»ÄÜ¼õÉÙ
	return slist[i];
}

int main(){
	seqlist <int,100> seqlisti;                         //Ë³Ğò±i¶ÔÏóseqlistiµÄÔªKØÎªÕûĞÍ
	int i,j,k,a[10]={2,3,5,7,11,13,17,19,23,29};
	for(j=0;j<10;j++)
		if (!seqlisti.Insert(a[j],j)){                      //°ÑËØÊıĞ´Èë
			cout<<"±íÌ«´ó·Å²»ÏÂÁË!"<<endl;
			break;
		}
	j=seqlisti.Length();
	for(i=0;i<j;i++) cout<<seqlisti.Get(i)<<' ';        //´òÓ¡³öseqlisti.slist[]-ËØÊı±í
	cout<<endl ;
	for(j=0;j<10;j++) seqlisti[j]=0;                    //²ÉÓÃÏÂ±êÔËËã·ûÔËËã
	for(j=0;j<10;j++) cout<<seqlisti[j]<<' ';
	cout<<endl;
	for(j=0;j<10;j++) seqlisti[j]=a[j];
	seqlisti[10]=31;                                    //ÊµÑéÄÜ·ñÔö¼ÓÔªËØ
	for(j=0;j<11;j++) cout<<seqlisti[j]<<' ';
	cout<<endl;

	k=7;
	if (seqlisti.IsIn(k)) cout<<"ËØÊı7ÔÚË³Ğò±íÖĞ"<< endl;
	//ÒòĞÎ²ÎÎªÒıÓÃ£¬ËùÒÔJµ²Î²»¿ÉÓCÕûÊı³£Á¿7
	else cout <<"ËØÊı7²»ÔÚË³Ğò±íÖĞ"<<endl;
	k=17;
	if (seqlisti.Remove (k)) cout<<"É¾³ıËØÊı17"<<endl;  //É¾³ıËØÊı17
	else cout<<"ÕÒ²»µ½ËØÊı17£¬ÎŞ·¨É¾³ı";
	j=seqlisti.Length( ) ;
	for (i=0;i<j;i++) cout<<seqlisti.Get(i)<<' ';      //´òÓ¡Ê£ÏÂµÄËØÊı
	cout<<endl;
	if (seqlisti.Insert(k,j-1)){                       // °ÑËØÊı17×°»ØÈ¥,³É¹¦Ôò´òÓ¡
		j=seqlisti.Length ( );
		for (i=0;i<j;i++)  cout<<seqlisti.Get(i)<<' '; 
		cout<<endl;
	}
	cout<<"´òÓ¡17ºóÒ»¸öËØÊı£º"<<seqlisti.Get(seqlisti.Next(k)) <<endl;
	cout<<"´òÓ¡17Ç°Ò»¸öËØÊı£º"<<seqlisti.Get(seqlisti.Prior(k))<<endl;
	cout<<"ËØÊı17ÔÚ±íÖĞÎ»ÖÃ£¨ÏÂ±ê£©Îª£º"<<seqlisti.Find(k)<<endl;
	if(seqlisti.IsEmpty( ))  cout<<"±íÊÇ¿ÕµÄ"<<endl;
	else cout<<"±í²»¿Õ"<<endl;
	if (seqlisti.IsFull())  cout<<"±íÊÇÂúµÄ"<<endl; 
	else cout<<"±íÒ²²»Âú"<<endl;
	if (seqlisti.IsIn(k))  cout<<"ËØÊı17ÔÚ±íÖĞ"<<endl;
	return 0;
}
