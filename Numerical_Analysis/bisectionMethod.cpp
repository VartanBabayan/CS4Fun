#include <iostream>
#include <cmath>
#include <functional>

void bisectionMethod(double a, double b, double eps, std::function<double(double)> f)
{
  if (f(a) * f(b) >= 0)
    std::cout << "There is no root in the interval: " << a << "\t" << b << "\n";

  int i = 0;
  double x = 0.0;
  while (true)
  {
    x = a + (b - a) / 2;
    std::cout << "interval: [" << a << " , " << b << "]"
            << "\t iter: " << i << "\t point: " << x << "\n";

    if (abs(f(x)) < eps)
      break;

    // reducing the interval [a, b]
    if (f(a) * f(x) < 0)
      b = x;  // a = a
    else
      a = x;  // b = b

    ++i;
  }

  std::cout << "\nFound the approximate root: " << x << " with " << i << " iterations" << std::endl;
}

int main()
{
  auto f = [](double x) { return (cos(2.0 / x) - (2 * sin(1.0 / x)) + (1.0 / x)); };
  auto g = [](double x) { return (pow(x, 3) - 3 * x + 1); };
  bisectionMethod(-2, -1, 0.001, g);
}
