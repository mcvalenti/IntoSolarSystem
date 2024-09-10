/*
 * main.cpp
 *
 *  Created on: Aug 16, 2024
 *      Author: mcvalenti
 */

#include <iostream>
#include <cmath>
#include "VectMath.h"

using namespace std;

/*
	S(1.0) = 0.175201
	C(1.0) = 0.543081
	S(-1.0) = 0.158529
	C(-1.0) = -0.459698
	S(0.0) = 0.5
	C(0.0) = 0.5
*/

int main() {

	/*
	 Under development:
	 Lambert's Problem algorithm.
	 The idea is to use spice + some computation to generates the
	 imputs of a Venus flyby for GMAT simulation.
	 Example: Curtis 5.2 - pag 270
	 */

	// ----------------------------------------
	// STUMPFF FUNCTIONS
	//-----------------------------------------
	double zz;
	double ss;
	zz=1.0;
	if (zz>0){
		ss=(std::sqrt(zz)-std::sin(std::sqrt(zz)))/(std::pow(std::sqrt(zz),1.5));
 		} else if (zz<0) {
			ss=(std::sinh(std::sqrt(-zz))-std::sqrt(-zz))/(std::pow(std::sqrt(-zz),1.5));
		}
	std::cout<<"S: "<<ss<<std::endl;
	// ----------------------------------------

	const double deg2rad=M_PI/180.0;
	double v1[]={5000.0,10000.0,2100.0}; // Curtis Example 5.2 - pag 270
	double v2[]={-14600.0,2500.0,7000.0};
	double v3[3];
	DVector r1(v1,3);
	DVector r2(v2,3);
	DVector r3(v3,3); // Cross product Vector
	double dotproduct=0;

	// 1 -Compute module
	double mr1, mr2;
	mr1=r1.positionModule();
	mr2=r2.positionModule();
	cout<<"r1: "<<mr1<<std::endl;
	cout<<"r2: "<<mr2<<std::endl;

	// 2 -Compute delta anomaly (dotProduct)
	double dtheta;
	r3=r1.cross(r2);
	dotproduct=r1*r2;
	if (r3[2]>0){
		// Retrograde definition
		dtheta=acos(dotproduct/(mr1*mr2));
	} else {
		dtheta=2*M_PI-acos(dotproduct/(mr1*mr2));
	}
	cout<<"Dtheta [deg]: "<<dtheta/deg2rad<<endl;
	// 3 -Compute constant A
	double A=0;
	double Aroot=0;
	Aroot=sqrt(mr1*mr2/(1-cos(dtheta)));
	A = sin(dtheta)*Aroot;
	cout<<"A: "<<A<<endl;

	// 4 -Resolve Kepler Equation for z with Newton Method
	Correct Stumpff Functions in gral_functions modules
	Compute the Newton Rapson method to estimatez


	// 5 -Compute y(z)
	// 6 -Compute Lagrange Coefficients using universal-variables
	// 7 -Compute v1 and v2 using Lagrange Coefficients
	// 8 -Use any of the state vectors (r1,v1) or (r2,v2) to compute orbital elements.

    return 0;
}


