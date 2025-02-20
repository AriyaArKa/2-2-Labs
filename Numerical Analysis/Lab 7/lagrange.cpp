#include <iostream>
#include <vector>

double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi) {
    double result = 0.0;
    int n = x.size();
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i)
                term *= (xi - x[j]) / (x[i] - x[j]);
        }
        result += term;
    }
    return result;
}

int main() {
    std::vector<double> x = {0, 1, 2, 4};
    std::vector<double> y = {1, 2, 1, 3};
    double xi = 3; // point to interpolate
    std::cout << "Interpolated value at " << xi << " is " << lagrangeInterpolation(x, y, xi) << std::endl;
    return 0;
}
