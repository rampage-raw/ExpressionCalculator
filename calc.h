#ifndef CALC_H
#define CALC_H
#include <stack>
#include <vector>
#include <string>
#include <QDebug>
using namespace std;
class calc
{
public:
    calc();
    double RunCalc(string);
    double transform(string);
    double cal(double, double, char);
    double func();
    bool checkmatch(string);
    bool checkvalid(string);
private:
    string ss;
    int len;
    stack<double> num;
    stack<char> symbol;
    vector<string> rec;
    bool decimal_point = false;
};

#endif // CALC_H
