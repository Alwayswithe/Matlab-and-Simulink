clc; clear; close all;

% Doi vi tri cac matrix trong Mactric;

Matric = [1:9; 10:18; 19:27; 28:36; 37:45; 46:54; 55:63; 64:72; 73:81];

Temp1 = Matric(1:3, 1:3);
Temp2 = Matric(1:3, 7:9);
Temp3 = Matric(7:9, 7:9);
Temp4 = Matric(7:9, 1:3);

Matric(7:9, 7:9) = Temp1;
Matric(7:9, 1:3) = Temp2;
Matric(1:3, 7:9) = Temp4;
Matric(1:3, 1:3) = Temp3;

Matric









