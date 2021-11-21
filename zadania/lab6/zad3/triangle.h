#pragma once
using namespace std;

class Triangle;
class Node {
private:
    double x, y;
    friend class Triangle;
public:
    Node();
    Node(double x, double y);
    friend std::ostream& operator<<(std::ostream &os, const Triangle& obj);
};

class Triangle {
private:
    Node a, b, c;
    string nazwa;
public:
    Triangle();
    Triangle( Node a, Node b, Node c, string nazwa);
    void display();
    double distance(int firstPointIndex, int secondPointIndex);
    friend std::ostream& operator<<(std::ostream &os, const Triangle& obj);
};

void showTriangleData(Triangle triangle);
void showTriangleData(Triangle &triangle);
void showTriangleData(Triangle *triangle);
