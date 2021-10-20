#include <iostream>
#include <time.h>

using namespace std;

int rnd(int a, int b){
    int liczba;
    liczba = a + rand() % (b - a + 1);
    return liczba;
}
void odwroc(int*& tab, int a){
    int *temp = new int[a];
    for(int i=0; i<a;i++){
        temp[i]=tab[(a-1-i)];
    }
    tab=temp;
}

int main(int argc, char* argv[]){
    srand(time(0));
    int max, a = rnd(10,20);
    int * tablica = new int[a];
    for (int i=0; i<a; i++){
        tablica[i]=rnd(1,100);
        cout<<tablica[i]<<" ";
    }
    max=0;
    for (int i=0; i<a; i++){
        if(tablica[i]>max)max=tablica[i];
    }
    cout<<endl;
    cout<<"Max: "<<max<<endl;
    odwroc(tablica,a);
    for(int i=0; i<a;i++) cout<<tablica[i]<<" ";
    cout<<endl;
    delete [] tablica;
    return 0;
}