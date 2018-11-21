/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <Spark.h>
#include "../Util.h"
#include "../OI.h"
#include "../RobotMap.h"
#include "../Robot.h"
using namespace Util;
class Drivetrain : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark m_leftMotor{LEFTMOTOR};
	Spark m_rightMotor{RIGHTMOTOR};

	XboxController *m_pJoystick = Robot::m_oi.controller();
	double limitUpper = 0.5;
	double limitLower = -0.5;
public:
	Drivetrain();
	void InitDefaultCommand() override;
	void StopMotors();
	void Movement();




};

