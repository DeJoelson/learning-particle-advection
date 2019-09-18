/* The Arnold-Beltrami-Childress flow, a steady state flow,
 * is defined as a flow with a 3-value parameterization.
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
 
#ifndef ABC_STEADY_VECTOR_FIELD_CPP
#define ABC_STEADY_VECTOR_FIELD_CPP

#include <archtypes/ParameterizedSteadyVectorField.h>

class ABCVectorField : public ParameterizedVectorField
{
	private:
		double a;
		double b;
		double c;
	public:
		ABCVectorField(double a, double b, double c)
		{
			this->a = a;
			this->b = b;
			this->c = c;
		}
		double getDeltaXComponentValue(double x, double y, double z);
		double getDeltaYComponentValue(double x, double y, double z);
		double getDeltaZComponentValue(double x, double y, double z);
};

double ABCSteadyVectorField::getDeltaXComponentValue(double x, double y, double z)
{
	return (this->a * sin(z)) + (this->c * cos(y));
}

double ABCSteadyVectorField::getDeltaYComponentValue(double x, double y, double z)
{
	return (this->b * sin(x)) + (this->a * cos(z));
}

double ABCSteadyVectorField::getDeltaZComponentValue(double x, double y, double z)
{
	return (this->c * sin(y)) + (this->b * cos(x));
}

#endif
