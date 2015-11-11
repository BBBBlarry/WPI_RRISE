//
//  Joystick.cpp
//  WPI_RRISE
//
//  Created by Blarry_Air on 2015-11-10.
//  Copyright (c) 2015 RRISE. All rights reserved.
//

#include "Joystick.h"

/***
    Prefix:
        c - control
        no prefix - WPI
 ***/


Joystick::Joystick(int cha){
    channel = cha;
    x = 0;
    y = 0;
}

float Joystick::GetX(void){
    return Joystick::x;
}

float Joystick::GetY(void){
    return Joystick::y;
}


/*** control ***/
void Joystick::c_PushJoystick(void){
    
    float c_x;
    float c_y;
    
    std::cout << "Joystick (up, right): ";
    std::cin >> c_y >> c_x;
    
    Joystick::x = c_x;
    Joystick::y = c_y;
}

