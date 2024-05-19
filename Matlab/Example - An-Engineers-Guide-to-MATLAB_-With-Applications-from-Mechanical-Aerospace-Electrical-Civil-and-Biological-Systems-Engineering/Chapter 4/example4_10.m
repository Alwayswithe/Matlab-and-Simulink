clc; clear; close all;

n = input('Enter the order of the square matrix: ');

k = 1:n;
M = zeros(n, n);

x = 1;

for i = 1:n
    for j = 1:n
        if rem(i,2) ~= 0
            if rem(j,2) == 0
                disp(-x)
            else
                disp(x)
            end
        else
            if rem(j,2) == 0
                disp(x)
            else
                disp(-x)
            end
        end
    end
end

OddRow = (-1).^(k-1);
EvenRow = (-1).^k;

for m = 1:2:n
    M(m,:) = OddRow;
    if m+1 <= n
    M(m+1,:) = EvenRow;
    end
end
disp(M)










