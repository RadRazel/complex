#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{

public:
    // Конструкторы
    Complex();                          // (0, 0)
    Complex(double real);               // (real, 0)
    Complex(double real, double imag); // (re, im)

    // Конструктор по модулю и аргументу (полярная форма)
    static Complex FromPolar(double r, double phi);

    // Методы
    double GetRe() const;
    double GetIm() const;

    Complex Conj() const; // комплексно-сопряженное
    double Abs() const;   // модуль
    double Arg() const;   // аргумент (atan2)

    // Операции присваивания
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    Complex& operator+=(double value);
    Complex& operator-=(double value);
    Complex& operator*=(double value);
    Complex& operator/=(double value);

    // Унарные
    Complex operator+() const;
    Complex operator-() const;

    //  Дружественные операции
    friend Complex operator+(Complex lhs, const Complex& rhs);
    friend Complex operator-(Complex lhs, const Complex& rhs);
    friend Complex operator*(Complex lhs, const Complex& rhs);
    friend Complex operator/(Complex lhs, const Complex& rhs);

    friend Complex operator+(Complex lhs, double rhs);
    friend Complex operator-(Complex lhs, double rhs);
    friend Complex operator*(Complex lhs, double rhs);
    friend Complex operator/(Complex lhs, double rhs);

    friend Complex operator+(double lhs, Complex rhs);
    friend Complex operator-(double lhs, const Complex& rhs);
    friend Complex operator*(double lhs, Complex rhs);
    friend Complex operator/(double lhs, const Complex& rhs);

    //  Потоки 
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);

private:
    double re;
    double im;
};

#endif
