#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    i_error = 0.0;
    d_error = 0.0;
    p_error = 0.0;
}

void PID::UpdateError(double cte) {
    //p_error contains previous cte 
    d_error = cte - p_error;
    i_error = i_error + cte;
    p_error = cte;
}

double PID::TotalError() {
    return -( Kp * p_error + Ki * i_error + Kd * d_error);
}

