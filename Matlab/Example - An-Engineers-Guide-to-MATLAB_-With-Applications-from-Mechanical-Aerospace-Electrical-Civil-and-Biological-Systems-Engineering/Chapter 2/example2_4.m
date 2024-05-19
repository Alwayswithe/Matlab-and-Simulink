clc; clear; close all;

k = 1:8;
y = 2.^k;

t = linspace(0,1,6);
a =0.2;
b = 0.9;
c = pi/6;

q = exp(-a*t);
vTren = sin(b*t + c);
vDuoi = t + c;

v = q.*vTren./vDuoi

