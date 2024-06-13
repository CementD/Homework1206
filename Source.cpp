#include <iostream>
#include <cmath>
using namespace std;

class Equation {
public:
    virtual void solution() const = 0;
    virtual void print() const = 0;
};

class LinearEquation : public Equation {
    int a, b;
public:
    LinearEquation(int A, int B) : a(A), b(B) {}

    void solution() const override {
        if (a != 0) {
            double x = double(-b) / a;
            cout << "The solution of linear equation: x = " << x << endl;
        }
        else if (a == 0 && b == 0) {
            cout << "The equation has infinitely many solutions." << endl;
        }
        else {
            cout << "No solution." << endl;
        }
    }

    void print() const override {
        cout << a << "x ";
        if (b < 0) {
            cout << "- " << abs(b);
        }
        else {
            cout << "+ " << b;
        }
        cout << " = 0" << endl;
    }
};

class QuadraticEquation : public Equation {
    int a, b, c;
public:
    QuadraticEquation(int A, int B, int C) : a(A), b(B), c(C) {}

    void solution() const override {
        double D = pow(b, 2) - 4 * a * c;
        if (D > 0) {
            double x1 = double(-b + sqrt(D)) / (2 * a);
            double x2 = double(-b - sqrt(D)) / (2 * a);
            cout << "The solutions of quadratic equation: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
        else if (D == 0) {
            double x = double(-b) / (2 * a);
            cout << "The solution of quadratic equation: x = " << x << endl;
        }
        else {
            cout << "No real solutions." << endl;
        }
    }

    void print() const override {
        cout << a << "x^2 ";
        if (b < 0) {
            cout << "- " << abs(b) << "x ";
        }
        else {
            cout << "+ " << b << "x ";
        }
        if (c < 0) {
            cout << "- " << abs(c);
        }
        else {
            cout << "+ " << c;
        }
        cout << " = 0" << endl;
    }
};

int main() {
    LinearEquation e1(2, -4);
    e1.print();
    e1.solution();

    QuadraticEquation e2(3, -14, -5);
    e2.print();
    e2.solution();

    return 0;
}