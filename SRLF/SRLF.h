#ifndef FILTER_SRLF
#define FILTER_SRLF

#include "Math_functions.h"

class SRLF{
    public:
        SRLF();
        void set_param(float dt_, float dx_dt_max_);
        void set_dt(float dt_);
        void set_dx_dt_max(float dx_dt_max_);
        float get_dt();
        float get_dx_dt_max();
        float get_y();
        float update(float x_i);
        void reset();

    private:
        Math_functions math_fun;
        float dt        = 0;
        float dx_dt_max = 0;
        float y_i       = 0.0;
        float y_i_1     = 0;
        bool start      = true;
};

#endif