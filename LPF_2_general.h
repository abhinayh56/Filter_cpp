class EcSsiLowPassFilter_2
{
	public:
		EcSsiLowPassFilter_2(double dt_)
		{
			dt = dt_;
			fc = 0.5/dt;
			enable_flag = false;
			start_counter = 0;
		}

		void init(double fc_, double dt_)
		{
			set_param(fc_, dt_);
		}

		void set_param(double fc_, double dt_)
		{
			fc = fc_;
			dt = dt_;
			double wc = 2.0*PI*fc;
			double b0 = dt*dt*wc*wc;
			double b1 = 2.0*b0;
			double b2 = b0;
			double a0 = b0 + 2*sqrt(2)*dt*wc + 4.0;
			double a1 = b1 - 8.0;
			double a2 = b0 - 2*sqrt(2)*dt*wc + 4.0;

			lambda_1 =  b0 / a0;
			lambda_2 =  b1 / a0;
			lambda_3 =  b2 / a0;
			lambda_4 = -a1 / a0;
			lambda_5 = -a2 / a0;
		}

		void set_fc(double fc_){
			set_param(fc_, dt);
		}

		void set_dt(double dt_){
			set_param(fc, dt_);
		}

		double get_fs(){
			return 1.0/dt;
		}

		void enable_filt(){
			enable_flag = true;
			start_counter = 0;
		}

		void disable_filt(){
			enable_flag = false;
			start_counter = 0;
		}

		double get_fc(){
			return fc;
		}

		double get_dt(){
			return dt;
		}

		double update(double x_k){
			double y_k = 0.0;

			if(enable_flag==false){
				y_k = x_k;
			}
			else{
				if(start_counter<=1){
					y_k = x_k;
					start_counter++;
				}
				else{
					y_k = lambda_1 * x_k + lambda_2 * x_k_1 + lambda_3 * x_k_2 + lambda_4 * y_k_1 + lambda_5 * y_k_2;
				}
				y_k_2 = y_k_1;
				y_k_1 = y_k;
				x_k_2 = x_k_1;
				x_k_1 = x_k;
				
				return y_k;
			}
		}

		void reset(){
			start_counter = 0;
		}

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