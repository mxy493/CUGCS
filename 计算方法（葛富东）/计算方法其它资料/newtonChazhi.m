function C=newtonChazhi(X,Y)

%Input     - X is a vector that contains a list of abscissas
%             - Y is a vector that contains a list of ordinates
%Output  - C is a vector that contains the coefficients
%               of the Newton intepolatory polynomial
%             - D is the divided difference table



% X=[0,1,2,4];  Y=[1,9,23,3];
% C=newtonChazhi(X,Y)


%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

n=length(X);
D=zeros(n,n);
D(:,1)=Y';

%Use formula (20) to form the divided difference table

for j=2:n
   for k=j:n
      D(k,j)=(D(k,j-1)-D(k-1,j-1))/(X(k)-X(k-j+1));
   end
end

%Determine the coefficients of the Newton interpolatory polynomial

C=D(n,n);

for k=(n-1):-1:1
   C=conv(C,poly(X(k)));
   m=length(C);
   C(m)=C(m)+D(k,k);
end

