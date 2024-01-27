clear;
close all;

%% input and constants
in = [0 0 0]*pi/180;
%% 

%% inverse kinematics
[thetaMotor,theta] = InverseKinematics(in);
%% 

%% Open Serial Communication
SPM = serial('COM8','BaudRate',115200);
fopen(SPM); 
pause(2);
%% Send
out = string(thetaMotor(1))+','+string(thetaMotor(2))+','+string(thetaMotor(3));
fprintf(SPM,out);
%% Close Serial Communication
fclose(SPM);