#ifndef PARAMETERIZED_UNSTEADY_VECTOR_FIELD_H
#define PARAMETERIZED_UNSTEADY_VECTOR_FIELD_H

#include <math.h>
class ParameterizedUnsteadyVectorField
{
	public:
		virtual double getDeltaXComponentValue(double t, double x, double y, double z) = 0;
		virtual double getDeltaYComponentValue(double t, double x, double y, double z) = 0;
		virtual double getDeltaZComponentValue(double t, double x, double y, double z) = 0;
		double getDeltaMValue(double t, double x, double y, double z);	
};
#endif
