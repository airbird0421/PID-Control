#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double kp, double ki, double kd) {
  Kp = kp;
  Ki = ki;
  Kd = kd;
  i_error = 0;
  d_error = 999999.0;
}

void PID::UpdateError(double cte) {
  p_error = cte;
  i_error += cte;
  // First time, just set d_error to 0
  if (d_error == 999999.0) {
    d_error = 0;
  } else {
    d_error = cte - pre_cte;
  }
  pre_cte = cte;
}

double PID::TotalError() {
  double te = -Kp * p_error - Ki * i_error - Kd * d_error;
  // per the comments in main.c, steering angle should be in range of [-1, 1]
  if (te > 1) te = 1;
  if (te < -1) te = -1;
  return te;
}

