#include <iostream>
#include <cmath>
#include <functional>

void newtonMethod(double a, double b, double eps, 
                  std::function<double(double)> f,
                  std::function<double(double)> f1,
                  std::function<double(double)> f2)
{
    double x0 = 0.0;

    // Fourier check that initial point is valid
    if (f(a) * f2(a) + eps > 0)
        x0 = a;
    else if (f(b) * f2(b) + eps > 0)
        x0 = b;
    else {
        std::cout << "The interval [" << a << "\t" << b << "] is not valid\n";
        return;
    }

    double x = x0;
    size_t i = 0;
    while (true)
    {
        x = x - (f(x) / f1(x));
        std::cout << "iter: " << x << "\t" << f(x) << "\t" << eps << "\t" << (abs(f(x)) < eps) << "\n";
        ++i;

        if (abs(f(x)) < eps) {
            std::cout << "Found root: " << x << "\t" << f(x) << "\t" << eps << "\t" << (abs(f(x)) < eps) << "\n";
            break;
        }

    }

    std::cout << "Found root: " << x << " with " << i << " iterations\n";
}

int main()
{
    auto f  =  [](double x) { return (pow(x, 3) - 3 * x + 1); };  // f(x)
    auto f1 =  [](double x) { return (3 * pow(x, 2) - 3); };      // f'(x) - 1st derivative
    auto f2 =  [](double x) { return 6 * x; };                    // f''(x) - 2nd derivative

    newtonMethod(0, 1, 0.001, f, f1, f2);
}
