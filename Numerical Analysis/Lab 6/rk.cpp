#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

double rk(double x0, double y0, double x, double h, function<double(double, double)> f) {
    int n = static_cast<int>((x - x0) / h); 
    double y = y0;

    for (int i = 0; i < n; i++) {
        double k1 = h * f(x0, y);
        double k2 = h * f(x0 + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x0 + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x0 + h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x0 += h;
    }

    return y;
}

function<double(double, double)> getequ(int choice) {
    double a, b, c;

    switch (choice) {
        case 1:
            cout << "Equation: dy/dx = a*x + b*y\n";
            cout << "Enter a and b values: ";
            cin >> a >> b;
            return [a, b](double x, double y) { return a * x + b * y; };
        case 2:
            cout << "Equation: dy/dx = a*x*y + b\n";
            cout << "Enter a and b values: ";
            cin >> a >> b;
            return [a, b](double x, double y) { return a * x * y + b; };
        case 3:
            cout << "Equation: dy/dx = a*x^2 + b*y + c\n";
            cout << "Enter a, b, and c values: ";
            cin >> a >> b >> c;
            return [a, b, c](double x, double y) { return a * x * x + b * y + c; };
        case 4:
            cout << "Equation: dy/dx = sin(a*x) - b*y\n";
            cout << "Enter a and b values: ";
            cin >> a >> b;
            return [a, b](double x, double y) { return sin(a * x) - b * y; };
        case 5:
            cout << "Equation: dy/dx = e^(a*x) - b*y\n";
            cout << "Enter a and b values: ";
            cin >> a >> b;
            return [a, b](double x, double y) { return exp(a * x) - b * y; };
        case 6:
            cout << "Equation: dy/dx = cos(a*x) + b*y\n";
            cout << "Enter a and b values: ";
            cin >> a >> b;
            return [a, b](double x, double y) { return cos(a * x) + b * y; };
        case 7:
            cout << "Equation: dy/dx = log(a + x) - b*y\n";
            cout << "Enter a and b values (note: a > 0): ";
            cin >> a >> b;
            return [a, b](double x, double y) { return log(a + x) - b * y; };
        default:
            cout << "Invalid choice! Defaulting to dy/dx = x + y.\n";
            return [](double x, double y) { return x + y; };
    }
}

int main() {
    cout << "Choose a differential equation to solve (dy/dx = f(x, y)):\n";
    cout << "1. dy/dx = a*x + b*y\n";
    cout << "2. dy/dx = a*x*y + b\n";
    cout << "3. dy/dx = a*x^2 + b*y + c\n";
    cout << "4. dy/dx = sin(a*x) - b*y\n";
    cout << "5. dy/dx = e^(a*x) - b*y\n";
    cout << "6. dy/dx = cos(a*x) + b*y\n";
    cout << "7. dy/dx = log(a + x) - b*y\n";
    
    int choice;
    cout << "Enter your choice (1-7): ";
    cin >> choice;

    auto differentialEquation = getequ(choice);

    double x0, y0, x, h;
    cout << "Enter initial x0: ";
    cin >> x0;
    cout << "Enter initial y0 (i.e., y(x0)): ";
    cin >> y0;
    cout << "Enter the x value to solve for y(x): ";
    cin >> x;
    cout << "Enter step size h: ";
    cin >> h;

    double result = rk(x0, y0, x, h, differentialEquation);

    cout << "The value of y at x = " << x << " is: " << result << endl;

    return 0;
}
