#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  p_error = 0;
  i_error = 0;
  d_error = 0;

  pre_cte = 0;
  cte_initialized = false;
  total_cte = 0;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  if(cte_initialized == false)
  {
    pre_cte = cte;
    cte_initialized = true;
  }

  total_cte += cte;

  p_error = -Kp * cte;
  i_error = -Ki * total_cte;
  d_error = -Kd * (cte - pre_cte);

  pre_cte = cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return p_error + i_error + d_error;  // TODO: Add your total error calc here!
}