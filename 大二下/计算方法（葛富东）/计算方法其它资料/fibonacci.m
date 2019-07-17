function X=fibonacci(f,a,b,tol,e)

%Input    - f, the object function 
%            - a, the left endpoint of the interval
%            - b, the right endpoint of the interval
%            - tol, length of uncertainty
%            - e, distinguishability constant
%Output - X, x and y coordinates of minimum
%Note this function calls the m-file fib.m


% f=@(x) sin(x)+exp(x);
% a=0; b=1; tol=0.01; e=2/3;
% X=fibonacci(f,a,b,tol,e)



%If f is defined as an M-file function use the @ notation
% call X=fibonacci(@f,a,b,tol,e).
%If f is defined as an anonymous function use the
% call X=fibonacci(f,a,b,tol,e).

%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458


%Determine n
i=1;
F=1;
while F<=(b-a)/tol
    F=fib(i);
    i=i+1;
end

%Initialize values
n=i-1;
A=zeros(1,n-2);B=zeros(1,n-2);
A(1)=a;
B(1)=b;
c=A(1)+(fib(n-2)/fib(n))*(B(1)-A(1));
d=A(1)+(fib(n-1)/fib(n))*(B(1)-A(1));
k=1;

%Compute Iterates
while k<=n-3
    if f(c)>f(d)
        A(k+1)=c;
        B(k+1)=B(k);
        c=d;
        d=A(k+1)+(fib(n-k-1)/fib(n-k))*(B(k+1)-A(k+1));
    else
        A(k+1)=A(k);
        B(k+1)=d;
        d=c;
        c=A(k+1)+(fib(n-k-2)/fib(n-k))*(B(k+1)-A(k+1));
    end
    k=k+1;
end

%Last iteration using distinguishability constant e
if f(c)>f(d)
    A(n-2)=c;
    B(n-2)=B(n-3);
    c=d;
    d=A(n-2)+(0.5+e)*(B(n-2)-A(n-2));
else
    A(n-2)=A(n-3);
    B(n-2)=d;
    d=c;
    c=A(n-2)+(0.5-e)*(B(n-2)-A(n-2));
end

%Output: Use midpoint of last interval for abscissa
if f(c)>f(d)
    a=c;b=B(n-2);
else
    a=A(n-2);b=d;
end
X=[(a+b)/2 f((a+b)/2)];
        