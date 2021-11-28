#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

class Figure{
public:
    virtual double getArea() = 0; //Przypisujemy 0, aby nie było ciała metody
};

class Circle: public Figure {
private:
    double r;
public:
    Circle(double r){
        this->r = r;
    }
    double getArea(){
        return M_PI*r*r;
    }
};

class Rectangle: public Figure {
private:
    double a, b;
public:
    Rectangle(double a, double b){
        this->a = a;    //Rectangle::a=a;       odwołanie do zmiennej klasy, zmienna klasy przyjmuje wartość a po prawej stronie
        this->b = b;
    }
     double getArea(){
        return a*b;
    }
};

int main() {
    Figure *circle = new Circle(5);
    Figure *rectangle = new Rectangle(5, 18);

    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;
}