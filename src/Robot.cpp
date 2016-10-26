#include "Robot.h"


// Initialize a single static instance of all of your subsystems to NULL
OperatorInterface *operatorInterface = 0;
IntakeRoller *intakeRoller = 0;
HangerWinch *hangerWinch = 0;
HangerArm *hangerArm = 0;
Drivetrain *drivetrain = 0;
Pneumatic *pneumatic = 0;
Flashlight *flashlight = 0;
ActionArm *actionArm = 0;
Clamp *clamp = 0;
Catapult *catapult = 0;

class Robot: public IterativeRobot
{
private:

	void RobotInit()
	{
		std::cout << "starting RobotInit" << std::endl;
		intakeRoller = IntakeRoller::GetInstance();
		flashlight = Flashlight::GetInstance();
		drivetrain = Drivetrain::GetInstance();
		pneumatic = Pneumatic::GetInstance();
		operatorInterface = OperatorInterface::GetInstance();
		actionArm = ActionArm::GetInstance();
		clamp = Clamp::GetInstance();
		catapult = Catapult::GetInstance();
		//chooser = new SendableChooser();
		//chooser->AddDefault("Default Auto", new ExampleCommand());
		//chooser->AddObject("My Auto", new MyAutoCommand());
		//SmartDashboard::PutData("Auto Modes", chooser);
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
		//Update SmartDashboard
		UpdateSmartDash();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit()
	{
		int position = operatorInterface->GetSelectorA();
		int defense = operatorInterface->GetSelectorB();
		int actions = operatorInterface->GetDSSwitches();
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */


	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
		//Update SmartDashboard
		UpdateSmartDash();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.

	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		//Update SmartDashboard
		UpdateSmartDash();
	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
	
	void UpdateSmartDash()
	{
		//Subsystems
		SmartDashboard::PutData(Drivetrain::GetInstance());
		SmartDashboard::PutData(ActionArm::GetInstance());
		SmartDashboard::PutData(IntakeRoller::GetInstance());


		SmartDashboard::PutBoolean("Lowgear:",Drivetrain::GetInstance()->GetGear());
		SmartDashboard::PutBoolean("Beam Status:",IntakeRoller::GetInstance()->IsBeamBroke());
		SmartDashboard::PutData("ShortLong",new ShootCatapult(true));
		SmartDashboard::PutData("ShortShot", new ShootCatapult(false));
		SmartDashboard::PutNumber("Gyro Angle:",((double)Drivetrain::GetInstance()->GetGyroAngle()));

	}
	
};

START_ROBOT_CLASS(Robot)

