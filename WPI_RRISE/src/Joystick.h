//
//  Joystick.h
//  WPI_RRISE
//
//  Created by Blarry_Air on 2015-11-01.
//  Copyright (c) 2015 RRISE. All rights reserved.
//


#ifndef WPI_RRISE_Joystick_h
#define WPI_RRISE_Joystick_h

#include <iostream>

class Joystick{
    
    /*
     Prefix:
     c - control
     no prefix - WPI
     */
    
public:
    
    Joystick(int cha){
        channel = cha;
        x = 0;
        y = 0;
    }
    
    float GetX(void){
        return x;
    }
    
    float GetY(void){
        return y;
    }
    
    
    /*** control ***/
    void c_PushJoystick(void){
        
        float c_x;
        float c_y;
        
        std::cout << "Joystick (x,y): ";
        std::cin >> c_x >> c_y;
        
        x = c_x;
        y = c_y;
    }
    
    
    
    
    
private:
    float x, y;
    int channel;
};

#endif


