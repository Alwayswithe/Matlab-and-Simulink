clc; clear; close all;

N = input("Enter a positive integer < 6: ");
cnt = 0;
a = ones(N,N) - eye(N);
A = zeros(N^2,N^2);

for c = 1:N
    row = ((c - 1)*N + 1):c*N;
    for r = 1:N
        cnt = cnt + 1;
        col = ((r - 1)*N + 1):r*N;
        A(row, col) = cnt*a;
    end
end

disp(A)