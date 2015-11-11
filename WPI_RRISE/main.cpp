//
//  main.cpp
//  WPI_RRISE
//
//  Created by Blarry_Air on 2015-11-01.
//  Copyright (c) 2015 RRISE. All rights reserved.
//

#include <iostream>

#include "./src/WPI_RRISE.h"
#include "./src/Robot_Mimic_Control.h"

#include "RRISE_Bot.cpp"

int main(){
    
    Robot_Mimic_Control* control = new Robot_Mimic_Control(new RRISE_Bot());
    
    control->StartGame();
    control->StartAuto(10);
    control->StartTeleop(-1);
    
    return 0;
}
