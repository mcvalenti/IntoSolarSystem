/*
 * main.cpp
 *
 *  Created on: Aug 16, 2024
 *      Author: macec
 */

#include <iostream>
#include "SpiceUsr.h"

int main() {
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Earth and Venus positions" << std::endl;
	std::cout << "-----------------------------" << std::endl;
    try {
        // Cargar el archivo de segundos intercalares
        furnsh_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\naif0012.tls");  // Asegurate de usar la ruta correcta

        // Cargar el archivo de ephemeris
        furnsh_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\de431p1.bsp");    // Intenta con este archivo primero
        // Si el problema persiste, carga otro archivo de ephemeris adicional
        furnsh_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\de440.bsp");    // Intenta con este archivo si es necesario

        // Fecha de interes en formato de tiempo ET (Ephemeris Time)
        SpiceDouble et;
        str2et_c("2020-08-17 TDB", &et);

        // Variables para almacenar las posiciones
        SpiceDouble venusPos[3];
        SpiceDouble earthPos[3];
        SpiceDouble lt;

        // Obtener la posicion de Venus con respecto a la Tierra
        spkezr_c("venus", et, "J2000", "NONE", "earth", venusPos, &lt);
        std::cout << "Posicion de Venus (km):" << std::endl;
        std::cout << "X: " << venusPos[0] << std::endl;
        std::cout << "Y: " << venusPos[1] << std::endl;
        std::cout << "Z: " << venusPos[2] << std::endl;

        // Obtener la posicion de la Tierra con respecto al Sol
        spkezr_c("earth", et, "J2000", "NONE", "sun", earthPos, &lt);
        std::cout << "Posicion de la Tierra (km):" << std::endl;
        std::cout << "X: " << earthPos[0] << std::endl;
        std::cout << "Y: " << earthPos[1] << std::endl;
        std::cout << "Z: " << earthPos[2] << std::endl;

        // Finalizar el uso del sistema SPICE descargando los kernels
        unload_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\de431p1.bsp");
        unload_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\de440.bsp");
        unload_c("C:\\Users\\macec\\AppData\\Local\\cspice\\cspice\\data\\naif0012.tls");
    }
    catch (const std::exception& e) {
        std::cerr << "Se produjo un error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

