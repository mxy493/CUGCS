function [V0,y0,dV,dy]=nelder(F,V,min1,max1,epsilon,show)

%Input     - F is input as an M-file function
%             - V is a 3xn matrix containing starting simplex
%             - min1 & max1 are minimum and maximum number of iterations
%             - epsilon is the tolerance
%             - show == 1 displays iterations (P and Q)
%Output  - V0 is the vertex forthe minimum
%             - y0 is the function value F(V0)
%             - dV is the size of the final simplex
%             - dy is the error bound for the minimum
%             - P is a matrix containing the vertex iterations
%             - Q is an array containing the iterations for F(P)

%Call  [V0,y0,dV,dy]=nelder(@F,V,min1,max1,epsilon,show)

%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

if nargin==5,
   show=0;
end

[mm n]=size(V);

% Order the vertices
for j=1:n+1
   Z=V(j,1:n);
   Y(j)=F(Z);
end

[mm lo]=min(Y);
[mm hi]=max(Y);
li=hi;
ho=lo;

for j=1:n+1
   if(j~=lo&j~=hi&Y(j)<=Y(li))
      li=j;
   end
   if (j~=hi&j~=lo&Y(j)>=Y(ho))
      ho=j;
   end
end

cnt=0;

%  Start of Nelder-Mead algorithm
while (Y(hi)>Y(lo)+epsilon&cnt<max1)|cnt<min1
   S=zeros(1:n);
   for j=1:n+1
      S=S+V(j,1:n);
   end
   M=(S-V(hi,1:n))/n;
   R=2*M-V(hi,1:n);
   yR=F(R);
   if (yR<Y(ho))
      if (Y(li)<yR)
         V(hi,1:n)=R;
         Y(hi)=yR;
      else
         E=2*R-M;
         yE=F(E);
         if (yE<Y(li))
            V(hi,1:n)=E;
            Y(hi)=yE;
         else
            V(hi,1:n)=R;
            Y(hi)=yR;
         end
      end
   else
      if (yR<Y(hi))
         V(hi,1:n)=R;
         Y(hi)=yR;
      end
      C=(V(hi,1:n)+M)/2;
      yC=F(C);
      C2=(M+R)/2;
      yC2=F(C2);
      if (yC2<yC)
         C=C2;
         yC=yC2;
      end
      if (yC<Y(hi))
         V(hi,1:n)=C;
         Y(hi)=yC;
      else
         for j=1:n+1
            if (j~=lo)
               V(j,1:n)=(V(j,1:n)+V(lo,1:n))/2;
               Z=V(j,1:n);
               Y(j)=F(Z);
            end
         end
      end
   end
   [mm lo]=min(Y);
   [mm hi]=max(Y);
   li=hi;
   ho=lo;
   for j=1:n+1
      if (j~=lo&j~=hi&Y(j)<=Y(li))
         li=j;
      end
      if (j~=hi&j~=lo&Y(j)>=Y(ho))
         ho=j;
      end
   end
   cnt=cnt+1;
   P(cnt,:)=V(lo,:);
   Q(cnt)=Y(lo);
end

% End of Nelder-Mead algorithm

%Determine size of simplex
snorm=0;
for j=1:n+1
   s=norm(V(j)-V(lo));
   if(s>=snorm)
      snorm=s;
   end
end

Q=Q';
V0=V(lo,1:n);
y0=Y(lo);
dV=snorm;
dy=abs(Y(hi)-Y(lo));

if (show==1)
    disp([P Q])
end

