#ifndef FILTER_LPF_2_
#define FILTER_LPF_2_

class EcSsiLowPassFilter_2
{
   public:
      EcSsiLowPassFilter_2(double dt_);
      void init(double fc_, double dt_);
      void set_param(double fc_, double dt_);
      void set_fc(double fc_);
      void set_dt(double dt_);
      void enable_filt();
      void disable_filt();
      double get_fc();
      double get_dt();
      double get_fs();
      double update(double x_k);
      void reset();

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
      bool enable_flag = false;
};

#endif