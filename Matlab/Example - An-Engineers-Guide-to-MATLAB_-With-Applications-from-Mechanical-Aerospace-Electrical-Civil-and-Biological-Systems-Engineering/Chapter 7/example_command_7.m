clc; clear; close all;

[x, y, z] = SurfExample;

figure(1)
surf(x, y, z)

figure(2)
mesh(x, y, z)

figure(3)
mesh(x, y, z)
hidden off

figure(4)
mesh(x, y, z)
grid off


figure(5)
mesh(x, y, z)
axis off
grid off

figure(5)
mesh(x, y, z)
box on
axis on
grid off

figure(6)
meshz(x, y, z)

figure(7)
waterfall(x, y, z)


function [x, y, z] = SurfExample
    x1 = linspace(-3, 3, 15);
    y1 = linspace(-3, 13, 17);
    [x, y] = meshgrid(x1, y1);
    z = x.^4 + 3*x.^2 - 2*x + 6 - 2*y.*x.^2 + y.^2 - 2*y;
end