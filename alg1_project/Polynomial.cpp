#include "Polynomial.h"
#include <cmath>


Polynomial::Polynomial(vector<double>& coefficients)
{
	this->coefficients = coefficients;
}

Polynomial::Polynomial(double& coefficient)
{
	this->coefficients.push_back(coefficient);
}

Polynomial Polynomial::operator+(Polynomial& other)
{
	vector <double> new_coeffs(max(coefficients.size(),other.coefficients.size()),0);

	for (int i = 0; i < coefficients.size(); i++) {
		new_coeffs[i] += coefficients[i];
	}

	for (int i = 0; i < other.coefficients.size(); i++) {
		new_coeffs[i] += other.coefficients[i];
	}


	return Polynomial(new_coeffs);
}

Polynomial Polynomial::operator-(Polynomial& other)
{
	vector <double> new_coeffs(max(coefficients.size(), other.coefficients.size()), 0);

	for (int i = 0; i < new_coeffs.size(); i++) {
		int coeff1 = (i < coefficients.size()) ? coefficients[i] : 0;
		int coeff2 = (i < other.coefficients.size()) ? other.coefficients[i] : 0;

		new_coeffs[i] = coeff1 - coeff2;
	}

	return Polynomial(new_coeffs);
}

Polynomial Polynomial::operator*(Polynomial& other)
{
	vector <double> new_coeffs(coefficients.size() + other.coefficients.size()-1, 0);

	for (int i = 0; i < coefficients.size(); i++) {
		for (int j = 0; j < other.coefficients.size(); j++) {
			new_coeffs[i + j] += coefficients[i] * other.coefficients[j];
		}
	}

	return Polynomial(new_coeffs);
}

void Polynomial::Print()
{
	if (coefficients.size() == 1) {
		cout << "P(x)=";
		cout << coefficients[0];
	}
	else {
		cout << "P(x)=";

		for (int i = coefficients.size() - 1; i >= 0; --i) {
			if (coefficients[i] == 0)
				continue;

			if (coefficients[i] > 0 && i != coefficients.size() - 1)
				cout << "+";

			if (coefficients[i] != 1 || i == 0)
				cout << coefficients[i];

			if (i >= 2)
				cout << "x^" << i;
			else if (i == 1)
				cout << "x";
		}
	}
	cout << endl;
}

int Polynomial::Degree()
{
	for (int i = coefficients.size() - 1; i >= 0; i--) {
		if (coefficients[i] != 0) {
			return i;
		}
	}
	return 0;
}

double Polynomial::Substitution(double x)
{
	double result = 0;
	for (int i = 0; i < coefficients.size(); i++) {
		result += coefficients[i] * pow(x, i);
	}

	return result;
}

Polynomial Polynomial::Derivative()
{
	vector<double> derivativeCoefficients;
	double zero=0.0;
	if (coefficients.size() <= 1) {
		return Polynomial(zero);
	}

	
	for (size_t i = 1; i < coefficients.size(); ++i) {
		derivativeCoefficients.push_back(coefficients[i] * i);
	}

	
	return Polynomial(derivativeCoefficients);
}

Polynomial Polynomial::Primitive()
{
	vector<double> primitiveCoefficients(coefficients.size() + 1, 0);

	for (size_t i = 0; i < coefficients.size(); i++) {
		primitiveCoefficients[i] = coefficients[i] / (i + 1);
	}

	return Polynomial(primitiveCoefficients);
}
