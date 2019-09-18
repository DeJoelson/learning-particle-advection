#include <ParameterizedUnsteadyVectorField.h>

double ParameterizedUnsteadyVectorField::getDeltaMValue(double t, double x, double y, double z)
{
	double dX = getDeltaXComponentValue(t, x, y, z);
	double dY = getDeltaYComponentValue(t, x, y, z);
	double dZ = getDeltaZComponentValue(t, x, y, z);

	return sqrt((dX * dX) + (dY * dY) + (dZ * dZ));
}