#ifndef PARAMETERIZED_VECTOR_FIELD_H
#define PARAMETERIZED_VECTOR_FIELD_H

#include <math.h>
class ParameterizedVectorField
{
	public:
		virtual double getDeltaXComponentValue(double x, double y, double z) = 0;
		virtual double getDeltaYComponentValue(double x, double y, double z) = 0;
		virtual double getDeltaZComponentValue(double x, double y, double z) = 0;
		double getDeltaMValue(double x, double y, double z);	
};
#endif