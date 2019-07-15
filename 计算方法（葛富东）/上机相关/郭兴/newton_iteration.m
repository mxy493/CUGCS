function [p0,err,k,y]=newton_iteration(f,df,p0,delta,epsilon,max1)
for k=1:max1    
    p1=p0-f(p0)/df(p0); 
    err=abs(p1-p0);
    relerr=2*err/(abs(p1)+delta);
    p0=p1;
    y=f(p0);
    if (err<delta)|(relerr<delta)|(abs(y)<epsilon),
   break,
   end
end
a=vpa(p0,9)

% ²âÊÔ£ºnewton_iteration(@f,@df,0.7,10^-9,10^-9,500)