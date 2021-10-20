#include <iostream>
#include <string.h>
using namespace std;

int pole(int a){
    return a*a;
}
double pole(double a){
    return a*a;
}
int pole(int a, int b){
    return a*b;
}
double pole(double a, double b){
    return a*b;
}
int pole(int a, int b, int h){
    return ((a+b)*h)/2;
}
double pole(double a, double b, double h){
    return ((a+b)*h)/2.;
}


int main(int argc, char* argv[]){
    cout<<"Pole kwadratu: "<<pole(2)<<endl;
    cout<<"Pole kwadratu: "<<pole(2.3)<<endl;
    cout<<"Pole prsotokata: "<<pole(2,5)<<endl;
    cout<<"Pole prsotokata: "<<pole(2.4,5.2)<<endl;
    cout<<"Pole trapezu: "<<pole(2,5,3)<<endl;
    cout<<"Pole trapezu: "<<pole(2.3,5.1,3.4)<<endl;
    return 0;
}