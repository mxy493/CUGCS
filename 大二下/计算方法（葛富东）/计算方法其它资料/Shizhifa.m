function [c,err,yc]=Shizhifa(f,a,b,delta,epsilon,max1)

%Input    - f is the function 
%	         - a and b are the left and right endpoints
%	         - delta is the tolerance for the zero
%	         - epsilon is the tolerance for the value of f at the zero
%	         - max1 is the maximum number of iterations
%Output - c is the zero
%	         - yc=f(c)
%	         - err is the error estimate for c

%Р§зг
% f=@(x)  10.*sin(x)-exp(x);
%  Shizhifa(f, 0, 1, 0.01, 0.01, 30)


%If f is defined as an M-file function use the @ notation
% call [c,err,yc]=regula(@f,a,b,delta,epsilon,max1)
%If f is defined as an anonymous function use the
% call [c,err,yc]=regula(f,a,b,delta,epsilon,max1)

%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

ya=f(a);
yb=f(b);

if ya*yb>0
	disp('Note: f(a)*f(b) >0'),
	return,
end

for k=1:max1
	dx=yb*(b-a)/(yb-ya);
	c=b-dx;
	ac=c-a;
	yc=f(c);
	if yc==0,break;
	elseif yb*yc>0
		b=c;
		yb=yc;
	else
		a=c;
		ya=yc;
	end
	dx=min(abs(dx),ac);
	if abs(dx)<delta,break,end
	if abs(yc)<epsilon, break,end
end

c;
err=abs(b-a)/2;
yc=f(c);

