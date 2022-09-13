#include <iostream>
#include <functional>

// Algorithm to define if the approximate interval with the root exists in the range [a, b]

void stepMethod(double a, double b, size_t n, std::function<double(double)> f)
{
  double h = (b - a) / n;
  size_t i = 0;
  for (double x = a; x <= b; x += h)
  {
    if (f(x) * f(x + h) < 0)
    {
      ++i;
      std::cout << "root between: [" << x << ", " << x + h << "]" << "\n";
    }
  }

  std::cout << "Found " << i << " intervals where roots are located" << std::endl;
}

int main()
{
  auto f = [](double x) { return (cos(2.0 / x) - (2 * sin(1.0 / x)) + (1.0 / x)); };
  auto g = [](double x) { return (pow(x, 3) - 3 * x + 1); };
  stepMethod(1, 2, 5, f);
}
