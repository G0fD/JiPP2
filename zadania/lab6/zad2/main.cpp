#include <iostream>
#include <math.h>

using namespace std;

class Vector {
private:
    double x, y;

public:
    Vector() {};

    Vector(double x, double y) : x(x), y(y) {}

    double length() {
        return sqrt(x * x + y * y);
    }

    Vector operator+(const Vector &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }
    Vector operator-(const Vector &rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    Vector &operator+=(const Vector &rhs) {
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        return *this;
    }
    Vector &operator-=(const Vector &rhs) {
        this->x = this->x - rhs.x;
        this->y = this->y - rhs.y;
        return *this;
    }

    //przeciwny
    Vector operator!() const {
        return {-x,-y};
    }
    //iloczyn skalarny
    double operator&(const Vector &rhs) const {
        return (x * rhs.x + y * rhs.y);
    }

    //mnozenie przez skalar
    Vector operator&&(double skalar){
        return {x*skalar, y*skalar};
    }
    //porownanie wektorow
    string operator/(const Vector &rhs) const {
        if(x==rhs.x && y==rhs.y) return "Sa takie same";
        else return "Sa rozne";
    }
    //wypisz
    void print(){
        cout<<"X: "<<x<<" Y: "<<y<<endl;
    }
    //przeciazenie <<
    friend std::ostream& operator<<(std::ostream &os, const Vector& obj);
};

std::ostream& operator<<(std::ostream &os, const Vector& obj)
{
    os << obj.x<<" "<< obj.y;
    return os;
}

class imNumbers {
private:
    double a, b;
public:
    imNumbers() {};

    imNumbers(double a, double b) : a(a), b(b) {}

    //dodawanie
    imNumbers operator+(const imNumbers &rhs) const {
        return {a + rhs.a, b + rhs.b};
    }
    //odejmowanie
    imNumbers operator-(const imNumbers &rhs) const {
        return {a - rhs.a, b - rhs.b};
    }
    //mnozenie
    imNumbers operator*(const imNumbers &rhs) const {
        double temp1=0;
        double temp2=0;
        temp1=(a*rhs.a)+(b*rhs.b*-1);
        temp2=(a*rhs.b)+(b*rhs.a);
        return {temp1, temp2};
    }
    //wypisz
    void print(){
        cout<<a<<" +"<<b<<"i"<<endl;
    }
};

int main() {
    //wektory
    Vector v1(2,1), v2(5,10);
    Vector v3 = v1 + v2;
    Vector v4 = v1 - v2;
    Vector v5 = v1;
    double v6 = v1 & v2;
    Vector v7 = v1 && 3;
    string v8 = v1 / v2;
    //v3 = v1.operator+(v2);        //alternatywna forma zapisania v3
    //v4=v1.operator-(v2);
    v5=v5.operator!();
    v3.print();v4.print();v5.print();
    cout<<"Iloczyn skalarny: "<<v6<<endl;
    v7.print();
    cout<<v8<<endl<<endl;

    //Liczby urojone
    imNumbers imNum1(2.1, 3), imNum2(5, -1);
    imNumbers imNum3 = imNum1 + imNum2;
    imNumbers imNum4 = imNum1 * imNum2;
    imNum3.print();imNum4.print();

    //przeciazenie <<
    cout<<"TEST: "<<endl;
    cout<<v1;
    return 0;
}
