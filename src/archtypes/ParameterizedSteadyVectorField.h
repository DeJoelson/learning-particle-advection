#ifndef PARAMETERIZED_STEADY_VECTOR_FIELD_H
#define PARAMETERIZED_STEADY_VECTOR_FIELD_H

#include <math.h>
class ParameterizedSteadyVectorField
{
public:
    virtual double getDeltaXComponentValue(double x, double y, double z) = 0;
    virtual double getDeltaYComponentValue(double x, double y, double z) = 0;
    virtual double getDeltaZComponentValue(double x, double y, double z) = 0;
    double getDeltaMValue(double x, double y, double z)	
};

double ParameterizedSteadyVectorField::getDeltaMValue(double x, double y, double z)
{
    double dX = getDeltaXComponentValue(x, y, z);
    double dY = getDeltaYComponentValue(x, y, z);
    double dZ = getDeltaZComponentValue(x, y, z);

    return sqrt((dX * dX) + (dY * dY) + (dZ * dZ));
}
#endif