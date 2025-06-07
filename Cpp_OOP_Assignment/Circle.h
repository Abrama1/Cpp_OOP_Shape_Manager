#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <cmath>

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius)
        : Shape("Circle"), radius(radius) {
        if (radius <= 0) {
            throw invalid_argument("Radius must be positive.");
        }
    }

    double area() const override {
        return 3.141592653589793 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.141592653589793 * radius;
    }

    void describe() const override {
        cout << name << "\n";
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }

    void save(ofstream& out) const override {
        out << "Circle " << radius << endl;
    }

    static Circle* load(ifstream& in) {
        double r;
        in >> r;
        return new Circle(r);
    }
};

#endif
