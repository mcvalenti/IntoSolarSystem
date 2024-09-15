/*
 * gral_functions.cpp
 *
 *  Created on: Sep 10, 2024
 *      Author: macec
 */

#include <cmath>
#include "gral_functions.h"

double C_z(double z){
	// ----------------------------------------
	// STUMPFF FUNCTIONS
	//-----------------------------------------
	//Replace in one expression with S
	double Cz;
	Cz=(1/2.0)-(z/24.0);
	return Cz;
}

double S_z(double z){
	// ----------------------------------------
	// STUMPFF FUNCTIONS
	//-----------------------------------------
	//Replace in one expression with S
	double Sz;
	Sz=(1/6.0)-(z/120.0);
	return Sz;
}

double y_z(double r1, double r2, double A, double z){
	double Yz;
	Yz=r1+r2+A*(z*S_z(z)-1)/sqrt(C_z(z));
	return Yz;
}

double F_z(double Cz, double Sz, double A, double Yz, double mu_body, double delta_t){
	double Fz;
	Fz=pow(Yz/Cz,3/2)*Sz+A*sqrt(Yz)-sqrt(mu_body*delta_t);
	return Fz;
}

double F_z_dot(double z, double Cz, double Sz, double A, double Yz, double Yzero){
	double Fzdot;
	double bracket;
	if (z != 0){
		bracket=(1/(2*z))*(Cz-3*Sz/(2*Cz))+3*Sz*Sz/(4*Cz);
		Fzdot = pow(Yz/Cz,3/2)*bracket+(A/8)*((3*Sz*sqrt(Yz)/Cz)+A*sqrt(Cz/Yz));
	} else if (z=0){
		Fzdot = (sqrt(2)*pow(Yzero,3/2)/40.0)+(A/8)*(sqrt(Yzero)+A*sqrt(1/(2*Yzero)));
	}
	return Fzdot;
}

