function [P0,y0,err,P]=grads(F,G,P0,max1,delta,epsilon,show)

%Input    - F is the object function input as an M-file function 
%            - G = -(1/norm(grad F))*grad F; the search direction
%              input as an M-file function
%            - P0 is the initial starting point
%            - max1 is the maximum number of iterations
%            - delta is the tolerance for hmin in the single parameter
%              minimization in the search direction
%            - epsilon is the tolerance for the error in y0
%            - show; if show==1 the iterations are displayed
%Output - P0 is the point for the minimum.
%            - y0 is the function value  F(P0)
%            - err is the error bound for y0
%            - P is a vector containing the iterations

%Use @F and @G to call the M-file functions F and G.

%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

if nargin==5, show = 0; end
[mm n] = size(P0);
maxj = 10;  big = 1e8;  h = 1;
P=zeros(maxj,n+1);
len = norm(P0);
y0 = F(P0);
if (len>1e4), h = len/1e4; end
err = 1;cnt = 0;cond = 0;
P(cnt+1,:)=[P0 y0];

while (cnt<max1 & cond~=5 & (h>delta | err>epsilon))
   
  %Compute search direction
  S = G(P0);
  
  %Start single parameter quadratic minimization  
  P1 = P0 + h*S;
  P2 = P0 + 2*h*S;
  y1 = F(P1);
  y2 = F(P2);
  cond = 0; j = 0;
  while (j<maxj & cond==0)
     len = norm(P0);
     if (y0<y1)
      P2 = P1;
      y2 = y1;
      h = h/2;
      P1 = P0 + h*S;
      y1 = F(P1);
    else
      if (y2<y1)
        P1 = P2;
        y1 = y2;
        h = 2*h;
        P2 = P0 + 2*h*S;
        y2 = F(P2);
      else
        cond = -1;
      end
    end
    j = j+1;
    if (h<delta), cond=1; end
    if (abs(h)>big | len>big), cond=5; end
  end
  if (cond==5)
    Pmin = P1;
    ymin = y1;
  else
    d = 4*y1 - 2*y0 - 2*y2;     
    if (d<0)
      hmin = h*(4*y1-3*y0-y2)/d;
    else
      cond = 4;
      hmin = h/3;
    end
    
    %Construct the next point
    Pmin = P0 + hmin*S;
    ymin =F(Pmin);
    
    %Determine magnitude of next h
    h0 = abs(hmin);
    h1 = abs(hmin-h);
    h2 = abs(hmin-2*h);
    if (h0<h), h = h0; end
    if (h1<h), h = h1; end
    if (h2<h), h = h2; end
    if (h==0), h = hmin; end
    if (h<delta), cond=1; end
    
    %Termination test for minimization
    e0 = abs(y0-ymin);
    e1 = abs(y1-ymin);
    e2 = abs(y2-ymin);
    if (e0~=0 & e0<err), err = e0; end
    if (e1~=0 & e1<err), err = e1; end
    if (e2~=0 & e2<err), err = e2; end
    if (e0==0 & e1==0 & e2==0), err = 0; end
    if (err<epsilon), cond=2; end
    if (cond==2 & h<delta), cond=3; end
 end    
 cnt = cnt+1;
 P(cnt+1,:)=[Pmin ymin];
  P0 = Pmin;
  y0 = ymin; 
end

if (show==1)
   disp(P);
end

