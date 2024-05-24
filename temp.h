class Filter_name{
    public:
        Filter_name();
        void init();
        void set_param();
        double update();
        void reset();

        void set_param_1();
        void set_param_2();
        void get_param_1();
        void get_param_2();

    private:
        double param_1;
        double param_2;
};