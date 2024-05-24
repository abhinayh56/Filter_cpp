#include "HPF_1.h"

HPF_1::HPF_1(){
	start = true;
}

void HPF_1::init(float fc_, float dt_){
	set_param(fc_, dt_);
	start = true;
}

void HPF_1::set_param(float fc_, float dt_){
	fc = fc_;
	dt = dt_;

	tau = 1.0 / (2.0*math_pi*fc);
	alpha = tau / (dt + tau);
}

float HPF_1::update(float x_i){
	if(start==true){
		start = false;
		y_i = x_i;
	}
	else{
		y_i = alpha*(y_i_1 + x_i - x_i_1);
	}
	x_i_1 = x_i;
	y_i_1 = y_i;

	return y_i;
}

void HPF_1::reset(){
	x_i_1 = 0.0;
	y_i_1 = 0.0;
	y_i = 0.0;
	start = true;
}

void HPF_1::set_fc(float fc_){
	fc = fc_;

	tau = 1.0 / (2.0*math_pi*fc);
	alpha = tau / (dt + tau);
}

void HPF_1::set_tau(float tau_){
	tau = tau_;

	fc = 1.0 / (2.0*math_pi*tau);
	alpha = tau / (dt + tau);
}

void HPF_1::set_dt(float dt_){
	dt = dt_;

	alpha = tau / (dt + tau);
}

void HPF_1::set_alpha(float alpha_){
	alpha = alpha_;

	tau = (alpha/(1.0 - alpha)) * dt;
	fc = 1.0 / (2.0*math_pi*tau);
}

float HPF_1::get_fc(){
	return fc;
}

float HPF_1::get_tau(){
	return tau;
}

float HPF_1::get_dt(){
	return dt;
}

float HPF_1::get_alpha(){
	return alpha;
}

float HPF_1::get_y(){
	return y_i;
}