#ifndef FILTER_LPF_2
#define FILTER_LPF_2

#include "Constants.h"
#include <stdint.h>

class LPF_2{
	public:
		LPF_2();

		void set_param(float fc_, float Q_, float dt_);
		void get_param(float* fc_, float* Q_, float* dt_);

		void set_fc(float fc_);
		void set_Q(float Q_);
		void set_dt(float dt_);

		float get_fc();
		float get_Q();
		float get_dt();

		float get_y();

		float update(float x_i);
		void reset();

	private:
        float dt = 0.0;
		float fc = 0.0;
        float wc = 0.0;
		float Q = 0.0;
        float K0 = 0.0;
        float K1 = 0.0;
        float K2 = 0.0;
        float K3 = 0.0;

		float y_i_2 = 0.0;
		float y_i_1 = 0.0;
		float y_i = 0.0;
		uint8_t start = 0;
};

#endif