#include <iostream>
#include "Node.h"
#include <math.h>

using namespace std;

Node::Node() {
    x = 0;
    y = 0;
}

Node::Node(double x, double y): x(x), y(y) {}

void Node::display() {
    cout << "x: " << x << "\ty: " << y << endl;
}

void Node::updateValue(double x, double y) {
    this->x = x;
    this->y = y;
}

double pointsDistance(Node a, Node b){
    double wynik=0;
    wynik= sqrt(pow(b.x-a.x, 2)+pow(b.y-a.y, 2));
    return wynik;
}

int main() {
    Node t1, t2;
    t1.updateValue(12.3, 4.6);
    t2.updateValue(3.1, 2.6);
    cout<<pointsDistance(t1,t2);
    return 0;
}
