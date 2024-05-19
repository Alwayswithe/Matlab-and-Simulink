clear; clc;

syms a b t

x = 2*b*cos(t) + b*cos(2*t);
y = 2*b*sin(t) - b*sin(2*t);

x_df = diff(x,t);
y_df = diff(y,t);

x_df_df = diff(diff(x,t));
y_df_df = diff(diff(y,t));


knum = (x_df*y_df_df) - (y_df*x_df_df);
kden = (x_df^2 + y_df^2);

knum_simple = simplify(knum);
kden_simple = simplify(kden);

k = knum_simple/(kden_simple^(3/2));
k = simplify(k)













