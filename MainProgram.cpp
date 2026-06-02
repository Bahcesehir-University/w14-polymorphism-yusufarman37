// ============================================================
// MainProgram.cpp  —  STUDENT VERSION
// Lab: Inheritance and Polymorphism
// Standard: C++17  |  Single file only, no headers
// ------------------------------------------------------------
// Complete every TODO. Do NOT rename classes, methods, or
// functions: the autograder depends on these exact names.
// ============================================================
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
// ================================
// CLASS DEFINITIONS
// ================================
// --- Base class -------------------------------------------------
class Shape {
protected:
   std::string name;
public:
   Shape(const std::string& n) : name(n) {}
   // TODO 1: Make this destructor VIRTUAL.
   virtual ~Shape() {}
   // Pure virtual: Shape is abstract and cannot be instantiated.
   virtual double area() const = 0;
   // describe() is virtual with a default body — leave as is.
   virtual std::string describe() const {       
       return name + " with area " + std::to_string(area());
   }
   std::string getName() const { return name; }
};
// --- Derived class: Circle --------------------------------------
class Circle : public Shape {
private:
   double radius;
public:
   // TODO 2: Write the constructor.
   Circle(double r) : Shape("Circle"), radius(r) {}
   // TODO 3: Override area().  Area of a circle = PI * r * r.
   double area() const override {
       return 3.14 * radius * radius;
   }
};
// --- Derived class: Rectangle -----------------------------------
class Rectangle : public Shape {
protected:
   double width;
   double height;
public:
   // TODO 4: Write the constructor.
   Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}
   // TODO 5: Override area().  Area of a rectangle = width * height.
   double area() const override {
       return width * height;
   }
};
// --- Derived class: Square (inherits from Rectangle) ------------
class Square : public Rectangle {
public:
   // TODO 6: Write the constructor.
   Square(double side) : Rectangle(side, side) {
       name = "Square";
   }
   // Note: Square reuses Rectangle::area() — no need to rewrite it.
};
// ================================
// FUNCTION IMPLEMENTATIONS
// ================================
// TODO 7: Sum the area() of every shape in the vector.
double totalArea(const std::vector<Shape*>& shapes) {
   double total = 0.0;
   for (const Shape* s : shapes) {
       if (s) total += s->area();
   }
   return total;
}
// TODO 8: Return getName() of the shape with the LARGEST area.
std::string largestShapeName(const std::vector<Shape*>& shapes) {
   if (shapes.empty()) return "";
   double maxArea = -1.0;
   std::string result = "";
   for (const Shape* s : shapes) {
       if (s) {
           double currentArea = s->area();
           if (currentArea > maxArea) {
               maxArea = currentArea;
               result = s->getName();
           }
       }
   }
   return result;
}
// ================================
// MAIN
// ================================
int main() {
   std::vector<Shape*> shapes;
   shapes.push_back(new Circle(2.0));
   shapes.push_back(new Rectangle(3.0, 4.0));
   shapes.push_back(new Square(5.0));
   for (const Shape* s : shapes) {
       std::cout << s->describe() << std::endl;
   }
   std::cout << "Total area: " << totalArea(shapes) << std::endl;
   std::cout << "Largest:    " << largestShapeName(shapes) << std::endl;
   for (Shape* s : shapes) delete s;
   return 0;
}
