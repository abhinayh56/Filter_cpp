#include "HPF_2.h"

HPF_2::HPF_2(){
   reset();
}

void HPF_2::init(double fc_, double dt_){
   set_param(fc_, dt_);
}

void HPF_2::set_param(double fc_, double dt_){
   fc = fc_;
   dt = dt_;
   double wc = math_2pi*fc;
   double b0 = 4.0;
   double b1 = -8.0;
   double b2 = 4.0;
   double a0 = dt*dt*wc*wc + 2.0*sqrt(2.0)*dt*wc + 4.0;
   double a1 = 2.0*dt*dt*wc*wc - 8.0;
   double a2 = dt*dt*wc*wc - 2.0*sqrt(2.0)*dt*wc + 4.0;

   lambda_1 = b0 / a0;
   lambda_2 = b1 / a0;
   lambda_3 = b2 / a0;
   lambda_4 = -a1 / a0;
   lambda_5 = -a2 / a0;
}

double HPF_2::update(double x_k){
   double y_k = 0.0;

   if (start_counter <= 1)
   {
      y_k = x_k;
      start_counter++;
   }
   else
   {
      y_k = lambda_1 * x_k + lambda_2 * x_k_1 + lambda_3 * x_k_2 + lambda_4 * y_k_1 + lambda_5 * y_k_2;
   }
   y_k_2 = y_k_1;
   y_k_1 = y_k;
   x_k_2 = x_k_1;
   x_k_1 = x_k;

   return y_k;
}

void HPF_2::reset(){
   start_counter = 0;
}

void HPF_2::set_fc(double fc_){
   set_param(fc_, dt);
}

void HPF_2::set_dt(double dt_){
   set_param(fc, dt_);
}

double HPF_2::get_fc(){
   return fc;
}

double HPF_2::get_dt(){
   return dt;
}

double HPF_2::get_fs(){
   return 1.0 / dt;
}