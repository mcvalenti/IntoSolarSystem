/*
 * main.cpp
 *
 *  Created on: Aug 16, 2024
 *      Author: mcvalenti
 */

#include <iostream>
#include "spice_functions.h"
using namespace std;

int main() {

	int result;
	result=run_spice();
	if (result ==0){
		std::cout<<"Process completed!"<<std::endl;
	}
    return 0;
}


