/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include "RobotMap.h"

using namespace frc;
DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{

}

void DriveTrain::ResetMotors()
{
    m_leftDriveMotor.Set(0);
    m_rightDriveMotor.Set(0);
}
void DriveTrain::InvertMotors()
{
    m_leftDriveMotor.SetInverted(true);
    m_rightDriveMotor.SetInverted(false);
}

void DriveTrain::StopMotors()
{
    m_leftDriveMotor.Set(0);
    m_rightDriveMotor.Set(0);
}
void DriveTrain::Drive(double left, double right)
{
    m_leftDriveMotor.Set(left + right);
    m_rightDriveMotor.Set(left-right);
    //drive.ArcadeDrive(left, right);
}

void DriveTrain::TeleopDrive(XboxController* controller)
{
    double leftY = controller->GetY(GenericHID::kLeftHand);
    double leftX = controller->GetX(GenericHID::kLeftHand);
    double leftYlimit = Limit(1, -1, leftY);
    double leftXlimit = Limit(1, -1, leftX);
    
    m_leftDriveMotor.Set(leftYlimit + leftXlimit);
    m_rightDriveMotor.Set(leftYlimit - leftXlimit);
}

double DriveTrain::Limit(double upperLimit, double lowerLimit, double value)
{
    if(value >= upperLimit)
    {
        value = upperLimit;
        return value;
    }
    if(value <= lowerLimit)
    {
        value = lowerLimit;
        return value;
    }

    else
    {
        return value;
    }

}
