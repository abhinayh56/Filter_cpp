#ifndef FILTER_MA_1
#define FILTER_MA_1

#include "Constants.h"

class MA{
	public:
		MA();
        
		void init(double fc_, double dt_);
		void set_param(double fc_, double dt_);
		void set_x_arr(double* x_arr_, uint16_t len_arr_);
		double update(double x_k);
		void reset();

		void set_fc(double fc_);
		void set_dt(double dt_);
		void set_n(double n_);

		double get_fc();
		double get_dt();
		double get_n();

	private:
		double fc = 0.0;
        double n = 0.0;
		double dt = 0.0;

		double* x_arr;
        bool start = true;
};

#endif