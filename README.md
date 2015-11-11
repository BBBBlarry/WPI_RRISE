# WPI_RRISE
A mimic library of the FRC WPI Library for educational purposes. Intro to WPI programming in C++.

## Quick Tutorial
### Creating Robot.cpp implementing IterativeRobot

You create your robot cpp file just like any regular WPI C++ code. Include the "./src/WPI_RRISE.h". In the current version, the library supports some basic classes and methods that the orginal WPI provides. It is also worth mentioning that you don't need "START_ROBOT_CLASS()" at the end of the robot cpp file. 
  
### Mimic Control

Create another cpp file and include the "./src/WPI_RRISE.h", "./src/Robot_Mimic_Control.h" and the robot cpp file. Create a new Robot_Mimic_Control while passing a new robot instance inside a main function. Now you can use Robot_Mimic_Control's

1. StartGame(void) to start the game
2. StartAuto(int cycle) to start autonomous
3. StartTeleop(int cycle) to start teleop

StartGame should always be called before StartAuto and StartTeleop. The control periodicly updates the robot status (speed, direction and the location in the arena). The parameter "int cycle" sets the length of the game stage (auto/teleop) in terms of how many time the the robot status is updated ("-1" means infinite amount of cycles). Now you see why "START_ROBOT_CLASS()" is not needed in the robot cpp file. 
