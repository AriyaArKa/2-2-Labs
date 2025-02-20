#include <iostream>
#include <vector>

double trapezoidalRule(const std::vector<double>& x, const std::vector<double>& y) {
    double sum = 0.0;
    for (int i = 0; i < x.size() - 1; i++) {
        sum += (x[i + 1] - x[i]) * (y[i] + y[i + 1]) / 2.0;
    }
    return sum;
}

int main() {
    std::vector<double> x = {0, 1, 2, 3, 4};
    std::vector<double> y = {1, 3, 5, 7, 9}; // f(x) = 2x + 1, integral from 0 to 4 should be around 32
    std::cout << "Trapezoidal Rule Result: " << trapezoidalRule(x, y) << std::endl;
    return 0;
}
