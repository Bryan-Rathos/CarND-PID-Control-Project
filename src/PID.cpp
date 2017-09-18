
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd)
{
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  
  p_error = 0.0;
  d_error = 0.0;
  i_error = 0.0;
  
  time_step = 1;
}

void PID::UpdateError(double cte)
{
  if (time_step == 1)
  {
    p_error = cte;
    time_step++;
  }
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
  
}

double PID::TotalError()
{
  return -p_error * Kp - d_error * Kd - i_error * Ki;
}

