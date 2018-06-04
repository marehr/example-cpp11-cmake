#include <iostream>

#include "complex.hpp"

int main() {
	Complex a(3,5);
	Complex b;
	b = a;

	std::cout << a.getReal() << " " << a.getImag() << " " << a.abs() << std::endl;
	std::cout << b.getReal() << " " << b.getImag() << " " << b.abs() << std::endl;

	return 0;
}
