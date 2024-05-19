clc; clear; close all;

A = magic(3);
B = A';
[rA, cA] = size(A);
[rB, cB] = size(B);

if ((rA~=rB)||(cA~=cB))
    error('Matrics must be the same size');
end

M = zeros(rA,cA)

for c = 1:cA
    for r = 1:rA
        M(r,c) = A(r,c)*B(r,c);
    end
end

disp(M)