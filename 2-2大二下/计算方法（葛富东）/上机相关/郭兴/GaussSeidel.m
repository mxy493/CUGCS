function X=GaussSeidel(A,B,P,delta, max1)

% GaussSeidel([4 1 -1 0;1 -5 -1 -3;2 -1 -6 1;5 4 4 30],[8;1;-1;16],[0;0;0;0],10^-9,100)

N = length(B);
 
for k=1:max1
   for j=1:N
      if j==1
        X(1)=(B(1)-A(1,2:N)*P(2:N))/A(1,1);
      elseif j==N
         X(N)=(B(N)-A(N,1:N-1)*(X(1:N-1))')/A(N,N);
      else
        X(j)=(B(j)-A(j,1:j-1)*X(1:j-1)'-A(j,j+1:N)*P(j+1:N))/A(j,j);
      end
   end
   err=abs(norm(X'-P));
   relerr=err/(norm(X)+eps);
   P=X';
      if (err<delta)|(relerr<delta)
     break
   end
end
X=X';
 