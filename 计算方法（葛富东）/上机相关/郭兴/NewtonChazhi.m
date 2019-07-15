function C=NewtonChazhi(X,Y,t)
 
%Input    - X is a vector that contains a list of abscissas
%            - Y is a vector that contains a list of ordinates
%Output - C is a matrix that contains the coefficents of
%              the Lagrange interpolatory polynomial
% - L is a matrix that contains the Lagrange coefficient polynomials
% X=[0,1,2,4];  Y=[1,9,23,3];  C=lagrangeChazhi(X,Y)
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
%Determine the coefficients of the Lagrange interpolator polynomial
C=Y*L;
T=C(1)*t^6+C(2)*t^5+C(3)*t^4+C(4)*t^3+C(5)*t^2+C(6)*t+C(7)