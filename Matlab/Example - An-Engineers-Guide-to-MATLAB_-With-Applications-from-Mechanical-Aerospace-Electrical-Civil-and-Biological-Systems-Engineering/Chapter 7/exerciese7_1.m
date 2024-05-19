clc; clear; close all;

% Spherical helix6
c = 5.0;
phi = linspace(0, 10*pi,300);

x = sin(phi/2.*c).*cos(phi);
y = sin(phi/2.*c).*sin(phi);
z = cos(phi/2.*c);

plot3(x, y, z,'-k')
axis equal


%% Soroidal spiral

a2 = 0.2;
b2 = 0.8;
c2 = 20.0;
phi2 = linspace(0, 2*pi, 500);

x2 = (b2 + a2.*sin(c2.*phi2)).*cos(phi2);
y2 = (b2 + a2.*sin(c2.*phi2)).*sin(phi2);
z2 = a2.*cos(c2.*phi2);

plot3(x2, y2, z2,'-k')
axis equal


%% Sine wave on sphere

a3 = 10.0;
b3 = 1.0;
c3 = 0.3;
phi3 = linspace(0, 2*pi, 300);

x3 = cos(phi3).*sqrt(b3.^2 - (c3.^2).*cos(a3.*phi3).^2)
y3 = sin(phi3).*sqrt(b3.^2 - (c3.^2).*cos(a3.*phi3).^2)
z3 = c3.*cos(a3.*phi3);

plot3(x3, y3, z3,'-k')
axis equal


%% Concho spiral7

a4 = 1.0;
b4 = 1.05;
c4 = 2.0;
u4 = linspace(0, 2*pi, 300);

r4 = a4.*b4.^u4;
phi4 = u4;
z4 = c4.*b4.^u4;

plot3(r4, phi4, z4,'-k')
axis equal


%% Intersection of two cylinders8

a5 = 1.0;
b5 = 1.3;
phi5 = linspace(0, 2*pi, 300)


x5 = a5.*cos(phi5);
y5 = a5.*sin(phi5);
z5 = sqrt(b5.^2 - (a5.^2).*sin(phi5).^2);

plot3(x5, y5, z5,'-k')
axis equal


%% Baseball seam9


a6 = 0.4;
t = linspace(0, 4*pi, 300);

x6 = sin(pi/2 - (pi/2 - a6).*cos(t)).*cos(t/2 + a6.*sin(2.*t));
y6 = sin(pi/2 - (pi/2 - a6).*cos(t)).*sin(t/2 + a6.*sin(2.*t));
z6 = cos(pi/2 - (pi/2 - a6).*cos(t));

plot3(x6, y6, z6,'-k')
axis equal


%% Spherical spiral10

a7 = 0.08;
phi7 = linspace(-12*pi, 12*pi, 300);

x7 = cos(phi7).*cos(atan(a7.*phi7));
y7 = sin(phi7).*cos(atan(a7.*phi7));
z7 = -sin(atan(a7.*phi7));

plot3(x7, y7, z7,'-k')
axis equal








