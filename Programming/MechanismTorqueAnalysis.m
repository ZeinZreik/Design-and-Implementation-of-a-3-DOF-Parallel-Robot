clear;
close all;
%% Input
inx = [-30:1:30]*pi/180;
iny = [-30:1:30]*pi/180;
inz = [-30:1:30]*pi/180;
Mx = zeros(3,length(inx));
My = zeros(3,length(iny));
Mz = zeros(3,length(inz));
tau = [1 1 1];
%% Positions
for i = 1:length(inx)
    M = TorqueTransmission(tau,[inx(i) 0 0]);
    Mx(1,i) = M(1);
    My(1,i) = M(2);
    Mz(1,i) = M(3);
end
for i = 1:length(iny)
    M = TorqueTransmission(tau,[0 iny(i) 0]);
    Mx(2,i) = M(1);
    My(2,i) = M(2);
    Mz(2,i) = M(3);
end
for i = 1:length(inz)
    M = TorqueTransmission(tau,[0 0 inz(i)]);
    Mx(3,i) = M(1);
    My(3,i) = M(2);
    Mz(3,i) = M(3);
end
for i = 1:3
    figure('Name',sprintf('Torque Transmission, moving on axis %.0f', i));
    hold on;
    plot(inx*180/pi, Mx(i,:),'o');
    plot(iny*180/pi, My(i,:),'*');
    plot(inz*180/pi, Mz(i,:),'--');
    hold off;
    legend('Torque through x','Torque through y', 'Torque through z')
end
