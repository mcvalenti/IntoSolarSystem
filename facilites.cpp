/*
 * facilites.cpp
 *
 *  Created on: Aug 30, 2024
 *      Author: macec
 */

#include <iostream>
#include "spice_functions.h"

int run_spice_facility(){
	int result;
	result=run_spice();
	std::cout<<result<<std::endl;
	return result;
}
