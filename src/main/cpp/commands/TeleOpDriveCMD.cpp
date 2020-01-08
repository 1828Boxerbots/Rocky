/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TeleOpDriveCMD.h"

#include <Robot.h>
#include <OI.h>
#include "subsystems/DriveTrain.h"

using namespace frc;
using namespace std;
TeleOpDriveCMD::TeleOpDriveCMD()
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_pDriveTrain.get());
}

// Called just before this Command runs the first time
void TeleOpDriveCMD::Initialize() 
{
  Robot::m_pDriveTrain->ResetMotors();
}

// Called repeatedly when this Command is scheduled to run
void TeleOpDriveCMD::Execute() 
{
  Robot::m_pDriveTrain->TeleopDrive(Robot::m_pOi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpDriveCMD::IsFinished() { return false; }

// Called once after isFinished returns true
void TeleOpDriveCMD::End() 
{
  Robot::m_pDriveTrain->StopMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpDriveCMD::Interrupted() 
{
  Robot::m_pDriveTrain->StopMotors();
}
