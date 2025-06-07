#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(string name) : name(name) {}
    virtual ~Shape() {}

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void describe() const = 0;

    virtual void save(ofstream& out) const = 0;
    static Shape* load(ifstream& in); // Factory method
};

#endif
