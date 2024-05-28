#ifndef FILTER_SRF
#define FILTER_SRF

#include "Math_functions.h"

class SRF{
    public:
        SRLF();
        void init(double dt_, double dx_dt_max_);
        void set_param(double dt_, double dx_dt_max_);
        double update(double x_k);
        void reset();

        void set_dt(double dt_);
        void set_dx_dt_max(double dx_dt_max_);
        double get_dt();
        double get_dx_dt_max();
        double get_y();

    private:
        Math_functions math_fun;

        double dt        = 0;
        double dx_dt_max = 0;

        double y_k       = 0.0;
        double y_k_1     = 0;

        bool start      = true;
};

#endif