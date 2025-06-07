#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <cmath>

class Triangle : public Shape {
private:
    double a, b, c;

    bool isValid() const {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    string triangleType() const {
        if (a == b && b == c) return "Equilateral";
        else if (a == b || b == c || a == c) return "Isosceles";
        else return "Scalene";
    }

public:
    Triangle(double a, double b, double c)
        : Shape("Triangle"), a(a), b(b), c(c) {
        if (!isValid()) {
            throw invalid_argument("Invalid triangle sides.");
        }
    }

    double area() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() const override {
        return a + b + c;
    }

    void describe() const override {
        cout << name << " (" << triangleType() << ")\n";
        cout << "Sides: " << a << ", " << b << ", " << c << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }

    void save(ofstream& out) const override {
        out << "Triangle " << a << " " << b << " " << c << endl;
    }

    static Triangle* load(ifstream& in) {
        double a, b, c;
        in >> a >> b >> c;
        return new Triangle(a, b, c);
    }
};

#endif