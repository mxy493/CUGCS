function X = zhuiganfa(A,B)
[N,N]=size(A);
X=zeros(N,1);   Y=zeros(N,1);
C=zeros(1,N);  R=1:N;
for p=1:N-1
   [max1,j]=max(abs(A(p:N,p)));
      C=A(p,:);
      A(p,:)=A(j+p-1,:);
      A(j+p-1,:)=C;
      d=R(p);
      R(p)=R(j+p-1);
      R(j+p-1)=d;
 if A(p,p)==0
      'A is singular.  No unique solution';
      break
 end
      for k=p+1:N
         mult=A(k,p)/A(p,p);
     A(k,p) = mult;
         A(k,p+1:N)=A(k,p+1:N)-mult*A(p,p+1:N);
      end
end
Y(1) = B(R(1));
for k=2:N
   Y(k)= B(R(k))-A(k,1:k-1)*Y(1:k-1);
end
X(N)=Y(N)/A(N,N);
for k=N-1:-1:1
   X(k)=(Y(k)-A(k,k+1:N)*X(k+1:N))/A(k,k);
end
X=vpa(X,6)
