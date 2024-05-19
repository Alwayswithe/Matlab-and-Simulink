clc; clear; close all;

series = 1;
k = 2;
exact = pi^2/6;

while abs((series - exact)/exact) >= 1e-4
    series = series + 1/k^2;
    k = k + 1;
end

disp(['Number of terms = ' int2str(k-1)])