function [p1,err,k,y]=Gexianfa_Iteration(f,p0,p1,delta,epsilon,max1)

%Input    - f is the object function 
%            - p0 and p1 are the initial approximations to a zero of f        
%	         - delta is the tolerance for p1
%	         - epsilon is the tolerance for the function values y
%	         - max1 is the maximum number of iterations
%Output - p1 is the secant method approximation to the zero
%	         - err is the error estimate for p1
%	         - k is the number of iterations
%	         - y is the function value f(p1)



% f=@(x)  x*exp(x)-1;  ;
% p0=1; p1=1.2; delta=1e-4; epsilon=1e-3;  max1=500; 
% Gexianfa_Iteration(f,p0, p1, delta, epsilon, max1)


%If f is defined as an M-file function use the @ notation
% call [c,err,yc]=bisect(@f,a,b,delta).
%If f is defined as an anonymous function use the
% call [c,err,yc]=bisect(f,a,b,delta).

%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

for k=1:max1	
	p2=p1-f(p1)*(p1-p0)/(f(p1)-f(p0));	
	err=abs(p2-p1);
	relerr=2*err/(abs(p2)+delta);
	p0=p1;
	p1=p2;
	y=f(p1);
	if (err<delta)|(relerr<delta)|(abs(y)<epsilon),break,end
end

