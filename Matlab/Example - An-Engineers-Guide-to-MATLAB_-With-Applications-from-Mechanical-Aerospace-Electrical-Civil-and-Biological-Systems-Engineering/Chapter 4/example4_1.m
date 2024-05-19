clc; clear; close all;

syms lode C_load;
syms d C_size;
syms T C_temp;

if lode == 'Bending'
    C_load = 1;
elseif lode == 'Axial'
    C_load = 0.7;
else
    error('No such loading');
end

if d <= 8
    C_size = 1;
elseif d >= 8 && d <= 250
    C_size = 1.189*d^-0.097;
else
    error('No such loading');
end

if T < 450
    C_temp = 1;
elseif 450 <= T
    C_temp = 1 - 0.0032*(T - 840);
else
    error('No such loading');
end













