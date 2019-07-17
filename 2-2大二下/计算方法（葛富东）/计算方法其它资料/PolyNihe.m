function C = PolyNihe(X,Y,M)

%Input     - X is the 1xn abscissa vector
%             - Y is the 1xn ordinate vector
%             - M is the degree of the least-squares polynomial
% Output - C is the coefficient list for the polynomial
% 
% 
% x=[-3,0,2,4];
% y=[3,1,1,3];
% scatter(x,y,'k');
% hold on
% M=2;
% a=PolyNihe(x,y,M);
% t=-3:1:4;
% z=0;
% for i=1:1:M+1
%  z=z+a(i).*t.^(M-i+1);   
% end
% plot(t,z,'r')


%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

n=length(X);
B=zeros(1:M+1);
F=zeros(n,M+1);

%Fill the columns of F with the powers of X

for k=1:M+1
   F(:,k)=X'.^(k-1);
end

%Solve the linear system from (25)

A=F'*F;
B=F'*Y';
C=A\B;
C=flipud(C);

