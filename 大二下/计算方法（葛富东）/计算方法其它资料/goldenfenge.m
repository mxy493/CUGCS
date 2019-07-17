function [S,E,G]=goldenfenge(f,a,b,delta,epsilon)

%Input    - f is the object function 
%            - a and b are the endpoints of the interval
%            - delta is the tolerance for the abscissas £¨ºá×ø±ê£©
%            - epsilon is the tolerance for the ordinates £¨×Ý×ø±ê£©
%Output - S=(p,yp) contains the abscissa p and
%              the ordinate yp of the minimum
%            - E=(dp,dy) contains the error bounds for p and yp
%            - G is an n x 4 matrix: the kth row contains [ak ck dk bk];
%              the values of a, c, d, and b at the kth iteration

% f=@(x) sin(x)+exp(x);
% a=0; b=1; delta=0.001; epsilon=0.001;
% [S,E,G]=goldenfenge(f,a,b,delta,epsilon)

%If f is defined as an M-file function use the @ notation
% call [S,E,G]=golden(@f,a,b,delta,epsilon).
%If f is defined as an anonymous function use the
% call [S,E,G]=golden(f,a,b,delta,epsilon).

%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

r1=(sqrt(5)-1)/2;
r2=r1^2;
h=b-a;
ya=f(a);
yb=f(b);
c=a+r2*h;
d=a+r1*h;
yc=f(c);
yd=f(d);
k=1;
A(k)=a; B(k)=b; C(k)=c; D(k)=d;

while (abs(yb-ya)>epsilon)|(h>delta)
   k=k+1;
   if (yc<yd)
      b=d;
      yb=yd;
      d=c;
      yd=yc;
      h=b-a;
      c=a+r2*h;
      yc=f(c);
   else
      a=c;
      ya=yc;
      c=d;
      yc=yd;
      h=b-a;
      d=a+r1*h;
      yd=f(d);
   end
   A(k)=a; B(k)=b; C(k)=c; D(k)=d;
end

dp=abs(b-a);
dy=abs(yb-ya);
p=a;
yp=ya;

if (yb<ya)
   p=b;
   yp=yb;
end

G=[A' C' D' B'];
S=[p yp];
E=[dp dy];

