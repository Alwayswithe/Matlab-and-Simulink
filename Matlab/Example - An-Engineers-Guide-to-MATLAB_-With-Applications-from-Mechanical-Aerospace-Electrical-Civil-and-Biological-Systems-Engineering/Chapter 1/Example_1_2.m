clc; clear;

g = 9.8;
d = 2;
theta = pi/3;
Dc = (d/2)*(1 - cos(theta));


Qnum = 2^(3/2)*Dc^(5/2)*sqrt(g)*...
    (theta - 0.5*sin(2*theta))^(3/2);
Qden = 8*sqrt(sin(theta))*...
    (1 - cos(theta))^(5/2);

Q = Qnum/Qden

















