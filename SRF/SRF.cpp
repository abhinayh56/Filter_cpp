#include "SRF.h"

SRF::SRF(){
    double dt = 0;
    double dx_dt_max = 0;
    double y_k_1 = 0;
    bool start = false;
}

void SRF::init(double dt_, double dx_dt_max_){
    set_param(dt_, dx_dt_max_);
}

void SRF::set_param(double dt_, double dx_dt_max_){
    dt = dt_;
    dx_dt_max = dx_dt_max_;
}

double SRF::update(double x_k){
    if(start==true){
        start = false;
        y_k = x_k;
    }
    else{
        if(math_fun.mod(x_k - y_k_1) > dx_dt_max*dt){
            y_k = y_k_1 + math_fun.sign((x_k - y_k_1))*dx_dt_max*dt;
        }
        else{
            y_k = x_k;
        }
    }
    
    y_k_1 = y_k;
    
    return y_k;
}

void SRF::reset(){
    double y_k = 0.0;
    double y_k_1 = 0;
    bool start = true;
}

void SRF::set_dt(double dt_){
    dt = dt_;
}

void SRF::set_dx_dt_max(double dx_dt_max_){
    dx_dt_max = dx_dt_max_;
}

double SRF::get_dt(){
    return dt;
}

double SRF::get_dx_dt_max(){
    return dx_dt_max;
}

double SRF::get_y(){
    return y_k;
}
