# Design and Implementation of a 3-DOF Parallel Robot

An extensive mechatronics project for the design, analysis, fabrication, electronics, and control of a three-degree-of-freedom spherical parallel mechanism. This repository includes CAD design iterations, final manufacturing files, PCB/Gerber assets, Arduino firmware, MATLAB inverse kinematics, torque-transmission analysis, ANSYS structural-analysis files, reports, posters, and presentation material.

The project is closer to a complete engineering package than a simple robotics demo: it documents the mechanical design process, actuator selection, embedded control path, mathematical modeling, structural validation, and final deliverables.

## Project Snapshot

- Domain: robotics, mechatronics, parallel mechanisms, embedded control
- Mechanism: 3-DOF spherical parallel mechanism / wrist-style robot
- Mechanical design: Inventor, SolidWorks, STEP, STL, drawings, exploded views
- Electronics: EasyEDA/CadStar PCB files and Gerber package
- Firmware: Arduino sketches for Dynamixel AX-12A and XL-320 servo control
- Modeling: MATLAB inverse kinematics, torque transmission, workspace and mechanism analysis
- Analysis: ANSYS structural analysis project files and solved result artifacts
- Documentation: final report, poster, presentation, images, and reference material

## Engineering Scope

This repository contains work across the full product-development loop:

- Concept research into spherical parallel mechanisms and prosthetic/robotic wrist applications.
- Multiple mechanical design branches and iterations, including coaxial, direct-connection, XL-320, AX-12A, and final designs.
- Final CAD assets in Inventor, SolidWorks, STEP, STL, and DWG formats.
- Structural analysis files for validating critical components under load.
- PCB design files, Gerber exports, and electronics backups.
- Arduino firmware for servo configuration, movement, reset, ID changes, and MATLAB-to-Arduino communication.
- MATLAB applications and scripts for inverse kinematics, serial communication, torque transmission, and mechanism analysis.

## Repository Map

```text
Design/
  Coaxial/                         Early coaxial mechanism designs
  DirectConnection/                Direct actuator connection concepts
  Final/                           Final CAD, drawings, STEP, STL, SolidWorks, Inventor
  Final AX12A/                     AX-12A-based final design variant
Circuit/
  EasyEDA/, CadStar/               PCB projects, backups, and Gerber package
Programming/
  InverseKinematics.m              Motor-angle solution for desired wrist orientation
  TorqueTransmission.m             Jacobian-based torque transmission analysis
  MechanismTorqueAnalysis.m        Torque plots across motion ranges
  Arduino/                         Servo control and MATLAB communication firmware
Structural Analysis/
  Structural Analysis.wbpj         ANSYS Workbench project and result files
Functional Analysis/
  SPM Functional Analysis.*        Functional mechanism analysis artifacts
Report/
  Final Report.pdf, Poster.pdf,
  Presentation.pptx, images        Final documentation and presentation deliverables
Files/
  datasheets and mechanism papers  Actuator, component, and research references
```

## Kinematics and Control

The MATLAB kinematics code computes motor commands from a desired 3-axis orientation. `InverseKinematics.m` builds rotation matrices for X, Y, and Z inputs, solves the spherical parallel mechanism geometry, converts mechanism angles into motor angles, and applies calibration offsets.

The control path also includes:

- MATLAB serial communication scripts
- A MATLAB app for inverse-kinematics testing
- Arduino firmware that receives comma-separated commands over serial
- Dynamixel XL-320 and AX-12A servo control sketches
- Servo ID, reset, and movement utilities

This connects mathematical kinematics to real actuator commands.

## Torque and Structural Analysis

`TorqueTransmission.m` computes Jacobian-based torque transmission through the mechanism, while `MechanismTorqueAnalysis.m` evaluates how transmitted torque changes across angular sweeps from -30 to 30 degrees.

The repository also includes ANSYS Workbench files and solved structural-analysis data, supporting the mechanical design with stress/displacement validation rather than relying only on CAD geometry.

## Mechanical and Manufacturing Assets

The final design folder includes:

- Inventor assemblies and parts
- SolidWorks parts and assemblies
- STEP files for exchange/manufacturing
- STL files for fabrication
- DWG drawings for individual components
- Exploded-view assets and final assembly files

These assets document the project as a real build package, not just a concept image.

## Electronics and Firmware Assets

The `Circuit/` folder contains PCB work in EasyEDA and CadStar formats, including a Gerber package. The `Programming/Arduino/` folder contains firmware for:

- AX-12A servo ID changes, movement, and reset
- XL-320 servo setup and movement
- MATLAB-to-Arduino serial communication for the SPM robot

## What This Project Demonstrates

- End-to-end parallel robot development
- Mechanical design iteration and final manufacturing file preparation
- Spherical parallel mechanism inverse kinematics
- Jacobian-based torque transmission analysis
- Embedded servo control using Arduino and Dynamixel actuators
- PCB design and electronics packaging
- Structural analysis using ANSYS Workbench
- Engineering reporting, presentation, and portfolio documentation

## Project Roadmap

- Final robot photos or CAD renders
- Images from `Report/Images/` showing workspace, mechanism architecture, and final design
- Build notes identifying the final hardware CAD folder
- Run notes for the MATLAB inverse-kinematics script and Arduino communication sketch
- Diagrams for the kinematic chain, actuator layout, and serial communication flow
- Results section with workspace limits, torque-analysis plots, and structural-analysis screenshots
