function S=SanciyangtiaoChazhi(X,Y,dx0,dxn)

%Input    - X is the 1xn abscissa vector
%         - Y is the 1xn ordinate vector
%         - dxo = S'(x0) first derivative boundary condition
%         - dxn = S'(xn) first derivative boundary condition
%Output   - S: rows of S are the coefficients for the cubic interpolants



% X=[0,1,2,3];  Y=[0,0.5,2,1.5];  dx0=0.2; dxn=-1;
% C=SanciyangtiaoChazhi(X,Y,dx0,dxn)
% »­Í¼
% x1=0:0.01:1; y1=polyval(C(1,:),x1-X(1));  x2=1:0.01:2; y2=polyval(C(2,:),x2-X(2));
%x3=2:0.01:3; y3=polyval(C(3,:),x3-X(3)); plot(x1,y1,x2,y2,x3,y3,X,Y,'.')


%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

N=length(X)-1;
H=diff(X);
D=diff(Y)./H;
A=H(2:N-1);
B=2*(H(1:N-1)+H(2:N));
C=H(2:N);
C=H(2:N);
U=6*diff(D);

%Clamped spline endpoint constraints

B(1)=B(1)-H(1)/2;
U(1)=U(1)-3*(D(1)-dx0);
B(N-1)=B(N-1)-H(N)/2;
U(N-1)=U(N-1)-3*(dxn-D(N));

for k=2:N-1
   temp=A(k-1)/B(k-1);
   B(k)=B(k)-temp*C(k-1);
   U(k)=U(k)-temp*U(k-1);
end

M(N)=U(N-1)/B(N-1);

for k=N-2:-1:1
   M(k+1)=(U(k)-C(k)*M(k+2))/B(k);
end

%Clamped spline endpoint constraints

M(1)=3*(D(1)-dx0)/H(1)-M(2)/2;
M(N+1)=3*(dxn-D(N))/H(N)-M(N)/2;

for k=0:N-1
   S(k+1,1)=(M(k+2)-M(k+1))/(6*H(k+1));
   S(k+1,2)=M(k+1)/2;
   S(k+1,3)=D(k+1)-H(k+1)*(2*M(k+1)+M(k+2))/6;
   S(k+1,4)=Y(k+1);
end




