#include <iostream>
#include <vector>

double newtonsBackwardInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi) {
    int n = x.size();
    std::vector<std::vector<double>> backwardDiff(n, std::vector<double>(n));
    
    for (int i = 0; i < n; i++)
        backwardDiff[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            backwardDiff[i][j] = backwardDiff[i][j - 1] - backwardDiff[i - 1][j - 1];
        }
    }

    double h = x[1] - x[0];
    double u = (xi - x[n - 1]) / h;
    double result = y[n - 1];
    double term = 1;

    for (int i = 1; i < n; i++) {
        term *= (u + (i - 1)) / i;
        result += term * backwardDiff[n - 1][i];
    }

    return result;
}


int main() {
    std::vector<double> x = {0, 1, 2, 3};
    std::vector<double> y = {1, 2, 1, 3};
    double xi = 2.5; // point to interpolate
    std::cout << "Interpolated value at " << xi << " is " << newtonsBackwardInterpolation(x, y, xi) << std::endl;
    return 0;
}