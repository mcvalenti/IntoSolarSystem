/*
 * gral_functions.h
 *
 *  Created on: Sep 10, 2024
 *      Author: macec
 */

#ifndef GRAL_FUNCTIONS_H_
#define GRAL_FUNCTIONS_H_


double C_z(double z);
double S_z(double z);
double y_z(double r1, double r2, double A);
double F_z(double Cz, double Sz, double A, double Yz, double mu_body, double delta_t);
double F_z_dot(double Cz, double Sz, double A, double Yz, double Yzero);

#endif /* GRAL_FUNCTIONS_H_ */
