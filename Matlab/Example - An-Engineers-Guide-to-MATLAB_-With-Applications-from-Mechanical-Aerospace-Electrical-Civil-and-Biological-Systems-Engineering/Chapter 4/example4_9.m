clc; clear; close all;

c = [4, 4, 7, 10, -6, 42, 1, 0];

Csum = zeros(length(c), 1);
Csum(1) = c(1);

for i = 2:length(c)
    Csum(i) = Csum(i - 1) + c(i)
end
Csum

