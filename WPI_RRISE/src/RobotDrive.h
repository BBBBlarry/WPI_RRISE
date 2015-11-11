//
//  RobotDrive.h
//  WPI_RRISE
//
//  Created by Blarry_Air on 2015-11-01.
//  Copyright (c) 2015 RRISE. All rights reserved.
//

#ifndef WPI_RRISE_RobotDrive_h
#define WPI_RRISE_RobotDrive_h

#include <math.h>
#include <iostream>
#include "Joystick.h"

class RobotDrive{
public:
    
    RobotDrive(int fLMotorChannel, int rLMotorChannel, int fRMotorChannel, int rRMotorChannel);
    void Drive(float outputMagnitude, float curve);
    void ArcadeDrive(Joystick *stick, bool squaredInputs = true);
    
private:
    int frontLeftMotorChannel;
    int rearLeftMotorChannel;
    int frontRightMotorChannel;
    int rearRightMotorChannel;
    
    //correspond to outputMagnitude and curve
    float s_speed;
    float s_Direction;
    
    float a_pos[2];
    
    void GetState(void);
    float ToDeg(float input);
    
};


#endif
