#include <iostream>
#include "complex.h"

int main()
{
    Complex a(3, 4);
    Complex b(1, -2);

    Complex c = a + b;
    Complex d = a * b;
    Complex e = a / b;

    Complex f = a + 5;
    Complex g = 5 + a;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a + b = " << c << "\n";
    std::cout << "a * b = " << d << "\n";
    std::cout << "a / b = " << e << "\n";

    std::cout << "a + 5 = " << f << "\n";
    std::cout << "5 + a = " << g << "\n";

    std::cout << "Conj(a) = " << a.Conj() << "\n";
    std::cout << "|a| = " << a.Abs() << "\n";
    std::cout << "Arg(a) = " << a.Arg() << "\n";

    return 0;
}
