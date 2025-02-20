#include <iostream>
#include <vector>

double simpsonsOneThirdRule(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size() - 1;
    double h = (x.back() - x.front()) / n;
    double sum = y.front() + y.back();
    for (int i = 1; i < n; i += 2) {
        sum += 4 * y[i];
    }
    for (int i = 2; i < n - 1; i += 2) {
        sum += 2 * y[i];
    }
    return (h / 3) * sum;
}

int main() {
    std::vector<double> x = {1, 2, 3, 4};
    std::vector<double> y = {1, 4, 9, 16};
    std::cout << "Simpson's 1/3 Rule Result: " << simpsonsOneThirdRule(x, y) << std::endl;
    return 0;
}
