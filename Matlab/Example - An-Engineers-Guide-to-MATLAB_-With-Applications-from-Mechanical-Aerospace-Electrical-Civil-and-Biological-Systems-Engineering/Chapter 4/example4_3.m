clc; clear; close all;

N = input('Enter the positive integer< 15: ');

Matr = zeros(N,N)

for r = 1:N;
    Matr(r,1:N) = ((r - 1)*N + 1):r*N;
end

disp(Matr)
