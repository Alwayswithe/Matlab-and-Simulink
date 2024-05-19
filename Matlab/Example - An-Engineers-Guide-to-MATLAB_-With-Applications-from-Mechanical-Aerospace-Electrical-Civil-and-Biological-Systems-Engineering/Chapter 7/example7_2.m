clc; clear; close all;

a = 10;
b = 1.0;
c = 0.3;

t = linspace(0, 2*pi, 200)

x = b*cos(t);
y = b*sin(t);
z = c*cos(a*t);

plot3(x, y, z,'-k')

% Dat ti le khung hinh
% sao cho cac du lieu giong nhau theo moi huong;
axis equal
