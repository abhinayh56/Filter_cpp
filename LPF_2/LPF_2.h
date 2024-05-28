#ifndef FILTER_LPF_2_H
#define FILTER_LPF_2_H

#include "Constants.h"

class LPF_2
{
   public:
      LPF_2();
      void init(double fc_, double dt_);
      void set_param(double fc_, double dt_);
      double update(double x_k);
      void reset();

      void set_fc(double fc_);
      void set_dt(double dt_);
      double get_fc();
      double get_dt();
      double get_fs();

   private:
      double fc = 0.0;
      double dt = 0.0;

      double lambda_1 = 0.0;
      double lambda_2 = 0.0;
      double lambda_3 = 0.0;
      double lambda_4 = 0.0;
      double lambda_5 = 0.0;

      double y_k_1 = 0.0;
      double y_k_2 = 0.0;

      double x_k_1 = 0.0;
      double x_k_2 = 0.0;

      uint8_t start_counter = 0;
};

#endif