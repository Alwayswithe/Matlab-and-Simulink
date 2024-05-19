clc; clear; close all;

N = 4;
mm = 1:N;
nn = mm;

% [X,Y] = meshgrid(x,y)
% returns 2-D grid coordinates
% based on the coordinates contained
% in vectors x and y. X is a matrix
% where each row is a copy of x,
% and Y is a matrix where each column is a copy of y.
% The grid represented by the coordinates X
% and Y has length(y) rows and length(x) columns.

[n, m] = meshgrid(nn, mm)
h = 1./(m+n-1);
