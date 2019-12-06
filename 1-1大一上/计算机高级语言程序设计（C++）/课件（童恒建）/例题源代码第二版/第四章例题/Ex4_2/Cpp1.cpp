class Rectangle {
	int left, top ;
	int right, bottom;
public:
//	Rectangle(int l=0, int t=0, int r=0, int b=0);
	Rectangle(int l, int t, int r, int b);
	~Rectangle(){};  //析构函数，在此函数体为空
	void Assign(int l, int t, int r, int b);
	void SetLeft(int t){ left = t;}  // 以下四个函数皆为内联成员函数
	void SetRight( int t ){ right = t;}
	void SetTop( int t ){ top = t;}
	void SetBottom( int t ){ bottom = t;}
	void Show();
};
