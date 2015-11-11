//
//  Robot_Mimic_Control.cpp
//  WPI_RRISE
//
//  Created by Blarry_Air on 2015-11-11.
//  Copyright (c) 2015 RRISE. All rights reserved.
//


#include "Robot_Mimic_Control.h"
#include <iostream>

Robot_Mimic_Control::Robot_Mimic_Control(IterativeRobot* i_bot){
    robot = i_bot;
}

void Robot_Mimic_Control::StartGame(void){
    std::cout << "************ Game Started ************" <<std::endl;
    robot->RobotInit();
}

void Robot_Mimic_Control::StartAuto(int cycle){
    std::cout << "************ Auto Started ************" <<std::endl;
    robot->AutonomousInit();
    if(cycle == -1){
        while(true){
            robot->AutonomousPeriodic();
        }
    }else{
        for(int i = 0; i < cycle; i++){
            robot->AutonomousPeriodic();
        }
    }
    std::cout << "************ Auto Ended ************" <<std::endl;
}

void Robot_Mimic_Control::StartTeleop(int cycle){
    std::cout << "************ Teleop Started ************" <<std::endl;
    robot->TeleopInit();
    if(cycle == -1){
        while(true){
            robot->TeleopPeriodic();
        }
    }else{
        for(int i = 0; i < cycle; i++){
            robot->TeleopPeriodic();
        }
    }
    std::cout << "************ Teleop Ended ************" <<std::endl;
}
