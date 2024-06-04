#ifndef FILTER_SRL
#define FILTER_SRL

class SRL{
    public:
        SRL();
        void init(double dt_, double dx_dt_min_, double dx_dt_max_);
        void set_param(double dt_, double dx_dt_min_, double dx_dt_max_);
        double update(double x_k);
        void reset();

        void set_dt(double dt_);
        void set_dx_dt_min(double dx_dt_min_);
        void set_dx_dt_max(double dx_dt_max_);
        double get_dt();
        double get_dx_dt_min();
        double get_dx_dt_max();

    private:
        double dt        = 0;
        double dx_dt_min = 0;
        double dx_dt_max = 0;

        double y_k_1     = 0;

        bool start      = true;
};

#endif