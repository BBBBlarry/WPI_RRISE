//
//  Robot_Mimic_Control.h
//  WPI_RRISE
//
//  Created by Blarry_Air on 2015-11-01.
//  Copyright (c) 2015 RRISE. All rights reserved.
//

#ifndef WPI_RRISE_Robot_Mimic_Control_h
#define WPI_RRISE_Robot_Mimic_Control_h

#include "WPI_RRISE.h"

class Robot_Mimic_Control{
public:
    
    Robot_Mimic_Control(IterativeRobot* i_bot);
    IterativeRobot* robot;
    
    /*
     * You should always startGame() before start any other state
     */
    void StartGame(void);
    
    
    /*
     * startAuto() will run until the cycles are ran
     * if cycle is -1, the robot will always be at auto state
     */
    void StartAuto(int);
    
    
    /*
     * startTeleop() will run until the cycles are ran
     * if cycle is -1, the robot will always be at auto state
     */
    
    void StartTeleop(int);
};

#endif
