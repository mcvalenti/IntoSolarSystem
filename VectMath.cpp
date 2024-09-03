/*
 * VectMath.cpp
 *
 *  Created on: Aug 30, 2024
 *      Author: mcvalenti
 */


#include "VectMath.h"
#include <string.h>
#include <stdexcept>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;



// Constructors
DVector::DVector()
{
	// empty DVector
    this->vec = NULL;
    this->asize = 0;
    //ctor
}
DVector::DVector(  double* vec, unsigned asize)
{
	// DVector from array
    this->vec = new   double[asize];
    this->asize = asize;
    //ctor
    memcpy(this->vec, vec, asize*sizeof(vec[0]));
}
DVector::DVector(unsigned asize)
{
	// DVector initialize in zeros
    this->vec = new double[asize];
    this->asize = asize;
    for(unsigned i=0;i<asize;i++){
        this->vec[i] = 0.0;
    }
}
DVector::DVector(const DVector &other)
{
	// DVector from another DVector
    this->vec = new double[other.asize];
    this->asize = other.asize;
    //ctor
    memcpy(this->vec, other.vec, other.asize*sizeof(vec[0]));
}


// Operators
const DVector DVector::operator+(const DVector &other)const{
	// Sum of DVector elements with another DVector elements
    DVector result(other.asize);
    for(unsigned i=0;i<this->asize;i++){
        result.vec[i] = this->vec[i] + other.vec[i];
    }
    return result;
}
const DVector DVector::operator-(const DVector &other)const{
	// Sum of DVector elements with another DVector elements
    DVector result(other.asize);
    for(unsigned i=0;i<this->asize;i++){
        result.vec[i] = this->vec[i] - other.vec[i];
    }
    return result;
}
DVector& DVector::operator=(const DVector &other){
	// Set a DVector equal to other
    delete [] this->vec;
    this->vec = new   double[other.asize];
    this->asize = other.asize;

    memcpy(this->vec, other.vec, asize*sizeof(vec[0]));
    return *this;
}
DVector& DVector::operator+=(const DVector &other){

    if(other.asize!=this->asize)
        throw std::runtime_error("out of bounds");

    for(unsigned i=0;i<this->asize;i++){
        this->vec[i] += other.vec[i];
    }
    return *this;
}
const DVector DVector::operator*( double val)const{
	// Multiply DVector elements with double const
    DVector result(this->asize);
    for(unsigned i=0;i<this->asize;i++){
        result.vec[i] = this->vec[i] * val;
    }
    return result;
}

double DVector::operator*(const DVector &other){
	//  Computes the dot product a.b=c
    double dotproduct=0;
    if(other.asize!=this->asize)
        throw std::runtime_error("out of bounds");
    for(unsigned i=0;i<this->asize;i++){
        dotproduct += this->vec[i] * other.vec[i];
    }
    return dotproduct;
}

double& DVector::operator[](unsigned index){
	// DVector element
    if(index>asize-1){
        throw std::runtime_error("out of bounds");
    }
    return this->vec[index];
}
const double& DVector::operator[](unsigned index)const{
	// DVector element
    if(index>asize-1){
        throw std::runtime_error("out of bounds");
    }
    return this->vec[index];
}

ostream& operator<<(ostream& os, const DVector& vec){
	// Print DVector
	os << std::fixed;
    os << std::setprecision(10);
    for(unsigned i=0;i<vec.asize;i++){
        os<<vec.vec[i]<<"\t";
    }
    return os;
}


// Methods
double DVector::getValue(unsigned index){
	// DVector elements
    return this->vec[index];
}

double DVector::positionModule(){
	double module;
	module=sqrt((this->vec[0])*(this->vec[0])+
					 (this->vec[1])*(this->vec[1])+
					 (this->vec[2])*(this->vec[2]));
	return module;
};

DVector DVector::cross(const DVector &other){
	// Computs the cross product vec x other =result
	DVector result(other.asize);
    if(other.asize!=this->asize)
        throw std::runtime_error("out of bounds");
    result[0]=this->vec[1]*other[2]-other[1]*this->vec[2];
    result[1]=-(this->vec[0]*other[2]-other[0]*this->vec[2]);
    result[2]=this->vec[0]*other[1]-other[0]*this->vec[1];
    return result;
}





/*bool DVector::areEqual(const DVector &other, double tolerance){
	for(unsigned i=0;i<this->asize;i++){
		if (abs(vec[i]-other[i])>tolerance){
			return false;
		}
	}
	return true;
}*/
/*double DVector::get_max_absolute(const DVector &other){
	unsigned aux=abs(vec[0]);
	for (unsigned i=0;i<this->asize;i++){
		if (abs(vec[i])>aux){
			aux=vec[i];
		}
	}
	return aux;
}*/

DVector::~DVector()
{
    //dtor
    delete [] this->vec;
}
