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
    
public:
    
    Joystick(int cha);
    
    float GetX(void);
    float GetY(void);
    
    /*** control ***/
    void c_PushJoystick(void);
    
    
private:
    
    float x, y;
    int channel;
};

#endif


