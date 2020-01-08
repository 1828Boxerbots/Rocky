/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TurrentCMD.h"

TurrentCMD::TurrentCMD() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void TurrentCMD::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TurrentCMD::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool TurrentCMD::IsFinished() { return false; }

// Called once after isFinished returns true
void TurrentCMD::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurrentCMD::Interrupted() {}
