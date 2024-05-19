clc; clear; close all;

H = [17, 12, 12, -6, 0, -14];
N = length(H);

box = 0;

for i = 1:(N - 1)
    for j = (i + 1):N
        if H(i) > H(j)
            box = H(i);
            H(i) = H(j);
            H(j) = box;
        end
    end
end

disp(H)