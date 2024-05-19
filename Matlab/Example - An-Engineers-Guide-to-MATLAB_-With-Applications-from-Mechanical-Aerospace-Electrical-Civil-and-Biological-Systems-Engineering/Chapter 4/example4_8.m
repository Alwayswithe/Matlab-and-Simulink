clc; clear; close all;

g = [4, 4, 7, 10, -6, 42, 1, 0];
a = 4;
k = 0;

indx = [];

for i = 1:length(g)
    if (g(i) > a)
        k = k + 1;
        indx(k) = g(i);
    end
end

indx