#ifndef IntakeOut_H
#define IntakeOut_H

#include "WPILib.h"
#include "Subsystems/IntakeRoller.h"

class IntakeOut : public Command
{
public:
	IntakeOut();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:

};

#endif
