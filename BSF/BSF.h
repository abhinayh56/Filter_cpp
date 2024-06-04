#ifndef FILTER_BSF_2_H
#define FILTER_BSF_2_H

#include "Constants.h"

class BSF_2
{
   public:
      BSF_2();
      void init(double f0_, double dt_);
      void set_param(double f0_, double dt_);
      double update(double x_k);
      void reset();

      void set_f0(double f0_);
      void set_dt(double dt_);
      double get_f0();
      double get_dt();
      double get_fs();

   private:
      double f0 = 0.0;
      double B = 0.0;
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