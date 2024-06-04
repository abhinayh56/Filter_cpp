#include "MA.h"

MA::MA(){
	start = true;
}

void MA::init(double fc_, double dt_){
	set_param(fc_, dt_);
	start = true;
}

void MA::set_param(double fc_, double dt_){
	fc = fc_;
	dt = dt_;
	tau = 1.0 / (2.0*math_pi*fc);
	alpha = dt / (dt + tau);
}

void MA::set_x_arr(double* x_arr_, uint16_t len_arr_){
	x_arr = x_arr_;
	n = len_arr_;
}

double MA::update(double x_k){
	double y_k = 0.0;
	for(uint16_t i=0;i<n-1;i++){
		x_arr[i] = x_arr[i+1];
	}
	x_arr[n-1] = x_k;

	double sum = 0.0;
	for(uint16_t i=0;i<n;i++){
		sum = sum + x_arr[i];
	}
	y_k = sum / n;
	return y_k;
}

void MA::reset(){
	start = true;
}

void MA::set_fc(double fc_){
	set_param(double fc_, double dt);
}

void MA::set_dt(double dt_){
	set_param(double fc, double dt_);
}

void MA::set_n(double n_){
	n = n_;
}

double MA::get_fc(){
	return fc;
}

double MA::get_dt(){
	return dt;
}

double MA::get_n(){
	return n;
}
