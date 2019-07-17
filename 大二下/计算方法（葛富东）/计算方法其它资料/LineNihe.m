function [A,B]=LineNihe(X,Y)

%Input    - X is the 1xn abscissa vector
%            - Y is the 1xn ordinate vector
%Output - A is the coeefficient of x in Ax + B
%            - B is the constant coefficient in Ax + B
% 
% x=[-1,0,1,2,3,4,5,6];
% y=[10,9,7,5,4,3,0,-1];
% scatter(x,y,'k');
% hold on
% [a,b]=LineNihe(x,y);
% c=-1:1:6;
% z=a*c+b;
% plot(c,z,'r')


%  NUMERICAL METHODS: Matlab Programs
% (c) 2004 by John H. Mathews and Kurtis D. Fink
%  Complementary Software to accompany the textbook:
%  NUMERICAL METHODS: Using Matlab, Fourth Edition
%  ISBN: 0-13-065248-2
%  Prentice-Hall Pub. Inc.
%  One Lake Street
%  Upper Saddle River, NJ 07458

xmean=mean(X);
ymean=mean(Y);
sumx2=(X-xmean)*(X-xmean)';
sumxy=(Y-ymean)*(X-xmean)';
A=sumxy/sumx2;
B=ymean-A*xmean;

