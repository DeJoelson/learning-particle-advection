// Modified Arnold-Beltrami-Childress (ABC) flow for time series
// From the definition found on page 240 in the paper:
// Linear and nonlinear dynamo properties of time-dependent ABC flows
// By N. H. Brummel, F. Cattaneo, and S. M. Tobias
// https://iopscience.iop.org/article/10.1016/S0169-5983(00)00027-7/pdf

#ifndef ABC_UNSTEADY_VECTOR_FIELD_H
#define ABC_UNSTEADY_VECTOR_FIELD_H

#include <archtypes/ParameterizedUnsteadyVectorField.h>

class ABCUnsteadyVectorField : public ParameterizedUnsteadyVectorField
{
private:
    double epsilon;
    double omega;
public:
    ABCUnsteadyVectorField()
    {
        this->epsilon = 1.0;
        this->omega = 1.0;
    }
    ABCUnsteadyVectorField(double epsilon, double omega)
    {
        this->epsilon = epsilon;
        this->omega = omega;
    }
    double getDeltaXComponentValue(double t, double x, double y, double z);
    double getDeltaYComponentValue(double t, double x, double y, double z);
    double getDeltaZComponentValue(double t, double x, double y, double z);
};

#endif