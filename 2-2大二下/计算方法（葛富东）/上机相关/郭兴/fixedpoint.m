function[k,p,err,P]=fixedpoint(g,p0,to1,max1)
P(1)=p0;
for k=2:max1
    P(k)=feval(g,P(k-1));
    err=abs(P(k)-P(k-1));
    relerr=err/(abs(P(k))+eps);
    p=P(k);
    if(err<to1)|(relerr<to1),break;
    end
end
if k==max1
    disp('maximum number of iterations exceeded')
end
P=P';
a=vpa(P,9)