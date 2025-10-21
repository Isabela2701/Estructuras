#include <iostream>
#include <iomanip>

class Calculadora {
public:
	// Cinco sobrecargas para combinaciones de (int, float, double)

	float suma(int a, float b, double c) {
		return static_cast<float>(a) + b + static_cast<float>(c);
	}

	float suma(int a, double b, float c) {
		return static_cast<float>(a) + static_cast<float>(b) + c;
	}

	float suma(float a, int b, double c) {
		return a + static_cast<float>(b) + static_cast<float>(c);
	}

	float suma(float a, double b, int c) {
		return a + static_cast<float>(b) + static_cast<float>(c);
	}

	float suma(double a, int b, float c) {
		return static_cast<float>(a) + static_cast<float>(b) + c;
	}
};

int main() {
	Calculadora calc;

	int i = 2;
	float f = 3.5f;
	double d = 4.25;

	std::cout << std::fixed << std::setprecision(4);

	std::cout << "suma(int, float, double) = " << calc.suma(i, f, d) << "\n";
	std::cout << "suma(int, double, float) = " << calc.suma(i, d, f) << "\n";
	std::cout << "suma(float, int, double) = " << calc.suma(f, i, d) << "\n";
	std::cout << "suma(float, double, int) = " << calc.suma(f, d, i) << "\n";
	std::cout << "suma(double, int, float) = " << calc.suma(d, i, f) << "\n";

	return 0;
}

