/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Spark.h>
#include <frc/XboxController.h>
//#include <frc/Drive/DifferentialDrive.h>

#include "RobotMap.h"

#include <frc/Commands/Subsystem.h>
using namespace frc;
class DriveTrain : public Subsystem
{
  private:
    Spark m_leftDriveMotor{LEFT_DRIVE_MOTOR_PORT};
    Spark m_rightDriveMotor{RIGHT_DRIVE_MOTOR_PORT};

    //DifferentialDrive drive {m_leftDriveMotor, m_rightDriveMotor};
 public:
  DriveTrain();
  void StopMotors();
  void ResetMotors();
  void TeleopDrive (XboxController* controller);
  void Drive (double left, double right);
  void InvertMotors();
  double Limit(double upperLimit, double lowerLimit, double value);
};

