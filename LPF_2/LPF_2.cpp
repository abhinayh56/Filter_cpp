EcSsiLowPassFilter_2::EcSsiLowPassFilter_2(double dt_)
{
   dt = dt_;
   fc = 0.5 / dt;
   enable_flag = false;
   start_counter = 0;
}

void EcSsiLowPassFilter_2::init(double fc_, double dt_)
{
   set_param(fc_, dt_);
}

void EcSsiLowPassFilter_2::set_param(double fc_, double dt_)
{
   fc = fc_;
   dt = dt_;
   double wc = Ec2Pi*fc;
   double b0 = dt*dt*wc*wc;
   double b1 = 2.0*b0;
   double b2 = b0;
   double a0 = b0 + 2 * sqrt(2)*dt*wc + 4.0;
   double a1 = b1 - 8.0;
   double a2 = b0 - 2 * sqrt(2)*dt*wc + 4.0;

   lambda_1 = b0 / a0;
   lambda_2 = b1 / a0;
   lambda_3 = b2 / a0;
   lambda_4 = -a1 / a0;
   lambda_5 = -a2 / a0;
}

void EcSsiLowPassFilter_2::set_fc(double fc_)
{
   set_param(fc_, dt);
}

void EcSsiLowPassFilter_2::set_dt(double dt_)
{
   set_param(fc, dt_);
}

void EcSsiLowPassFilter_2::enable_filt()
{
   enable_flag = true;
   start_counter = 0;
}

void EcSsiLowPassFilter_2::disable_filt()
{
   enable_flag = false;
   start_counter = 0;
}

double EcSsiLowPassFilter_2::get_fc()
{
   return fc;
}

double EcSsiLowPassFilter_2::get_dt()
{
   return dt;
}

double EcSsiLowPassFilter_2::get_fs(){
   return 1.0 / dt;
}

double EcSsiLowPassFilter_2::update(double x_k)
{
   double y_k = 0.0;

   if (enable_flag == false)
   {
      y_k = x_k;
   }
   else{
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
}

void EcSsiLowPassFilter_2::reset()
{
   start_counter = 0;
}