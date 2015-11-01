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

class RobotDrive{
public:
    
    RobotDrive(int fLMotorChannel, int rLMotorChannel, int fRMotorChannel, int rRMotorChannel){
        frontLeftMotorChannel = fLMotorChannel;
        rearLeftMotorChannel = rLMotorChannel;
        frontRightMotorChannel = fRMotorChannel;
        rearRightMotorChannel = rRMotorChannel;
        
        
        /*
         Prefix:
         s - robot state
         a - arena state
         */
        
        s_speed = 0;
        s_Direction = 0;
        a_pos[0] = 0; //x
        a_pos[1] = 0; //y

    }
    
    void Drive(float outputMagnitude, float curve){
        //assume curve is rad/cycle
        s_speed = outputMagnitude;
        s_Direction = fmod((s_Direction + curve), 2);
        a_pos[0] += sin(curve) * outputMagnitude;
        a_pos[0] += cos(curve) * outputMagnitude;
    }
    
    void ArcadeDrive(Joystick *stick, bool squaredInputs = true){
        
        float squared;
        if (squaredInputs){
            squared = 2;
        }else{
            squared = 1;
        }
        
        
        stick->c_PushJoystick();
        
        float x = stick->GetX();
        float y = stick->GetX();
        
        float mag = pow(sqrt(pow(x, 2) + pow(y, 2)), squared);
        float curve = atan(x/y);
        
        Drive(mag, curve);
    }
    
    
private:
    int frontLeftMotorChannel;
    int rearLeftMotorChannel;
    int frontRightMotorChannel;
    int rearRightMotorChannel;
    
    //correspond to outputMagnitude and curve
    float s_speed;
    float s_Direction;
    
    float a_pos[2];
    
    void GetState(void){
        std::cout << " *** Speed of The Robot *** " << std::endl;
        std::cout << "Speed: " << s_speed << " Facing:     " << s_Direction << "       " << std::endl;
        
    }
    
};


#endif
