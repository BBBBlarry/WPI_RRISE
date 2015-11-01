//
//  RRISE_Bot.cpp
//  WPI_RRISE
//
//  Created by Blarry_Air on 2015-11-01.
//  Copyright (c) 2015 RRISE. All rights reserved.
//

#include <stdio.h>
#include "./src/WPI_RRISE.h"

class RRISE_Bot: public IterativeRobot{
private:
    // Driver joystick
    Joystick *driveJoystick;
    RobotDrive *robot;
    
public:
    RRISE_Bot(void){
        driveJoystick = new Joystick(1);
        
        // Create a robot using standard right/left robot drive on PWM 1, 2, 3, and 4
        robot = new RobotDrive(1, 3, 2, 4);
    }
    
    
    /********** init ********/
    void RobotInit(void){
        //Robot-wide initialization code should go here.
    }
    
    void AutonomousInit(void){
        //Initialization code for autonomous mode should go here.
    }
    
    void TeleopInit(void){
        //Initialization code for teleop mode should go here.
    }
    
    
    
    /********** periodic ********/
    void AutonomousPeriodic(void){
        //drive forward with motor speed 0.1
        robot->Drive(0.1, 0);
    }
    
    void TeleopPeriodic(void){
        //use driveJoystick to arcade drive in squaredInputs
        robot->ArcadeDrive(driveJoystick, true);
    }
};
