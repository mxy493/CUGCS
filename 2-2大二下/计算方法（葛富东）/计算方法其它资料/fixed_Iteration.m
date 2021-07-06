function [k,p,err,P] = fixed_Iteration(g,p0,tol,max1)

%Input   -  g is the iteration function
%           -  p0 is the initial guess for the fixed-point
%           -  tol is the tolerance
%           -  max1 is the maximum number of iterations
%Output-  k is the number of iterations
%           -  p is the approximation to the fixed-point
%           - err is the error in the approximation
%           -  P' contains the sequence {pn}



% f=@(x)  2*sqrt(x-1);
% p0=1; tol=1e-4; max1=500;
% fixed_Iteration(f, p0, tol, max1)



%If g is defined as an M-file function use the @ notation
% call [k,p,err,P]=fixed_Iteration(@g,p0,tol,max1).
%If g is defined as an anonymous function use the
% call [k,p,err,P]=fixed_Iteration(g,p0,tol,max1).

%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

P(1)= p0;

for k=2:max1
	P(k)=g(P(k-1));
	err=abs(P(k)-P(k-1));
	relerr=err/(abs(P(k))+eps);
	p=P(k);
	if (err<tol) | (relerr<tol),break;end
end

P=P'

