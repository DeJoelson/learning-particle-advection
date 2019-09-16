#include "ParameterizedSteadyVectorField.h"

double ParameterizedSteadyVectorField::getDeltaMValue(double x, double y, double z)
{
	double dX = getDeltaXComponentValue(x, y, z);
	double dY = getDeltaYComponentValue(x, y, z);
	double dZ = getDeltaZComponentValue(x, y, z);

	return sqrt((dX * dX) + (dY * dY) + (dZ * dZ));
}
