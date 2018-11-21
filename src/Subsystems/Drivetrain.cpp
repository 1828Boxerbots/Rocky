/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/*This is where we put any external calls*/
#include "Drivetrain.h"
#include "../RobotMap.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain")
{

}

void Drivetrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivetrain::StopMotors()
{
	double value = 0.0;
	m_leftMotor.Set(value);
	m_rightMotor.Set(value);
}

void Drivetrain::Movement()
{
	//Obtaining and assigning left joy stick input.
	double leftX = m_pJoystick->GetX(GenericHID::kLeftHand);
	double leftY = m_pJoystick->GetY(GenericHID::kLeftHand);
	//Accounting for the inverted Y-axis and the inverted motor spins.
	double leftMotorValue = -leftY + leftX;
	double rightMotorValue = leftY + leftX;
	//Assigning limits of -1 to 1 for both motors.
	leftMotorValue = Util::Limit(1.0,-1.0,leftMotorValue);
	rightMotorValue = Util::Limit(1.0,-1.0,rightMotorValue);
	//Combining limits and joy stick inputs to control the motors properly.
	m_leftMotor.Set(leftMotorValue);
	m_rightMotor.Set(rightMotorValue);
}



