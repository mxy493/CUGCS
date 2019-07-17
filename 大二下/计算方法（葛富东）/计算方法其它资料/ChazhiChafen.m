function [A,df]=ChazhiChafen(X,Y)

%Input     - X is the 1xn abscissa vector
%             - Y is the 1xn ordinate vector
%Output  - A is the 1xn vector containing the coefficients of the Nth
%              degree Newton polynomial
%             - df is the approximate derivative

% x=0:0.1:1.5;  y=x.^2+sin(x);
% [A,df]=ChazhiChafen(x,y)


%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

A=Y;
N=length(X);

for j=2:N
   for k=N:-1:j
      A(k)=(A(k)-A(k-1))/(X(k)-X(k-j+1));
   end
end

x0=X(1);
df=A(2);
prod=1;
n1=length(A)-1;

for k=2:n1
   prod=prod*(x0-X(k));
   df=df+prod*A(k+1);
end

