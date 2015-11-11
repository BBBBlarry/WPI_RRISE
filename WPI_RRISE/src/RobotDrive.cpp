//
//  RobotDrive.cpp
//  WPI_RRISE
//
//  Created by Blarry_Air on 2015-11-11.
//  Copyright (c) 2015 RRISE. All rights reserved.
//

#include "RobotDrive.h"

RobotDrive::RobotDrive(int fLMotorChannel, int rLMotorChannel, int fRMotorChannel, int rRMotorChannel){
    frontLeftMotorChannel = fLMotorChannel;
    rearLeftMotorChannel = rLMotorChannel;
    frontRightMotorChannel = fRMotorChannel;
    rearRightMotorChannel = rRMotorChannel;
    
    
    /**** Variable prefix: ******
     s - robot state
     a - arena state
     ******************/
    
    
    /**** s_Direction reference ****
     value   facing
     0       y+
     0.5     x+
     1       y-
     1.5     x-
     ****************************/
    
    
    s_speed = 0;
    s_Direction = 0; // unit: (pi*rad)
    a_pos[0] = 0; //x
    a_pos[1] = 0; //y
    
}

void RobotDrive::Drive(float outputMagnitude, float curve){

    //assume curve is (2 * pi * rad)/cycle
    //where curve 1 means a full turn to the clockwise, -1 mean full turn counterclockwise
    
    s_speed = outputMagnitude;
    s_Direction = fmod((s_Direction + (curve * 2)), 2);
    a_pos[0] += sin(s_Direction * M_PI) * outputMagnitude;
    a_pos[1] += cos(s_Direction * M_PI) * outputMagnitude;
    
    GetState();
}

void RobotDrive::ArcadeDrive(Joystick *stick, bool squaredInputs){
    
    float squared;
    if (squaredInputs){
        squared = 2;
    }else{
        squared = 1;
    }
    
    stick->c_PushJoystick();
    
    float x = stick->GetX();
    float y = stick->GetY();
    
    float mag = pow(y, squared);
    float curve = x;
    
    
    Drive(mag, curve);
}

float RobotDrive::ToDeg(float input){
    return fmod((input/(2))*360, 360);
}

void RobotDrive::GetState(void){
    std::cout << " *** The Robot *** " << std::endl;
    std::cout << "Speed: " << s_speed << " Facing: " << ToDeg(s_Direction) << "       " << std::endl;
    std::cout << " Y: " << a_pos[1] <<  "       " << "X: " << a_pos[0] << std::endl;
    std::cout <<  std::endl;
    
}
