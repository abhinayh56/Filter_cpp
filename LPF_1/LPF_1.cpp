#include "LPF_1.h"

LPF_1::LPF_1(){
	start = true;
}

void LPF_1::init(float fc_, float dt_){
	set_param(fc_, dt_);
	start = true;
}

void LPF_1::set_param(float fc_, float dt_){
	fc = fc_;
	dt = dt_;
	tau = 1.0 / (2.0*math_pi*fc);
	alpha = dt / (dt + tau);
}

float LPF_1::update(float x_k){
	double y_k = 0.0;
	
	if(start==true){
		start = false;
		y_k = x_k;
	}
	else{
		y_k = alpha*x_k + (1.0 - alpha)*y_k_1;
	}
	y_k_1 = y_k;
	return y_k;
}

void LPF_1::reset(){
	y_k_1 = 0.0;
	start = true;
}

void LPF_1::set_fc(float fc_){
	set_param(float fc_, float dt);
}

void LPF_1::set_tau(float tau_){
	tau = tau_;
	fc = 1.0 / (2.0*math_pi*tau);
	alpha = dt / (dt + tau);
}

void LPF_1::set_dt(float dt_){
	set_param(float fc, float dt_);
}

void LPF_1::set_alpha(float alpha_){
	alpha = alpha_;
	tau = ((1.0 - alpha)*dt) / alpha;
	fc = 1.0 / (2.0*math_pi*tau);
}

float LPF_1::get_fc(){
	return fc;
}

float LPF_1::get_tau(){
	return tau;
}

float LPF_1::get_dt(){
	return dt;
}

float LPF_1::get_alpha(){
	return alpha;
}
