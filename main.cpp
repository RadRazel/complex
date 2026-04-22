#include <iostream>
#include <cassert>
#include <cmath>
#include "complex.h"

bool almostEqual(double a, double b, double eps = 1e-9) {
    return std::abs(a - b) < eps;
}

bool complexEqual(const Complex& a, const Complex& b, double eps = 1e-9) {
    return almostEqual(a.GetRe(), b.GetRe(), eps) &&
           almostEqual(a.GetIm(), b.GetIm(), eps);
}

int main()
{
    Complex a(3, 4);
    Complex b(1, -2);

    assert(complexEqual(a + b, Complex(4, 2)));
    assert(complexEqual(a - b, Complex(2, 6)));
    assert(complexEqual(a * b, Complex(11, -2)));
    assert(complexEqual(a / b, Complex(-1, 2)));

    
    assert(complexEqual(a + 5, Complex(8, 4)));
    assert(complexEqual(5 + a, Complex(8, 4)));

    assert(complexEqual(a - 5, Complex(-2, 4)));
    assert(complexEqual(5 - a, Complex(2, -4)));

    assert(complexEqual(a * 2, Complex(6, 8)));
    assert(complexEqual(2 * a, Complex(6, 8)));

    assert(complexEqual(a / 2, Complex(1.5, 2)));
    assert(complexEqual(5 / Complex(1, 2), Complex(1, -2)));

    // свойства
    Complex res = (a / b) * b;
    assert(almostEqual(res.GetRe(), a.GetRe()));
    assert(almostEqual(res.GetIm(), a.GetIm()));

    // сопряжение
    Complex c = a.Conj().Conj();
    assert(complexEqual(c, a));

    // модуль
    assert(almostEqual(a.Abs(), 5));

    // искл
    try {
        Complex(1, 2) / Complex(0, 0);
        assert(false);
    } catch (std::runtime_error&) {}

    try {
        5 / Complex(0, 0);
        assert(false);
    } catch (std::runtime_error&) {}

    try {
        a / 0;
        assert(false);
    } catch (std::runtime_error&) {}

    std::cout << "All tests passed\n";
    return 0;
}
