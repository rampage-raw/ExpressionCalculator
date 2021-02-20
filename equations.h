#ifndef EQUATIONS_H
#define EQUATIONS_H
#include <string>
#include <cmath>
using namespace std;

class equations
{
public:
    equations();
    void RunCalc(float, float, float, float, float);
    float* roots_quartic_equation(float, float, float, float, float);
    float* roots_cubic_equation(float, float, float, float);
    float* roots_quadratic_equation(float, float, float);
    float *r;
};

#endif // EQUATIONS_H
