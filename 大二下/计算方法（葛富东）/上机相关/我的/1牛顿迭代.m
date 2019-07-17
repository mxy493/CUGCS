function x=sqrt_newton(a)

# 牛顿迭代法求sqrt(5)

f=@(x)x^2-a;
df=diff(sym('x^2-a'));
if a<0
warning('负数没有实平方根');
x1=[];
elseif a==0;
x1=a;
else
x0=a;
x1=x0-f(x0)/subs(df,x0);
while abs(x1-x0)>1e-6
x0=x1;
x1=x0-f(x0)/subs(df,x0);
end
end
x=x1;

function [p0,err,k,y] = newton(p0,delta,max1)

for k=1:max1
p1=(p0+A/p0)/2;
err=abs(p1-p0);
relerr=2*err/(abs(p1)+delta);

if(err<delta)|(relerr<delta),break,end
end