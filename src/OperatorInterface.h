/*
 * OperatorInterface.h
 *
 *  Created on: Aug 4, 2016
 *      Author: griggsjr
 */

#ifndef SRC_OPERATORINTERFACE_H_
#define SRC_OPERATORINTERFACE_H_

#include "WPILib.h"
#include "Commands/IntakeIn.h"

class OperatorInterface {
public:
	OperatorInterface();

private:
	Joystick* m_driverJoystick;
	Joystick* m_operatorJoystick;

	JoystickButton* m_drvButton1;
	JoystickButton* m_drvButton2;
	JoystickButton* m_drvButton3;
	JoystickButton* m_drvButton4;
	JoystickButton* m_drvButton5;
	JoystickButton* m_drvButton6;

	JoystickButton* m_opButton1;
	JoystickButton* m_opButton2;
	JoystickButton* m_opButton3;
	JoystickButton* m_opButton4;
	JoystickButton* m_opButton5;
	JoystickButton* m_opButton6;


	float m_driverXStick = 0.0;
	float m_driverYStick = 0.0;
	float m_operatorXStick = 0.0;
	float m_operatorYStick = 0.0;



};

#endif /* SRC_OPERATORINTERFACE_H_ */
