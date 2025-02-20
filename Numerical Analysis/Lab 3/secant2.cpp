#include <bits/stdc++.h>
using namespace std;

#define err 1e-6

double degree{0};
vector<double> equ;
int interval{0};
set<double> roots;

void input()
{
    cout << "degree: ";
    cin >> degree;
    cout << "Co-efficients: ";

    for (int i{0}; i < degree + 1; i++)
    {
        double value;
        cin >> value;
        equ.push_back(value);
    }
}

double f(double x)
{
    double sum{0};
    double temp = degree;
    for (int i{0}; i < degree + 1; i++)
    {
        sum += pow(x, temp) * equ[i];
        temp--;
    }

    return sum;
}

bool is_valid(double x)
{
    for (auto a : roots)
    {
        if (fabs(x - a) < err)
            return false;
    }

    return true;
}

double secant(double p)
{
    double b{p};
    double a{p - 1};
    double x{0};
    x = b - (f(b) * (b - a)) / (f(b) - f(a));

    while (fabs(x - b) > err)
    {
        a = b;
        b = x;
        x = b - (f(b) * (b - a)) / (f(b) - f(a));
    }

    return x;
}

int main()
{
    cout << setprecision(6) << fixed;

    input();
    interval = ceil(sqrt(pow((equ[1] / equ[0]), 2) - 2 * (equ[2] - equ[0])));
    interval = -interval;

    for (int i{interval}; i < interval * (-1); i++)
    {
        double p{secant(i)};
        if (is_valid(p))
            roots.insert(p);
    }

    int no{1};
    for (auto a : roots)
    {
        cout << "Root " << no++ << ": " << a << endl;
    }

    return 0;
}
