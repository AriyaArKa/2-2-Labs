#include <iostream>
#include <vector>

double simpsonsThreeEighthRule(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size() - 1;
    double h = (x.back() - x.front()) / n;
    double sum = y.front() + y.back();
    for (int i = 1; i < n; i += 3) {
        sum += 3 * (y[i] + y[i + 1]);
    }
    for (int i = 3; i < n - 1; i += 3) {
        sum += 2 * y[i];
    }
    return (3 * h / 8) * sum;
}

int main() {
    std::vector<double> x = {1, 2, 3, 4};
    std::vector<double> y = {1, 4, 9, 16};
    std::cout << "Simpson's 3/8 Rule Result: " << simpsonsThreeEighthRule(x, y) << std::endl;
    return 0;
}
