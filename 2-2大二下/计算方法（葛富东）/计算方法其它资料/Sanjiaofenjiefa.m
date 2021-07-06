function X = Sanjiaofenjiefa(A,B)
%Input    - A is an N x N matrix
%	         - B is an N x 1 matrix
%Output - X is an N x 1 matrix containing the solution to AX = B.

%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

%Initialize X, Y,the temporary storage matrix C, and the row 
% permutation information matrix R

[N,N]=size(A);
X=zeros(N,1);
Y=zeros(N,1);
C=zeros(1,N);
R=1:N;

for p=1:N-1
   
   %Find the pivot row for column p
   [max1,j]=max(abs(A(p:N,p)));
   
   %Interchange row p and j
      C=A(p,:);
      A(p,:)=A(j+p-1,:);
      A(j+p-1,:)=C;
      d=R(p);
      R(p)=R(j+p-1);
      R(j+p-1)=d;

   if A(p,p)==0
      'A is singular.  No unique solution'
      break
   end

   %Calculate multiplier and place in subdiagonal portion of A
      for k=p+1:N
         mult=A(k,p)/A(p,p);
	 A(k,p) = mult;
         A(k,p+1:N)=A(k,p+1:N)-mult*A(p,p+1:N);
      end
end

%Solve for Y
Y(1) = B(R(1));
for k=2:N
   Y(k)= B(R(k))-A(k,1:k-1)*Y(1:k-1);
end

%Solve for X
X(N)=Y(N)/A(N,N);
for k=N-1:-1:1
   X(k)=(Y(k)-A(k,k+1:N)*X(k+1:N))/A(k,k);
end

