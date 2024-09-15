/*
 * spice_functions.cpp
 *
 *  Created on: Aug 29, 2024
 *      Author: macec
 */
#include <iostream>
#include <cstring>
#include <cmath>
#include "spice_functions.h"
#include "SpiceUsr.h"

int run_spice(){

	char year_mm[8]="2024-08";
	char my_date[24];
	char salva_memoria[17]="Error paranormal";
	double max_distance_earth = 0;
	double distance_earth = 0;
	double max_distance_venus = 0;
	double distance_venus = 0;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Earth and Venus positions" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	try {
		// Cargar el archivo de segundos intercalares
		furnsh_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\naif0012.tls");

		// Cargar el archivo de ephemeris
		furnsh_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\de431p1.bsp");
		// otro archivo de ephemeris adicional
		furnsh_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\de440.bsp");

		for (int day=1; day<=4; day++){
			// Fecha de interes en formato de tiempo ET (Ephemeris Time)
			SpiceDouble et;
			sprintf(my_date, "%s-%02dT00:00:00.000",year_mm,day);
			str2et_c(my_date, &et);

			// Variables para almacenar las posiciones
			SpiceDouble venusPos[3];
			SpiceDouble earthPos[3];
			SpiceDouble lt;

			// Obtener la posicion de Venus con respecto a la Tierra
			spkezr_c("venus", et, "J2000", "NONE", "earth", venusPos, &lt);

			// Obtener la posicion de la Tierra con respecto al Sol
			spkezr_c("earth", et, "J2000", "NONE", "sun", earthPos, &lt);


			// Max distance
			distance_earth=sqrt(pow(earthPos[0],2)+pow(earthPos[1],2)+pow(earthPos[2],2));
			distance_venus=sqrt(pow(venusPos[0],2)+pow(venusPos[1],2)+pow(venusPos[2],2));
			if (max_distance_earth < distance_earth){
				max_distance_earth=distance_earth;
				//std::cout<<my_date<<";" <<max_distance_earth<<std::endl;
			}
			if (max_distance_venus < distance_venus){
				max_distance_venus=distance_venus;
			}

			std::cout<<my_date<<";" <<earthPos[0] <<";" <<earthPos[1] <<";"<< earthPos[2]<<";" <<max_distance_earth<<";"
					<<venusPos[0] <<";" << venusPos[1] <<";" <<venusPos[2]<<";" <<max_distance_venus << std::endl;
		}
		// Finalizar el uso del sistema SPICE descargando los kernels
		unload_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\de431p1.bsp");
		unload_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\de440.bsp");
		unload_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\naif0012.tls");
	}
	catch (const std::exception& e) {
		std::cerr << "Se produjo un error: " << e.what() << std::endl;
		return 1;
	}
	std::cout<<salva_memoria<<std::endl;
	return 0;
}





