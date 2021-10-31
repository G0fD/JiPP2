#include<iostream>

using namespace std;

struct samochod{
    string marka;
    string model;
    int rok_produkcji;
    string kolor;
    int dodatkowy;
};

void liczmarka(samochod *test, int n){
    int wynik=1, k=0;
    int *tmp=new int[n];
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(test[i].marka==test[j].marka && i!=j) {
                wynik++;
            }
        }
        tmp[k]=wynik; k++;
        wynik=1;
    }
    for(int i=0; i<n;i++){
        if (tmp[i]>=2){
            for(int j=0; j<n;j++){
                if(tmp[i]==tmp[j]){
                    if(test[i].marka==test[j].marka &&i!=j){
                        tmp[j]=0;
                    }
                }
            }
        } else tmp[i]=0;
    }
    for (int i=0;i<n;i++){
        if(tmp[i]>0) {
            cout << test[i].marka <<": "<<tmp[i]<<endl;
        }
    }
    delete [] tmp;
}

int najstarszy(samochod *test, int n){
    int temp=test[0].rok_produkcji;
    int wynik=0;
    for (int i=1; i<n; i++){
        if (test[i].rok_produkcji<=temp){
            temp=test[i].rok_produkcji;
            wynik=i;
        }
    }
    return wynik;
}

int main()
{
    int ilosc=5, indeks;
    samochod auta[]{{"Mercedes","GLA", 2015, "czarny"},
                    {"BMW", "M3", 2018, "bialy"},
                    {"Kia","Picanto",2021,"srebrny"},
                    {"Mercedes", "GLS", 2019, "czerwony"},
                    {"BMW", "3 GT", 1970, "czerwony"}};


    cout << "Marka\tModel \tRok produkcji \tKolor" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < ilosc; i++)
    {
        cout << auta[i].marka << "     \t" << auta[i].model << "\t" << auta[i].rok_produkcji <<"\t" << auta[i].kolor << endl;
    }
    liczmarka(auta, ilosc);
    indeks= najstarszy(auta, ilosc);
    cout<<"Najstarszy znajduje sie pod indeksem: "<<najstarszy(auta, ilosc)<<" i jest to "<<auta[indeks].marka<<" "<<auta[indeks].model<<" "<<auta[indeks].rok_produkcji<<" "<<auta[indeks].kolor<<endl;
    return 0;
}