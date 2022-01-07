#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    string nr_linii, poczatek, koniec, oprtr;
    ifstream input("../dane.csv");
    ofstream autobus("../autobus.csv");
    ofstream tramwaj("../tramwaj.csv");
    if(input.is_open()) {
        while(input.peek()!=EOF) {
            getline(input,nr_linii,',');
            getline(input, poczatek, ',');
            getline(input, koniec, ',');
            getline(input, oprtr, '\n');

            if(atoi(nr_linii.c_str())>=100 && atoi(nr_linii.c_str())<=999)
                autobus<<nr_linii<<","<<poczatek<<","<<koniec<<","<<oprtr<<"\n";
            if(atoi(nr_linii.c_str())>=1 && atoi(nr_linii.c_str())<=99)
                tramwaj<<nr_linii<<","<<poczatek<<","<<koniec<<","<<oprtr<<"\n";
        }
        autobus.close();
        tramwaj.close();
        input.close();
    } else {
        cout << "Error on opening file" << endl;
        exit(1);
    }
}
