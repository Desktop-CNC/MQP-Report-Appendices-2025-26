% Torque conversion %

% Variables to change
axialForce = 6700; % in lbs
k = 0.2; % friction coeeficient (steel)
nominalBoltDiameter = .250; % in inches
lubricationFactor = 0;

% Conversions
axialForce_newtons = axialForce * 4.448;
nominalBoltDiameter_mm = nominalBoltDiameter * 25.4; % bolt diameter in mm


% Maximum torque allowed on bolt in lb-inch
disp("torque in lb-inch:")
torque_lbInch = k * axialForce * nominalBoltDiameter *...
(1-lubricationFactor/100) 


% Maximum torque allowed on bolt in nM
fprintf("\n")
disp("torque in newton-m:")
torque_newtonM = (k * axialForce_newtons * nominalBoltDiameter_mm * ...
    (1-lubricationFactor/100)) / 1000 
