clc; clear; close all;

t = linspace(0,2*pi,50);
f_t = sin(t);

% Tinh trung binh cua f_t ma co f_t < 0;
fAvgNeg = mean(f_t(find(f_t < 0)))

% Tim gia tri nho nhat cua f_t voi f_t > 0;
fMinPos = min(f_t(find(f_t > 0))) 

tValue_fMinpos = t(find(f_t == fMinPos))








