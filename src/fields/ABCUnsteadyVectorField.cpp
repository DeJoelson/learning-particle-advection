#include <ABCUnsteadyVectorField.h>

/* The Arnold-Beltrami-Childress time series flow, an unsteady state flow,
 * is defined as a flow with a 3-value parameterization.
 *
 * Let the parameters be known as time (t), epsilon (e) and Omega (O). The flow is defined as:
 * [dx/dt, dy/dt, dz/dt] = [delta x, delta y, delta z]
 *
 * where
 *
 * delta x = sin(z + (e * sin(t * O))) + cos(y + (e * sin(t * O)))
 * delta y = sin(x + (e * sin(t * O))) + cos(z + (e * sin(t * O)))
 * delta z = sin(y + (e * sin(t * O))) + cos(x + (e * sin(t * O)))
 *
 * for all x, y, z, t.
 */

double ABCUnsteadyVectorField::getDeltaXComponentValue(double t, double x, double y, double z)
{
	return sin(z + (this->epsilon * sin(t * this->omega))) + cos(y + (this->epsilon * sin(t * this->omega)));
}

double ABCUnsteadyVectorField::getDeltaYComponentValue(double t, double x, double y, double z)
{
	return sin(x + (this->epsilon * sin(t * this->omega))) + cos(z + (this->epsilon * sin(t * this->omega)));
}

double ABCUnsteadyVectorField::getDeltaZComponentValue(double t, double x, double y, double z)
{
	return sin(y + (this->epsilon * sin(t * this->omega))) + cos(x + (this->epsilon * sin(t * this->omega)));
}