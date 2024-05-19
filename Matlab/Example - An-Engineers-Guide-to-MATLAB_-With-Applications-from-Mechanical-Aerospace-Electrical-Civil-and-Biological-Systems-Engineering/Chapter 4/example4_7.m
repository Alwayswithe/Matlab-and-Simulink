clc; clear; close all;

loan = input('Enter loan amount: ');
durat = input ('Enter ternm of loan in months: ');
int = input('Enter annual interest rate(%): ')/1200;
ints = zeros(durat,1);
prins = ints;
bals = ints;
pmon = (loan*int)/(1 - (1 + int)^(-durat));
bals(1) = loan;

for m = 2:durat + 1
    ints(m) = int*bals(m - 1);
    prins(m) = pmon - ints(m);
    bals(m) = bals(m-1)-prins(m);
end

fprintf(1,'Total interest = $%8.2f /n', sum(ints))