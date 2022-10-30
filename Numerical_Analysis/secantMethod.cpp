#include <iostream>
#include <functional>
#include <cmath>

void secantMethod(double a, double b, double eps,
									std::function<double(double)> f,
									std::function<double(double)> f1,
									std::function<double(double)> f2)
{
	double xn_1, xn;
	if (f(a) * f2(a) + eps > 0)
	{
		xn_1 = a;
		xn = a + eps;
	}
	else if (f(b) * f2(b) + eps > 0)
	{
		xn_1 = b;
		xn = b + eps;
	}
	else {
		std::cout << "The interval [" << a << "," << b << "] is invalid\n";
	}

	size_t i = 0;
	double x;
	while(true)
	{
		x = xn - ( f(xn) * (xn - xn_1) ) / ( f(xn) - f(xn_1) );
		std::cout << i << "\t" << x << "\n";
		++i;

		if (std::abs(x - xn) < eps)
			break;
	
		xn_1 = xn;
		xn = x;
	}

	std::cout << "Found root: " << x << " with " << i << " iterations\n";
}

int main()
{
	auto f =  [](double x) { return std::pow(x, 3) - 3 * x + 1; };
	auto f1 = [](double x) { return 3 * std::pow(x, 2) - 3; };
	auto f2 = [](double x) { return 6 * x; };
	
	constexpr double a = 1, b = 2, eps = 0.01;
	secantMethod(a, b, eps, f, f1, f2);
}
