/* Modified Arnold-Beltrami-Childress (ABC) flow for time series
* From the definition found on page 240 in the paper:
* Linear and nonlinear dynamo properties of time-dependent ABC flows
* By N. H. Brummel, F. Cattaneo, and S. M. Tobias
* https://iopscience.iop.org/article/10.1016/S0169-5983(00)00027-7/pdf
*
* The Arnold-Beltrami-Childress time series flow, an unsteady state flow,
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

#ifndef ABC_UNSTEADY_VECTOR_FIELD_CPP
#define ABC_UNSTEADY_VECTOR_FIELD_CPP

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

#endif
