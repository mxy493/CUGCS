function X=jacobi(A,B,P,delta, max1)

% Input    - A is an N x N nonsingular matrix
%             - B is an N x 1 matrix
%             - P is an N x 1 matrix; the initial guess
%	          - delta is the tolerance for P
%	          - max1 is the maximum number of iterations
% Output - X is an N x 1 matrix: the jacobi approximation to
%	            the solution of AX = B

%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

N = length(B);

for k=1:max1
   for j=1:N
      X(j)=(B(j)-A(j,[1:j-1,j+1:N])*P([1:j-1,j+1:N]))/A(j,j);
   end
   err=abs(norm(X'-P));
   relerr=err/(norm(X)+eps);
   P=X';
      if (err<delta)|(relerr<delta)
     break
   end
end

X=X';


