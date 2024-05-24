#ifndef FILTER_HPF_1
#define FILTER_HPF_1

#include "Constants.h"

class HPF_1{
	public:
		HPF_1();
		void init(double fc_, double dt_);
		void set_param(float fc_, float dt_);
		float update(float x_i);
		void reset();

		void set_fc(float fc_);
		void set_tau(float tau_);
		void set_dt(float dt_);
		void set_alpha(float alpha_);
		
		float get_fc();
		float get_tau();
		float get_dt();
		float get_alpha();
		float get_y();

	private:
		float fc = 0.0;
		float tau = 0.0;
		float dt = 0.0;
		float alpha = 0.0;

		float x_i_1 = 0.0;
		float y_i_1 = 0.0;
		float y_i = 0.0;
		bool start = true;
};

#endif