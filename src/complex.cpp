#include "complex.h"
#define EULER 2.71828182845904523536
#include <cmath>

// Complex constructors
Complex::Complex() {re=0.0; im=0.0;}
Complex::Complex(double r, double i = 0.0) {re=r; im=i;}

// Basic arithmetic operators
Complex operator -(Complex a, Complex b) {
    Complex c;
    c.re = a.re - b.re;
    c.im = a.im - b.im;
    return c;
}
Complex operator -(Complex a) {
    Complex c;
    c.re = -a.re;
    c.im = -a.im;
    return c;
}

Complex exp(const Complex a) {
    Complex c;
    double e_a = pow(EULER, a.re);
    double r = cos(a.im) * e_a;
    double i = sin(a.im) * e_a;

    c.re = r;
    c.im = i;
    return c;
}

double arg(const Complex a) {
    return atan2(a.im, a.re);
}

double real(const Complex& a) {
    return a.re;
}

Complex operator +(Complex a, Complex b) {
    Complex c;
    c.re = a.re + b.re;
    c.im = a.im + b.im; 
    return c;
} 

Complex operator /(Complex a, Complex b) {
    double first = ((a.re)*(b.re) + (a.im)*(b.im))/(pow(b.re, 2) + pow(b.im,2));
    double sec = ((a.im)*(b.re) - (a.re)*(b.im))/( pow(b.re, 2) + pow(b.im,2));

    Complex c;
    c.re = first;
    c.im = sec;
    return c;
    
}

Complex operator *(Complex a, Complex b) {
    double real = a.re * b.re - a.im * b.im;
    double imag = a.re * b.im + b.re * a.im;
    Complex c(real, imag); 
    return c;
}

Complex operator *(int a, Complex b) {
    Complex c(b.re * a, b.im * a); return c;
}

// returns principle root of a
// to get the other root, simple take the negative of the principal root
Complex sqrt(const Complex a) {
    if ((a.im != 0)) {
        double mag = abs(a);
        double real = sqrt((mag + a.re)/2);
        double imag = a.im/abs(a.im) * sqrt((mag - a.re)/2);
        return Complex(real, imag);
    // Formula does not work if a.im is 0, since it would result in a 0/0
    } else if ((a.im == 0) && (a.re != 0)) {
        if (a.re < 0) {
            return Complex(0.0, sqrt(-a.re));
        } else {
            return Complex(sqrt(a.re), 0.0);
        }
    // If both a.re and a.im are zero
    } else {
        return Complex(0.0, 0.0);
    }
    /*
    // This formula doesn't work for purely negative real numbers (no imaginary part)
    if (!(a.re < 0) || (a.im != 0)) {
        double mag = abs(a);
        Complex w(a.re + mag, a.im);
        double constant = sqrt(mag)/abs(w);
        return constant * w;
    } else {
        return Complex(0.0, sqrt(-a.re));
    }*/
}

Complex conj(Complex a) {
    Complex c(a.re, -a.im); return c;
}

Complex polar(double mag, double ang=0.0) {
    double real = mag * cos(ang);
    double imag = mag * sin(ang);
    Complex a(real, imag); return a;
}

// Gives abs**2
double norm(const Complex a) {
    double value;
    value = pow(a.re,2)+pow(a.im,2);
    return value;
}

// Gives the magnitude of the complex coordinate relative to the origin of the complex plane
double abs(const Complex a) {
    double value;
    value = sqrt(pow(a.re,2)+pow(a.im,2));
    return value;
}

bool operator ==(Complex a, Complex b) {
    return (a.re == b.re) && (a.im == b.im);
}

bool operator !=(Complex a, Complex b) {
    if(a.re == b.re && a.im == b.im){
        return false;
    }
    else{
        return true;
    }
}


Complex log(const Complex a) {
    Complex c;
    double r = log(abs(a));
    double i = arg(a);
    c.re = r;
    c.im = i;

    return c;
}

void operator +=(Complex a, Complex b) {
    a = a + b;
}

void operator -=(Complex a, Complex b) {
    a = a - b;
}

void operator *=(Complex a, Complex b) {
    a = a * b;
}

void operator /=(Complex a, Complex b) {
    a = a / b;
}

std::ostream& operator <<(std::ostream& out, Complex b) {out << b.re << " + " << b.im << "i"; return out;}
