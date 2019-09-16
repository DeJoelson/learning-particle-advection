#ifndef PARAMETERIZED_TIME_SERIES_VECTOR_FIELD_H
#define PARAMETERIZED_TIME_SERIES_VECTOR_FIELD_H

#include <math.h>
class ParameterizedTimeSeriesVectorField
{
	public:
		virtual double getDeltaXComponentValue(double t, double x, double y, double z) = 0;
		virtual double getDeltaYComponentValue(double t, double x, double y, double z) = 0;
		virtual double getDeltaZComponentValue(double t, double x, double y, double z) = 0;
		double getDeltaMValue(double t, double x, double y, double z);
};
#endif