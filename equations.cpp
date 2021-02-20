#include "equations.h"

equations::equations()
{

}

void equations::RunCalc(float a, float b, float c, float d, float e){
    r = roots_quartic_equation(a, b, c, d, e);
}

float* equations::roots_quartic_equation(float a, float b, float c, float d, float e) {
    float *roots = new float[5];
    if (a == 0) {
        roots = roots_cubic_equation(b, c, d, e);
    }
    else {
        float b1 = b/a;
        float c1 = c/a;
        float d1 = d/a;
        float e1 = e/a;
        if ((b1 == 0) && (c1 == 0) && (d1 == 0)) {
            if (e1 > 0) {
                roots[0] = 0.0;
            }
            else {
                roots[1] = sqrt(sqrt(-e1));
                roots[2] = -sqrt(sqrt(-e1));
                roots[0] = 2.0;
            }
        }
        else {
            float *roots_y = new float[4];
            roots_y = roots_cubic_equation(-1.0, c1, 4*e1-b1*d1, d1*d1+e1*b1*b1-4*e1*c1);
            float y = roots_y[1];
            float B1, B2, C1, C2;
            if (b1*b1-4*c1+4*y == 0) {
                B1 = b/2;
                B2 = b/2;
                C1 = y/2;
                C2 = y/2;
            }
            else {
                B1 = b/2 - sqrt(b1*b1-4*c1+4*y)/2;
                B2 = b/2 + sqrt(b1*b1-4*c1+4*y)/2;
                C1 = y/2 - (b1*y -2*d1)/(2*sqrt(b1*b1-4*c1+4*y));
                C2 = y/2 + (b1*y -2*d1)/(2*sqrt(b1*b1-4*c1+4*y));
            }
            float *roots_x1 = new float[3];
            float *roots_x2 = new float[3];
            roots_x1 = roots_quadratic_equation(1.0, B1, C1);
            roots_x2 = roots_quadratic_equation(1.0, B2, C2);
            if (roots_x1[0] != 0) {
                for (int i=1; i<roots_x1[0]+1; i++) {
                    roots[i] = roots_x1[i];
                }
            }
            if (roots_x2[0] != 0) {
                int roots_x1_number = int(roots_x1[0]);
                for (int j=1; j<roots_x2[0]+1; j++) {
                    roots[roots_x1_number+j] =roots_x2[j];
                }
            }
            roots[0] = roots_x1[0] + roots_x2[0];
        }
    }
    return roots;
}

float* equations::roots_cubic_equation(float a, float b, float c, float d) {
    float *roots = new float[4];
    if (a == 0) {
        roots = roots_quadratic_equation(b, c, d);
    }
    else {
        float A = b*b - 3*a*c;
        float B = b*c - 9*a*d;
        float C = c*c - 3*b*d;
        float deita = B*B - 4*A*C;

        if ((A == B) && (A == 0)) {
            //the three roots are the same
            if (a != 0) {
                roots[1] = -b/(3*a);
            }
            else {
                if (b != 0) {
                    roots[1] = -c/b;
                }
                else {
                    if (c != 0) {
                        roots[1] = -3*d/c;
                    }
                }
            }
            roots[2] = roots[1];
            roots[3] = roots[1];
            roots[0] = 3;
        }
        else if (deita > 0) {
            //only one real root
            float y1 = A*b + (3*a/2)*(-B + sqrt(deita));
            float y2 = A*b + (3*a/2)*(-B - sqrt(deita));
            float pow_y1, pow_y2;
            if (y1 < 0) {
                //for pow(a,b), when b is not int, a should not be negative.
                pow_y1 = - pow(-y1, 1.0/3.0);
            }
            else {
                pow_y1 = pow(y1, 1.0/3.0);
            }
            if (y2 < 0) {
                pow_y2 = - pow(-y2, 1.0/3.0);
            }
            else {
                pow_y2 = pow(y2, 1.0/3.0);
            }
            roots[1] = (-b - pow_y1 - pow_y2) / (3*a);
            roots[0] = 1;
        }
        else if (deita == 0) {
            //three real roots and two of them are the same
            float K = B/A;
            roots[1] = -b/a + K;
            roots[2] = -K/2;
            roots[3] = -K/2;
            roots[0] = 3;
        }
        else if (deita < 0) {
            //three different real roots
            float theta = acos((2*A*b-3*a*B) / (2*pow(A, 1.5)));
            roots[1] = (-b - 2*sqrt(A)*cos(theta/3)) / (3*a);
            roots[2] = (-b + sqrt(A) * (cos(theta/3) + sqrt(3)*sin(theta/3))) / (3*a);
            roots[3] = (-b + sqrt(A) * (cos(theta/3) - sqrt(3)*sin(theta/3))) / (3*a);
            roots[0] = 3;
        }
    }
    return roots;
}

float* equations::roots_quadratic_equation(float a, float b, float c) {
    float *roots = new float[3];
    if (a == 0.0) {
        if (b == 0.0) {
            roots[0] = 0.0;
        }
        else {
            roots[1] = -c/b;
            roots[0] = 1.0;
        }
    }
    else {
        float d = b*b - 4*a*c;
        if (d < 0.0) {
            roots[0] = 0.0;
        }
        else {
            roots[1] = (-b + sqrt(d)) / (2*a);
            roots[2] = (-b - sqrt(d)) / (2*a);
            roots[0] = 2.0;
        }
    }
    return roots;
}
