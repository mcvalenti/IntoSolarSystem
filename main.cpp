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
	 */

	const double deg2rad=M_PI/180.0;

	// STUMPFF FUNCTIONS
	double z;
	double s;
	z=1.0;
	if (z>0){
		s=(std::sqrt(z)-std::sin(std::sqrt(z)))/(std::pow(std::sqrt(z),1.5));
 		} else if (z<0) {
			s=(std::sinh(std::sqrt(-z))-std::sqrt(-z))/(std::pow(std::sqrt(-z),1.5));
		}
	std::cout<<"S: "<<s<<std::endl;

	double v1[]={1,2,3};
	double v2[]={4,-5,6};
	double v3[3];
	DVector r1(v1,3);
	DVector r2(v2,3);
	DVector r3(v3,3); // Cross product Vector

	// 1 -Compute module
	double mr1, mr2;
	mr1=r1.positionModule();
	mr2=r2.positionModule();
	cout<<mr1<<std::endl;
	cout<<mr2<<std::endl;

	// 2 -Compute delta anomaly (dotProduct)
	double dotproduct=0;
	double dtheta;
	r3=r1.cross(r2);
	dotproduct=r1*r2;
	cout<<dotproduct<<endl;
	//Revisar dotproduct
	if (r3[2]<=0){
		dtheta=acos(dotproduct/(mr1*mr2));
	}
	cout<<"Dtheta [deg]: "<<dtheta/deg2rad<<endl;
	// 3 -Compute constant A
	// 4 -Resolve Kepler Equation with Newton Method
	// 5 -Compute y(z)
	// 6 -Compute Lagrange Coefficients using universal-variables
	// 7 -Compute v1 and v2 using Lagrange Coefficients
	// 8 -Use any of the state vectors (r1,v1) or (r2,v2) to compute orbital elements.

    return 0;
}


