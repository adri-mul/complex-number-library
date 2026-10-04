#include <iostream>
#include <stdlib.h>

#ifndef Complex_H
#define COMPLEX_H
    class Complex {
        public:
            double re, im;
            Complex();
            Complex(double r, double i);

            friend Complex operator +(Complex a, Complex b); 
            friend Complex operator -(Complex a, Complex b);
            friend Complex operator -(Complex a);
            friend Complex operator *(Complex a, Complex b);
            friend Complex operator *(int a, Complex b); 
            friend Complex operator /(Complex a, Complex b);
            friend Complex exp(const Complex a);
            friend Complex sqrt(const Complex a);
            friend Complex log(const Complex a);
            friend Complex conj(Complex a);
            friend Complex polar(double mag, double ang);
            friend double arg(const Complex a);
            friend double norm(const Complex a);
            friend double abs(const Complex a);
            friend double real(const Complex& a);
            friend bool operator ==(Complex a, Complex b);
            friend bool operator !=(Complex a, Complex b);
            friend void operator +=(Complex a, Complex b);
            friend void operator +=(Complex a, Complex b);
            friend void operator -=(Complex a, Complex b);
            friend void operator *=(Complex a, Complex b);
            friend void operator /=(Complex a, Complex b);
            friend std::ostream& operator <<(std::ostream& out, Complex b);
    };


#endif