#include <iostream>
#include <vector>
#include <utility>

std::pair<double, double> leastSquaresMethod(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / n;

    return {a, b};
}

int main() {
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 4, 5, 4, 5};

    std::pair<double, double> result = leastSquaresMethod(x, y);
    std::cout << "Fitted line: y = " << result.first << " + " << result.second << " * x" << std::endl;

    return 0;
}
