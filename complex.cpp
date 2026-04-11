#include "complex.h"
#include <cmath>
#include <stdexcept>

//  Конструкторы
Complex::Complex() : re(0), im(0) {}

Complex::Complex(double real) : re(real), im(0) {}

Complex::Complex(double real, double imag) : re(real), im(imag) {}

Complex Complex::FromPolar(double r, double phi)
{
    return Complex(r * cos(phi), r * sin(phi));
}

//  Методы
double Complex::GetRe() const { return re; }
double Complex::GetIm() const { return im; }

Complex Complex::Conj() const
{
    return Complex(re, -im);
}

double Complex::Abs() const
{
    return std::sqrt(re * re + im * im);
}

double Complex::Arg() const
{
    return std::atan2(im, re);
}

//  Операции присваивания
Complex& Complex::operator+=(const Complex& other)
{
    re += other.re;
    im += other.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
    re -= other.re;
    im -= other.im;
    return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
    double r = re * other.re - im * other.im;
    double i = re * other.im + im * other.re;
    re = r;
    im = i;
    return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
    double denom = other.re * other.re + other.im * other.im;
    if (denom == 0)
        throw std::runtime_error("Division by zero");

    double r = (re * other.re + im * other.im) / denom;
    double i = (im * other.re - re * other.im) / denom;
    re = r;
    im = i;
    return *this;
}

Complex& Complex::operator+=(double value)
{
    re += value;
    return *this;
}

Complex& Complex::operator-=(double value)
{
    re -= value;
    return *this;
}

Complex& Complex::operator*=(double value)
{
    re *= value;
    im *= value;
    return *this;
}

Complex& Complex::operator/=(double value)
{
    if (value == 0)
        throw std::runtime_error("Division by zero");
    re /= value;
    im /= value;
    return *this;
}

//  Унарные
Complex Complex::operator+() const
{
    return *this;
}

Complex Complex::operator-() const
{
    return Complex(-re, -im);
}

//  Бинарные
Complex operator+(Complex lhs, const Complex& rhs)
{
    lhs += rhs;
    return lhs;
}

Complex operator-(Complex lhs, const Complex& rhs)
{
    lhs -= rhs;
    return lhs;
}

Complex operator*(Complex lhs, const Complex& rhs)
{
    lhs *= rhs;
    return lhs;
}

Complex operator/(Complex lhs, const Complex& rhs)
{
    lhs /= rhs;
    return lhs;
}

// complex o double
Complex operator+(Complex lhs, double rhs)
{
    lhs += rhs;
    return lhs;
}

Complex operator-(Complex lhs, double rhs)
{
    lhs -= rhs;
    return lhs;
}

Complex operator*(Complex lhs, double rhs)
{
    lhs *= rhs;
    return lhs;
}

Complex operator/(Complex lhs, double rhs)
{
    lhs /= rhs;
    return lhs;
}

// double o complex
Complex operator+(double lhs, Complex rhs)
{
    rhs += lhs;
    return rhs;
}

Complex operator-(double lhs, const Complex& rhs)
{
    return Complex(lhs - rhs.re, -rhs.im);
}

Complex operator*(double lhs, Complex rhs)
{
    rhs *= lhs;
    return rhs;
}

Complex operator/(double lhs, const Complex& rhs)
{
    double denom = rhs.re * rhs.re + rhs.im * rhs.im;
    if (denom == 0)
        throw std::runtime_error("Division by zero");

    return Complex(lhs * rhs.re / denom, -lhs * rhs.im / denom);
}

//  Потоки 
std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os << "(" << c.re << ", " << c.im << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c)
{
    is >> c.re >> c.im;
    return is;
}
