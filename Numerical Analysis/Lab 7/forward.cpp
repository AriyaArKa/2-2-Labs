#include <iostream>
#include <vector>

double newtonsForwardInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi) {
    int n = x.size();
    std::vector<std::vector<double>> forwardDiff(n, std::vector<double>(n));
    
    for (int i = 0; i < n; i++)
        forwardDiff[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            forwardDiff[i][j] = forwardDiff[i + 1][j - 1] - forwardDiff[i][j - 1];
        }
    }

    double h = x[1] - x[0];
    double u = (xi - x[0]) / h;
    double result = y[0];
    double term = 1;

    for (int i = 1; i < n; i++) {
        term *= (u - (i - 1)) / i;
        result += term * forwardDiff[0][i];
    }

    return result;
}


int main() {
    std::vector<double> x = {0, 1, 2, 3};
    std::vector<double> y = {1, 2, 1, 3};
    double xi = 1.5; // point to interpolate
    std::cout << "Interpolated value at " << xi << " is " << newtonsForwardInterpolation(x, y, xi) << std::endl;
    return 0;
}