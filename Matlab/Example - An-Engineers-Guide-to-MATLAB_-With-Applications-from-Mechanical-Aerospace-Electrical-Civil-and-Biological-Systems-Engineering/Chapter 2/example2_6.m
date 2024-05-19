clc; clear; close all;

r_box = linspace(0.5,1,3);
theta_box = linspace(0,pi/2,4);

% meshgrid

[r, theta] = meshgrid(r_box, theta_box);

x = r.*cos(theta)
y = r.*sin(theta)