function [M] = TorqueTransmission(tau, in)
    %% Constants
    Qx = [1 0 0; ...
         0 cos(in(1)) -sin(in(1)); ...
         0 sin(in(1))  cos(in(1))];
    Qy = [cos(in(2)) 0 -sin(in(2)); ...
          0        1 0; ...
          sin(in(2)) 0 cos(in(2));];
    Qz = [cos(in(3)) -sin(in(3)) 0; ...
         sin(in(3))  cos(in(3)) 0; ...
         0          0     1];
    Q = Qz*Qy*Qx;
    gamma = 0;beta = pi/2;
    alpha1 = pi/3;alpha2 = 0.9831;
    eta = [0 2*pi/3 4*pi/3];
    %% inverse kinematics
    v = Q*[-sin(eta(1))*sin(beta) sin(eta(3))*sin(beta) sin(eta(2))*sin(beta);...
           cos(eta(1))*sin(beta)  cos(eta(3))*sin(beta)  cos(eta(2))*sin(beta);...
           cos(beta)              cos(beta)              cos(beta)];

    [thetaMotor,theta] = InverseKinematics(in);

    %% 

    %% jacobian matrix  
    thetaMotor(1) = thetaMotor(1)*pi/180+50.1919*pi/180;
    thetaMotor(2) = thetaMotor(2)*pi/180+2*pi/3+50.1919*pi/180;
    thetaMotor(3) = thetaMotor(3)*pi/180-2*pi/3+50.1919*pi/180;
    
    u = [-sin(eta(1))*sin(gamma) -sin(eta(2))*sin(gamma) -sin(eta(3))*sin(gamma);...
         cos(eta(2))*sin(gamma)  cos(eta(2))*sin(gamma)  cos(eta(3))*sin(gamma);...
         -cos(gamma)             -cos(gamma)             -cos(gamma)];

%     w = [[(sin(alpha1)*(cos(eta(1))*sin(theta(1))-sin(eta(1))*cos(gamma)*cos(theta(1)))-cos(alpha1)*sin(eta(1))*sin(gamma)) ...
%           (sin(alpha1)*(cos(eta(2))*sin(theta(2))-sin(eta(2))*cos(gamma)*cos(theta(2)))-cos(alpha1)*sin(eta(2))*sin(gamma)) ...
%           (sin(alpha1)*(cos(eta(3))*sin(theta(3))-sin(eta(3))*cos(gamma)*cos(theta(3)))-cos(alpha1)*sin(eta(3))*sin(gamma))];...
%          [(sin(alpha1)*(sin(eta(1))*sin(theta(1))+cos(eta(1))*cos(gamma)*cos(theta(1)))+cos(alpha1)*cos(eta(1))*sin(gamma)) ...
%           (sin(alpha1)*(sin(eta(2))*sin(theta(2))+cos(eta(2))*cos(gamma)*cos(theta(2)))+cos(alpha1)*cos(eta(2))*sin(gamma)) ...
%           (sin(alpha1)*(sin(eta(3))*sin(theta(3))+cos(eta(3))*cos(gamma)*cos(theta(3)))+cos(alpha1)*cos(eta(3))*sin(gamma))];... 
%          [sin(alpha1)*sin(gamma)*cos(theta(1))-cos(alpha1)*cos(gamma) ... 
%           sin(alpha1)*sin(gamma)*cos(theta(2))-cos(alpha1)*cos(gamma) ...
%           sin(alpha1)*sin(gamma)*cos(theta(3))-cos(alpha1)*cos(gamma)]];   
    w = [sin(alpha1)*sin(thetaMotor(1)) sin(alpha1)*sin(thetaMotor(3)) sin(alpha1)*sin(thetaMotor(2)); ...
         sin(alpha1)*cos(thetaMotor(1)) sin(alpha1)*cos(thetaMotor(3))  sin(alpha1)*cos(thetaMotor(2)); ...
         -cos(alpha1)               -cos(alpha1)               -cos(alpha1)];
    JA = [cross(w(:,1),v(:,1)) ...
          cross(w(:,2),v(:,2)) ...
          cross(w(:,3),v(:,3))];

    JB = [dot(cross(u(:,1),w(:,1)), v(:,1)) 0 0;
          0 dot(cross(u(:,2),w(:,2)), v(:,2)) 0;
          0 0 dot(cross(u(:,3),w(:,3)), v(:,3))];

    J = (JA.')\JB;
%     J = [(cross(w(:,1),v(:,1)))/(dot(cross(u(:,1),w(:,1)), v(:,1))) ...
%          (cross(w(:,2),v(:,2)))/(dot(cross(u(:,2),w(:,2)), v(:,2))) ...
%          (cross(w(:,3),v(:,3)))/(dot(cross(u(:,3),w(:,3)), v(:,3)))];
    %% 

    %% torque transmission
    G = abs(inv(J));
    M = tau*G;
end

