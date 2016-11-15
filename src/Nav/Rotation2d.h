/*
 * Rotation2d.h
 *
 *  Created on: Nov 14, 2016
 *      Author: james_tonthat
 */

#ifndef SRC_NAV_ROTATION2D_H_
#define SRC_NAV_ROTATION2D_H_

#include <math.h>

class Rotation2d {
public:
	Rotation2d();
	Rotation2d(double x, double y, bool normalize);
	Rotation2d(Rotation2d other);
	static Rotation2d fromRadians(double angle_radians);
	static Rotation2d fromDegrees(double angle_degrees);
	void normalize();
	double m_cos();
	double m_sin();
	double m_tan();
	double getRadians();
	double getDegrees();
	Rotation2d rotateBy(Rotation2d other);
	Rotation2d inverse();
	Rotation2d interpolate(Rotation2d other, double x);
	std::string toString();

protected:
	double m_cos_angle = 0;
	double m_sin_angle = 0;
	static const double kEpsilon = 1E-9;


};

#endif /* SRC_NAV_ROTATION2D_H_ */