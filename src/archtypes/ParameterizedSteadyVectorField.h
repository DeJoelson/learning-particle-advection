#ifndef PARAMETERIZED_STEADY_VECTOR_FIELD_H
#define PARAMETERIZED_STEADY_VECTOR_FIELD_H

#include <math.h>
class ParameterizedSteadyVectorField
{
	public:
		virtual double getDeltaXComponentValue(double x, double y, double z) = 0;
		virtual double getDeltaYComponentValue(double x, double y, double z) = 0;
		virtual double getDeltaZComponentValue(double x, double y, double z) = 0;
		double getDeltaMValue(double x, double y, double z);	
};
#endif