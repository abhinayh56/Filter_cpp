#ifndef FILTER_LPF_1
#define FILTER_LPF_1

#include "Constants.h"

class LPF_1{
	public:
		LPF_1();
		void init(double fc_, double dt_);
		void set_param(double fc_, double dt_);
		double update(double x_k);
		void reset();

		void set_fc(double fc_);
		void set_tau(double tau_);
		void set_dt(double dt_);
		void set_alpha(double alpha_);

		double get_fc();
		double get_tau();
		double get_dt();
		double get_alpha();

		double get_y();

	private:
		double fc = 0.0;
		double tau = 0.0;
		double dt = 0.0;
		double alpha = 0.0;

		double y_k_1 = 0.0;
		double y_k = 0.0;
		bool start = true;
};

#endif