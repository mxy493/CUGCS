function  [L,n]=ShuzhiChafen(f,x,toler)

%Input     - f is the function 
%            - x is the differentiation point
%            - toler is the desired tolerance
%Output - L=[H' D' E']: H is the vector of step sizes
%              D is the vector of approximate derivatives
%              E is the vector of error bounds
%            - n is the coordinate of the "best approimation"

%f=@(x) 20.*x.^3+sin(x)-6.*x-3;  t=1; toler=0.001;
% [L,n]=ShuzhiChafen(f,t,toler)

% If f is an M-file function use the call [L,n]=difflim(@f,x,toler).
% If f is an anonymous function use the call [L,n]=difflim(f,x,toler).

%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

max1=15;
h=1;
H(1)=h;
D(1)=(f(x+h)-f(x-h))/(2*h);
E(1)=0;
R(1)=0;

for n=1:2
   h=h/10;
   H(n+1)=h;
   D(n+1)=(f(x+h)-f(x-h))/(2*h);
   E(n+1)=abs(D(n+1)-D(n));
   R(n+1)=2*E(n+1)*(abs(D(n+1))+abs(D(n))+eps);
end

n=2;

while((E(n)>E(n+1))&(R(n)>toler))&n<max1
   h=h/10;
   H(n+2)=h;
   D(n+2)=(f(x+h)-f(x-h))/(2*h);
   E(n+2)=abs(D(n+2)-D(n+1));
   R(n+2)=2*E(n+2)*(abs(D(n+2))+abs(D(n+1))+eps);
   n=n+1;
end

n=length(D)-1;
L=[H' D' E'];

