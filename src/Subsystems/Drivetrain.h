#ifndef Drivetrain_H
#define Drivetrain_H

#include "WPILib.h"
#include "Constants/Ports.h"
#include "Commands/DriveWithJoystick.h"

class Drivetrain: public Subsystem {
public:
	static Drivetrain* GetInstance();
	void InitDefaultCommand();
	void Arcade(float ystick, float xstick);
	//void Arcade(Joystick joy);

	void DriveDistance(int dist, int time = 0);		//drive a given distance
	void Turn(int angle, int time = 0);				//Turn a specific angle
	void ResetEncoders(); 							//Reset Both Encoders
	void SetGear(bool gear);						//shift to given low/high gear
	void SwitchGear();								//shift to the other gear

private:
	Drivetrain();
	static Drivetrain *m_instance;

	CANTalon *m_LeftMotor1;
	CANTalon *m_LeftMotor2;
	CANTalon *m_RightMotor1;
	CANTalon *m_RightMotor2;

	RobotDrive *m_drive;

	//Shifter Solenoid
	Solenoid *m_shifter;
	bool m_gear;


	//PDP
	PowerDistributionPanel *pdp;

	//Encoders
	Encoder *m_lEncoder;
	Encoder *m_rEncoder;
	int m_lEncoderDistance;
	int m_rEncoderDistance;


	//Gyro
	Gyro *m_gyro;

};

#endif
