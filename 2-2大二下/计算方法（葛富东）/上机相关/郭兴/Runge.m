clear
clc
x=-5:1:5
y=1./(1+x.^2);
plot(x,y);
xx=4.97;
yy=0;
for i=1:11
    temp=y(i);
    for j=1:11
        if j~=i
            temp=temp*(xx-x(j))/(x(i)-x(j));
        end
    end
    yy=yy+temp;
end
plot(x,yy);
fprintf('\nf(%f) = %f',xx,1/(1+xx*xx));
fprintf('\n��ֵ����ʽ��x = %fʱ��y = %f\n',xx,yy)
