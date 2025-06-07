#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <vector>
#include <limits>

using namespace std;

Shape* Shape::load(ifstream& in) {
    string type;
    in >> type;
    if (type == "Triangle") return Triangle::load(in);
    if (type == "Rectangle") return Rectangle::load(in);
    if (type == "Circle") return Circle::load(in);
    return nullptr;
}

void showMenu() {
    cout << "\n--- Shape Manager ---\n";
    cout << "1. Add Shape\n";
    cout << "2. View All Shapes\n";
    cout << "3. Save to File\n";
    cout << "4. Load from File\n";
    cout << "5. Exit\n";
    cout << "Select an option: ";
}

void addShape(vector<Shape*>& shapes) {
    int choice;
    cout << "Choose shape to add (1.Triangle 2.Rectangle 3.Circle): ";
    cin >> choice;

    try {
        if (choice == 1) {
            double a, b, c;
            cout << "Enter 3 sides: ";
            cin >> a >> b >> c;
            shapes.push_back(new Triangle(a, b, c));
        }
        else if (choice == 2) {
            double w, h;
            cout << "Enter width and height: ";
            cin >> w >> h;
            shapes.push_back(new Rectangle(w, h));
        }
        else if (choice == 3) {
            double r;
            cout << "Enter radius: ";
            cin >> r;
            shapes.push_back(new Circle(r));
        }
        else {
            cout << "Invalid shape option.\n";
        }
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void viewShapes(const vector<Shape*>& shapes) {
    if (shapes.empty()) {
        cout << "No shapes available.\n";
        return;
    }
    for (const auto& shape : shapes) {
        cout << "------------------\n";
        shape->describe();
    }
}

void saveToFile(const vector<Shape*>& shapes, const string& filename) {
    ofstream out(filename);
    for (const auto& shape : shapes) {
        shape->save(out);
    }
    out.close();
    cout << "Shapes saved to " << filename << endl;
}

void loadFromFile(vector<Shape*>& shapes, const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "Cannot open file.\n";
        return;
    }
    shapes.clear();
    while (!in.eof()) {
        Shape* s = Shape::load(in);
        if (s) shapes.push_back(s);
    }
    in.close();
    cout << "Shapes loaded from " << filename << endl;
}

int main() {
    vector<Shape*> shapes;
    int option;

    // Pre-load two of each shape
    shapes.push_back(new Triangle(3, 4, 5));
    shapes.push_back(new Triangle(6, 6, 6));
    shapes.push_back(new Rectangle(4, 4));
    shapes.push_back(new Rectangle(3, 5));
    shapes.push_back(new Circle(5));
    shapes.push_back(new Circle(2.5));

    do {
        showMenu();
        cin >> option;

        switch (option) {
        case 1: addShape(shapes); break;
        case 2: viewShapes(shapes); break;
        case 3: saveToFile(shapes, "shapes.txt"); break;
        case 4: loadFromFile(shapes, "shapes.txt"); break;
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid option.\n";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (option != 5);

    for (auto s : shapes) delete s;
    return 0;
}
