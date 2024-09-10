/*
 * VectMath.h
 *
 *  Created on: Aug 30, 2024
 *      Author: mcvalenti
 */

#ifndef VECTMATH_H_
#define VECTMATH_H_

#include <iostream>

using namespace std;

class DVector
{
    private:

        unsigned asize;
    public:
        double* vec;

        // Constructors
        DVector();
        DVector(unsigned asize);
        DVector(double* vec, unsigned asize);
        DVector(const DVector &other);

        // Operators
        double& operator[](unsigned index);
        const double& operator[](unsigned index)const;
        const DVector operator+(const DVector &other)const;
        const DVector operator-(const DVector &other)const;
        DVector& operator+=(const DVector &other);
        DVector& operator=(const DVector &other);
        const DVector operator*(double val)const;

        double operator*(const DVector &other)const;
        friend ostream& operator<<(ostream& os, const DVector& vec);

        // Methods
        //bool areEqual(const LDVector &other, double tolerance);
        //double get_max_absolute(const LDVector &other);
        double getValue(unsigned index);
        double positionModule();
        DVector cross(const DVector &other);

        virtual ~DVector();

};


#endif /* VECTMATH_H_ */
