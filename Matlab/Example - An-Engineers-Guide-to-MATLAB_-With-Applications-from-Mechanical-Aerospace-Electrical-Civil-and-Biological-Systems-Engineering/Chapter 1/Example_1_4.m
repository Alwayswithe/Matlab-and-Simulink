clc; clear;

syms j n r t;

r = sqrt(1 - j^2);

x = exp(j*n)*sin(r*(t - n));
y = exp(-j*t)*int(x,n,0,t)/r;
Y = simplify(y)