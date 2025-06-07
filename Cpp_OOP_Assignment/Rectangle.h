#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double width, double height)
        : Shape("Rectangle"), width(width), height(height) {
        if (width <= 0 || height <= 0) {
            throw invalid_argument("Rectangle sides must be positive.");
        }
    }

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }

    bool isSquare() const {
        return width == height;
    }

    void describe() const override {
        cout << name << (isSquare() ? " (Square)\n" : "\n");
        cout << "Width: " << width << ", Height: " << height << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }

    void save(ofstream& out) const override {
        out << "Rectangle " << width << " " << height << endl;
    }

    static Rectangle* load(ifstream& in) {
        double w, h;
        in >> w >> h;
        return new Rectangle(w, h);
    }
};

#endif