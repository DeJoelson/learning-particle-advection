#include "ABCVectorField.h"

/* The Arnold-Beltrami-Childress flow, a steady state flow,
 * is defined as a flow with a 3-value parmeterization.
 * 
 * Let the parameters be known as A, B, and C. The flow is defined as:
 * [dx/dt, dy/dt, dz/dt] = [delta x, delta y, delta z]
 *
 * where
 *
 * delta x = A sin(z) + C cos(y)
 * delta y = B sin(x) + A cos(z)
 * delta z = C sin(y) + B cos(x)
 *
 * for all x, y, z, t.
 */

double ABCVectorField::getDeltaXComponentValue(double x, double y, double z)
{
	return (this->a * sin(z)) + (this->c * cos(y));
}

double ABCVectorField::getDeltaYComponentValue(double x, double y, double z)
{
	return (this->b * sin(x)) + (this->a * cos(z));
}

double ABCVectorField::getDeltaZComponentValue(double x, double y, double z)
{
	return (this->c * sin(y)) + (this->b * cos(x));
}
