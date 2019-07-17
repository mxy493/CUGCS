function X = GaussXuanzhuyuan(A,B)

%Input    - A is an N x N nonsingular matrix
%	         - B is an N x 1 matrix
%Output - X is an N x 1 matrix containing the solution to AX=B.

%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

%Initialize X and the temporary storage matrix C 
[N N]=size(A);
X=zeros(N,1);
C=zeros(1,N+1);

%Form the augmented matrix: Aug=[A|B]
Aug=[A B];

for p=1:N-1
   %Partial pivoting for column p
   [Y,j]=max(abs(Aug(p:N,p)));
   %Interchange row p and j
   C=Aug(p,:);
   Aug(p,:)=Aug(j+p-1,:);
   Aug(j+p-1,:)=C;
  
   if Aug(p,p)==0
      'A was singular.  No unique solution'
     break
  end
  %Elimination process for column p
  for k=p+1:N
     m=Aug(k,p)/Aug(p,p);
     Aug(k,p:N+1)=Aug(k,p:N+1)-m*Aug(p,p:N+1);
  end
end

%Back Substitution on [U|Y] using Program 3.1
X=backsub(Aug(1:N,1:N),Aug(1:N,N+1));

