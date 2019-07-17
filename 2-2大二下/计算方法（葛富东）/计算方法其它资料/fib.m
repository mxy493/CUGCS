function y=fib(n)
%Generates fibonacci numbers for the program fibonacci
fz(1)=1;fz(2)=1;
for k=3:n
    fz(k)=fz(k-1)+fz(k-2);
end
y=fz(n);