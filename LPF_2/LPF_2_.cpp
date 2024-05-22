#include "LPF_2.h"

LPF_2::LPF_2(){
	start = true;
}

void LPF_2::set_param(double fc_, double Q_, double dt_){
	fc = fc_;
    Q = Q_;
	dt = dt_;

    wc = math_2pi*fc_;

    K0 = Q + wc*dt + Q*dt*dt*wc*wc;
    K1 = Q*dt*dt*wc*wc / K0;
    K2 = (2.0*Q + wc*dt) / K0;
    K3 = Q / K0;
}

void LPF_2::get_param(double* fc_, double* Q_, double* dt_){
	*fc_ = fc;
    *Q_ = Q;
	*dt_ = dt;
}

void LPF_2::set_fc(double fc_){
	fc = fc_;

    wc = math_2pi*fc_;

    K0 = Q + wc*dt + Q*dt*dt*wc*wc;
    K1 = Q*dt*dt*wc*wc / K0;
    K2 = (2.0*Q + wc*dt) / K0;
    K3 = Q / K0;
}

void LPF_2::set_Q(double Q_){
	Q = Q_;

    K0 = Q + wc*dt + Q*dt*dt*wc*wc;
    K1 = Q*dt*dt*wc*wc / K0;
    K2 = (2.0*Q + wc*dt) / K0;
    K3 = Q / K0;
}

void LPF_2::set_dt(double dt_){
	dt = dt_;
    
    K0 = Q + wc*dt + Q*dt*dt*wc*wc;
    K1 = Q*dt*dt*wc*wc / K0;
    K2 = (2.0*Q + wc*dt) / K0;
    K3 = Q / K0;
}

double LPF_2::get_fc(){
	return fc;
}

double LPF_2::get_Q(){
	return Q;
}

double LPF_2::get_dt(){
	return dt;
}

double LPF_2::get_y(){
	return y_i;
}

double LPF_2::update(double x_i){
	if(start==0){
		start = 1;
		y_i = x_i;
	}
    else if(start==1){
        start = 2;
        y_i = x_i;
    }
	else{
		y_i = K1*x_i + K2*y_i_1 + K3*y_i_2;
	}

	y_i_2 = y_i_1;
	y_i_1 = y_i;

	return y_i;
}

void LPF_2::reset(){
    y_i_2 = 0.0;
    y_i_1 = 0.0;
    y_i = 0.0;
    start = 0;
}