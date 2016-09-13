#include "LongShot.h"

LongShot::LongShot()
{
	m_timer = new Timer();
	Requires(Catapult::GetInstance());
	Requires(Clamp::GetInstance());
	Requires(CandyCane::GetInstance());

	m_step1 = CLAMP_OPEN_LONG_DWELL;
	m_step2 = m_step1 + CATAPULT_LONG_DWELL;
}

// Called just before this Command runs the first time
void LongShot::Initialize()
{
	m_startTime = m_timer->GetFPGATimestamp();
}

// Called repeatedly when this Command is scheduled to run
void LongShot::Execute()
{
	double m_currentTime = m_timer->GetFPGATimestamp();

	if((m_currentTime-m_startTime) < m_step1){
		if(Clamp::GetInstance()->GetState()){ //if closed then open
			Clamp::GetInstance()->SetState(1) //open
		}
	}
	else{
		if((m_currentTime-m_startTime) < m_step2){
			if(Catapult::GetInstance()->GetState()){ //if not fired
				Clamp::GetInstance()->SetState(1) //fire
			}
		}
	}


}

// Make this return true when this Command no longer needs to run execute()
bool LongShot::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LongShot::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LongShot::Interrupted()
{

}
