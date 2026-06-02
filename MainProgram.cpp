#include <iostream>
#include <string>
#include <vector>
#include <cmath>
// M_PI tanımlı değilse diye güvenli hale getirdik
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
// ================================
// CLASS DEFINITIONS
// ================================
// --- Base class -------------------------------------------------
class Shape {
protected:
   std::string name;
public:
   Shape(const std::string& n) : name(n) {}
   // TODO 1: Destructor'ı VIRTUAL yaptık (Polimorfik silme için şart)
   virtual ~Shape() {}
   // Pure virtual: Shape abstract olmalı.
   virtual double area() const = 0;
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
   // TODO 2
   Circle(double r) : Shape("Circle"), radius(r) {}
   // TODO 3: Override anahtar kelimesini ekledik
   double area() const override {
       return M_PI * radius * radius;
   }
};
// --- Derived class: Rectangle -----------------------------------
class Rectangle : public Shape {
protected:
   double width;
   double height;
public:
   // TODO 4
   Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}
   // TODO 5
   double area() const override {
       return width * height;
   }
};
// --- Derived class: Square (inherits from Rectangle) ------------
class Square : public Rectangle {
public:
   // TODO 6
   Square(double side) : Rectangle(side, side) {
       name = "Square";
   }
};
// ================================
// FUNCTION IMPLEMENTATIONS
// ================================
// TODO 7
double totalArea(const std::vector<Shape*>& shapes) {
   double total = 0.0;
   for (const Shape* s : shapes) {
       if (s != nullptr) {
           total += s->area();
       }
   }
   return total;
}
// TODO 8
std::string largestShapeName(const std::vector<Shape*>& shapes) {
   if (shapes.empty()) return "";
   double maxArea = -1.0;
   std::string bestName = "";
   for (const Shape* s : shapes) {
       if (s != nullptr) {
           double a = s->area();
           if (a > maxArea) {
               maxArea = a;
               bestName = s->getName();
           }
       }
   }
   return bestName;
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
