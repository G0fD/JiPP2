#include <iostream>
#include <cmath>
#include "triangle.h"

using namespace std;
Node::Node() {
    x = 0;
    y = 0;
}
Node::Node(double x, double y): x(x), y(y) {}

Triangle::Triangle() {

}
Triangle::Triangle(Node a, Node b, Node c, string nazwa): a(a), b(b), c(c), nazwa(nazwa) {}

void Triangle::display() {
    cout<<nazwa<<endl;
    cout<<"A: "<<a.x<<" "<<a.y<<endl;
    cout<<"B: "<<b.x<<" "<<b.y<<endl;
    cout<<"C: "<<c.x<<" "<<c.y<<endl;
}
std::ostream& operator<<(std::ostream &os, const Triangle& obj)
{
    os << obj.nazwa <<endl;
    os << "A: "<<obj.a.x<<" "<<obj.a.y<<endl;
    os << "B: "<<obj.b.x<<" "<<obj.b.y<<endl;
    os << "C: "<<obj.c.x<<" "<<obj.c.y<<endl;
    return os;
}
double Triangle::distance(int firstPointIndex, int secondPointIndex) {
    double wynik=0;
    Node tmp1, tmp2;
    switch (firstPointIndex) {
        case 0:
            tmp1=a;
            break;
        case 1:
            tmp1=b;
            break;
        case 2:
            tmp1=c;
            break;
        default:
            cout<<endl<<"Blad"<<endl;
            return 0;
    }
    switch (secondPointIndex) {
        case 0:
            tmp2=a;
            break;
        case 1:
            tmp2=b;
            break;
        case 2:
            tmp2=c;
            break;
        default:
            cout<<endl<<"Blad"<<endl;
            return 0;
    }
    wynik = sqrt(pow(tmp2.x-tmp1.x, 2)+pow(tmp2.y-tmp1.y, 2));
    return wynik;
}

void showTriangleData(Triangle *triangle){
    triangle->display();
}
