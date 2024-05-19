clc; clear; close all;

[X,Y] = meshgrid(1:0.5:10,1:20);
Z = sin(X) + cos(Y);
surf(X,Y,Z)

View_user = input('Enter the view reg, top, rside or lside: ','s');

switch View_user
    case 'reg'
        view(-37.5, 30)
    case 'top'
        view(-90, 90)
    case 'rside'
        view(0, 0)
    case 'lside'
        view(-90, 0)
    otherwise
        error('No such view')
end
