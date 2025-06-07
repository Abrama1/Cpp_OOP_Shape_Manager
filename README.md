# C++ OOP Shape Manager

This is a C++ console application that manages a collection of geometric shapes: Triangles, Rectangles, and Circles. The project demonstrates core object-oriented programming (OOP) principles including **encapsulation**, **inheritance**, and **polymorphism**.

---

## 📌 Features

- Add shapes via user input
- View all shapes with:
  - Type information
  - Area and perimeter
  - Triangle classification (Equilateral / Isosceles / Scalene)
  - Rectangle type detection (Square / Not Square)
- Save all shapes to a file
- Load shapes from file (using polymorphism)
- Validation and user-friendly error handling

---

## 🧠 OOP Concepts Used

| Concept       | Usage                                                                 |
|---------------|-----------------------------------------------------------------------|
| Encapsulation | Shape dimensions are private and validated through constructors      |
| Inheritance   | Triangle, Rectangle, and Circle all inherit from the abstract `Shape` |
| Polymorphism  | Virtual functions allow storing all shapes in a `vector<Shape*>`     |
| Abstraction   | The `Shape` class defines a generic interface for all shape types     |
| Virtual Destructors | Used for proper memory cleanup in polymorphic base class       |

---

## 🛠️ How to Compile

### Using g++ (Linux/macOS/Windows with MinGW)
```bash
g++ -std=c++11 Cpp_OOP_Assignment.cpp -o ShapeApp
./ShapeApp
```

### Using Visual Studio
1. Open the solution.
2. Set `Cpp_OOP_Assignment.cpp` as the **Startup File**.
3. Build and run.

---

## 📂 Project Structure

```
/project-root
├── Cpp_OOP_Assignment.cpp     // Main logic and menu
├── Shape.h                    // Abstract base class
├── Triangle.h                 // Triangle class
├── Rectangle.h                // Rectangle class
├── Circle.h                   // Circle class
├── shapes.txt                 // File for saving/loading shapes
├── README.md                  // This file
```
