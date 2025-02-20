#include <iostream>
#include <vector>

double numericalDifferentiation(const std::vector<double>& x, const std::vector<double>& y, double xi) {
    int n = x.size();
    for (int i = 0; i < n; i++) {
        if (x[i] == xi) {
            if (i == 0)
                return (y[i + 1] - y[i]) / (x[i + 1] - x[i]); // Forward difference
            else if (i == n - 1)
                return (y[i] - y[i - 1]) / (x[i] - x[i - 1]); // Backward difference
            else
                return (y[i + 1] - y[i - 1]) / (x[i + 1] - x[i - 1]); // Central difference
        }
    }
    return 0; // xi not found in x
}

int main() {
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {1, 4, 9, 16, 25}; // f(x) = 2x, so derivative should be 2
    double xi = 5; // Point at which to differentiate
    std::cout << "Numerical Derivative at " << xi << ": " << numericalDifferentiation(x, y, xi) << std::endl;
    return 0;
}
