template<typename T>
class seqlist{
	T *s;
	int last;
	int maxsize;
public:
	seqlist();
	seqlist(seqlist &);
	bool Insert(T &,int);
	bool Insert(T &);
	seqlist & operator=(seqlist &);
	T operator[](int);
	~seqlist();
	void print();
	void bubbleSort();
};

template<typename T>
seqlist<T>::seqlist(){
	int n;
	cout<<"input maxsize of the list:";
	cin>>n;
	last=-1;
	maxsize=n;
	if(!(s=new T[n])) cout<<"fail 0"<<endl; 
}

template<typename T>
seqlist<T>::seqlist(seqlist<T> &a){
	if(s=new T[a.last+1]){
		last=a.last;
		maxsize=a.maxsize;
		for(int i=0;i<=a.last;i++) s[i]=a.s[i];
	}
	else cout<<"fail 1"<<endl;  
}

template<typename T>
seqlist<T> & seqlist<T>::operator= (seqlist<T> &a){
	if(s) delete []s;
	if(a.s){
		if(s=new T[a.last+1]){
			last=a.last;
			maxsize=a.maxsize;
			for(int i=0;i<=a.last;i++) s[i]=a.s[i];
		}
		else cout<<"fail 2"<<endl; 
	}
	else s=0;
	return *this;
}

template<typename T>
T seqlist<T>::operator[] (int i){
	if(i>last||i<0) cout<<"out of range"<<endl;
	else return s[i];
}

template<typename T>
bool seqlist<T>::Insert(T &a,int i){
	if(last==maxsize-1){cout<<"list full"<<endl; return false;}
	else if(i<0||i>last+1){cout<<"wrong position"<<endl; return false;}
	else{
		for(int j=last;j>=i;j--) s[j+1]=s[j];
		s[i]=a;
		last++;
		return true;
	}
}

template<typename T>
bool seqlist<T>::Insert(T &a){
	if(last==maxsize-1){cout<<"list full"<<endl; return false;}
	else{
		if(last==-1){
			last++;
			s[last]=a;
		}
		else{
			for(int j=last;j>=0&&a<s[j];j--) s[j+1]=s[j];
			s[j+1]=a;
			last++;
		}
		return true;
	}
}

template<typename T>
seqlist<T>::~seqlist(){if(s) delete []s;}

template<typename T>
void seqlist<T>::print(){
	for(int i=0;i<=last;i++) cout<<s[i]; 
	cout<<endl;
}

template<typename T>
void seqlist<T>::bubbleSort(){
	int noswap=1;
	for(int i=0;i<last;i++){
		for(int j=last;j>i;j--)
			if(s[j]<s[j-1]){
				T temp=s[j];
				s[j]=s[j-1];
				s[j-1]=temp;
				noswap=0;
			}
		if(noswap) break;
	}
}