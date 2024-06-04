#include "HPF_1.h"

HPF_1::HPF_1(){
	start = true;
}

void HPF_1::init(double fc_, double dt_){
	set_param(fc_, dt_);
	start = true;
}

void HPF_1::set_param(double fc_, double dt_){
	fc = fc_;
	dt = dt_;

	tau = 1.0 / (2.0*math_pi*fc);
	alpha = tau / (dt + tau);
}

double HPF_1::update(double x_k){
	double y_k = 0.0;
	
	if(start==true){
		start = false;
		y_k = x_k;
	}
	else{
		y_k = alpha*(y_k_1 + x_k - x_k_1);
	}
	x_k_1 = x_k;
	y_k_1 = y_k;

	return y_k;
}

void HPF_1::reset(){
	x_k_1 = 0.0;
	y_k_1 = 0.0;
	start = true;
}

void HPF_1::set_fc(double fc_){
	set_param(fc_, dt);
}

void HPF_1::set_tau(double tau_){
	tau = tau_;
	fc = 1.0 / (2.0*math_pi*tau);
	alpha = tau / (dt + tau);
}

void HPF_1::set_dt(double dt_){
	set_param(fc, dt_);
}

void HPF_1::set_alpha(double alpha_){
	alpha = alpha_;
	tau = (alpha/(1.0 - alpha)) * dt;
	fc = 1.0 / (2.0*math_pi*tau);
}

double HPF_1::get_fc(){
	return fc;
}

double HPF_1::get_tau(){
	return tau;
}

double HPF_1::get_dt(){
	return dt;
}

double HPF_1::get_alpha(){
	return alpha;
}
