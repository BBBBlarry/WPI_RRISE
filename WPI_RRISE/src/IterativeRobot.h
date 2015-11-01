//
//  IterativeRobot.h
//  WPI_RRISE
//
//  Created by Blarry_Air on 2015-11-01.
//  Copyright (c) 2015 RRISE. All rights reserved.
//

#ifndef WPI_RRISE_IterativeRobot_h
#define WPI_RRISE_IterativeRobot_h

class IterativeRobot{
public:
    virtual void RobotInit(void);
    virtual void AutonomousInit(void);
    virtual void TeleopInit(void);
    
    virtual void AutonomousPeriodic(void);
    virtual void TeleopPeriodic(void);
};


#endif
