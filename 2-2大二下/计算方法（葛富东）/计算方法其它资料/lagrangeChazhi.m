function C=lagrangeChazhi(X,Y)

%Input    - X is a vector that contains a list of abscissas
%            - Y is a vector that contains a list of ordinates
%Output - C is a matrix that contains the coefficents of
%              the Lagrange interpolatory polynomial
%            - L is a matrix that contains the Lagrange
%              coefficient polynomials


% X=[0,1,2,4];  Y=[1,9,23,3];
% [C,L]=lagrangeChazhi(X,Y)

%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

w=length(X);
n=w-1;
L=zeros(w,w);

%Form the Lagrange coefficient polynomials

for k=1:n+1
   V=1;
   for j=1:n+1
      if k~=j
         V=conv(V,poly(X(j)))/(X(k)-X(j));
      end
   end
   L(k,:)=V;
end

%Determine the coefficients of the Lagrange interpolator
%polynomial

C=Y*L;

   