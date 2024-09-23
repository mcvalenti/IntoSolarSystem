/*
 * main.cpp
 *
 *  Created on: Aug 16, 2024
 *      Author: mcvalenti
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include "SpiceUsr.h"
using namespace std;

#define SCLKID -82
#define STRLEN 50

double calculate_angle(SpiceDouble pos1[], SpiceDouble pos2[]) {
    // Producto punto
    double dot_product = pos1[0] * pos2[0] + pos1[1] * pos2[1] + pos1[2] * pos2[2];

    // Normas
    double norm1 = sqrt(pos1[0] * pos1[0] + pos1[1] * pos1[1] + pos1[2] * pos1[2]);
    double norm2 = sqrt(pos2[0] * pos2[0] + pos2[1] * pos2[1] + pos2[2] * pos2[2]);

    // Angle [rad]
    double angle = acos(dot_product / (norm1 * norm2));

    // Angle [deg]
    return angle * (180.0 / M_PI);
}

int main() {

	//Local
	SpiceChar      calet [STRLEN];
	SpiceChar      utctim []="2029 jul 21 19:32:00";
	SpiceChar      tdbtim []="2029 jul 21 19:32:00 TDB";
	SpiceDouble    tdbet;
	SpiceChar      tdbStr[64];
	SpiceDouble    et;
	SpiceDouble    lt;
	//SpiceDouble    state_e [6];
    SpiceDouble    pos_earth[3];
    SpiceDouble    pos_venus[3];
	//SpiceDouble    dist;

	// Load leapseconds kernel
	furnsh_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\naif0008.tls");
	// Cargar el archivo de ephemeris
	furnsh_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\de431p1.bsp");
	// otro archivo de ephemeris adicional
	furnsh_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\de440.bsp");

	// MANIPULATE TIME
	std::cout<<"Converting UTC Time entered: "<<utctim<<std::endl;
	//Convert UTC to et
	str2et_c (utctim, &et);
	std::cout<<"ET Seconds Past J2000: "<<std::setw(16) << std::fixed << std::setprecision(3) << et << std::endl;
	etcal_c (et,STRLEN, calet);
	std::cout<<"Calendar ET: "<<calet<<std::endl;

	// TIME ITERATIONS
	str2et_c(tdbtim, &tdbet);
	for (int i=0; i<584;++i){
		et2utc_c(tdbet, "ISOC", 0, 64, tdbStr); // TDB to SpiceChar

	    // Earth and Venus positions
	    spkpos_c("EARTH", tdbet, "J2000", "NONE", "SUN", pos_earth, &lt);
	    spkpos_c("VENUS"
	    		"", tdbet, "J2000", "NONE", "SUN", pos_venus, &lt);

	    // Compute angle
	    double angle = calculate_angle(pos_earth, pos_venus);
	    std::cout <<tdbStr<< " Angle: " << angle << " [deg]" << std::endl;


		/*
		spkpos_c("venus", tdbet, "J2000", "none", "earth", pos, &lt); // Venus distance to Earth
		dist = vnorm_c (pos);
		std::cout<<"    Distance Earth-Venus [km]: "<<tdbStr<<std::setw(16) << std::fixed << std::setprecision(3) << dist << std::endl;
		*/
		tdbet += 86400.0; // Increment of 1 day (in sec)
	}

	unload_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\naif0008.tls");
	furnsh_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\de431p1.bsp");
	furnsh_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\de440.bsp");

    return 0;
}


