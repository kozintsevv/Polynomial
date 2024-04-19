#pragma once

#include <iostream>
#include <vector>
#include "Symbol.h"

using namespace std;

/**
 * @brief A class representing a polynomial.
 *
 * This class allows for the creation and manipulation of polynomials.
 */
class Polynomial
{
private:
    vector<double> coefficients; /**< Coefficients of the polynomial */

public:
    /**
     * @brief Constructs a polynomial with the given coefficients.
     *
     * @param coefficients Coefficients of the polynomial
     */
    Polynomial(vector<double>& coefficients);

    /**
     * @brief Constructs a polynomial of degree 0 with the given coefficient.
     *
     * @param coefficient Coefficient of the constant term
     */
    Polynomial(double& coefficient);

    /**
     * @brief Overloaded addition operator for polynomials.
     *
     * @param other Another polynomial to add
     * @return Resulting polynomial after addition
     */
    Polynomial operator+(Polynomial& other);

    /**
     * @brief Overloaded subtraction operator for polynomials.
     *
     * @param other Another polynomial to subtract
     * @return Resulting polynomial after subtraction
     */
    Polynomial operator-(Polynomial& other);

    /**
     * @brief Overloaded multiplication operator for polynomials.
     *
     * @param other Another polynomial to multiply
     * @return Resulting polynomial after multiplication
     */
    Polynomial operator*(Polynomial& other);

    /**
     * @brief Prints the polynomial to the standard output.
     */
    void Print();

    /**
     * @brief Calculates the degree of the polynomial.
     *
     * @return Degree of the polynomial
     */
    int Degree();

    /**
     * @brief Evaluates the polynomial at the given value of x.
     *
     * @param x Value at which to evaluate the polynomial
     * @return Result of the polynomial substitution
     */
    double Substitution(double x);

    /**
     * @brief Computes the derivative of the polynomial.
     *
     * @return Derivative of the polynomial
     */
    Polynomial Derivative();

    /**
     * @brief Computes the primitive (indefinite integral) of the polynomial.
     *
     * @return Primitive of the polynomial
     */
    Polynomial Primitive();
};

