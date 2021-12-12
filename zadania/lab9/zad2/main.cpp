/*
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> li= { 10, 20, 42, 50, 75 };


    list<int>::iterator x;
    cout<<"Wynik: "<<endl;

    for (x = li.begin(); x != li.end(); x++) {
//iterator wyjścia do zmiany lub przypisania nowych wartości do wszystkich
// elementów listy
        *x = 4;
    }
    for (x = li.begin(); x != li.end(); x++) {
//używanie iteratora wejściowego do przechodzenia przez listę
        cout << (*x) << " ";
    }

    return 0;
}
*/
/*
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> li= { 10, 20, 42, 50, 75 };


    list<int>::iterator x;
    cout<<"Przejście po elementach listy do przodu."<<endl;


    for (x = li.begin(); x != li.end(); x++) {
//używanie iteratora wejściowego do przechodzenia przez listę
        cout << (*x) << " ";
    }
    cout<<endl;
    cout<<"Przechodzenie przez elementy listy w kierunku wstecznym"<<endl;

    for (x=li.end();x!=li.begin();--x)
    {
        if (x != li.end())
        {
            cout << (*x) << " ";
        }
    }
    cout << (*x);

    return 0;
}


#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> li= {10, 20, 42, 50, 75};
    list<int>::iterator x;

    cout<<"Przejście po elementach listy do przodu "<<endl;


    for (x = li.begin(); x != li.end(); x++) {

        cout << (*x) << " "; //używanie iteratora wejściowego do przechodzenia przez listę
    }
    cout<<endl;

    list<int>::iterator ee = li.begin();

    advance(ee, 3);
    cout << "Element wskazywany przez iterator po użyciu metody Advance():";
    cout << *ee << " ";
    cout<<endl;
    list<int>::iterator A = li.begin();
    list<int>::iterator B = li.end();
    //begin, end zwracaja index (czyli od 0)

    auto aa = next(A, 2);
    auto  bb = prev(B, 1);

    cout << "Element wskazany za pomocą next() to : ";
    cout << *aa << " ";
    cout << endl;

    cout << "Element wskazany za pomocą prev() to : ";
    cout << *bb << " ";
    cout << endl;

    return 0;
}
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Music {
private:
    long id;
    string name;
    string autor;
public:
    Music::Music(long id, const string &name, const string &autor) : id(id), name(name), autor(autor) {}
    void print(){
        cout<< id << " " << name << " " << autor <<endl;
    }
    long getId(){
        return id;
    }
};

class Playlista {
private:
    vector<Music> muzyka;
public:
    void addSong(Music *stop) {
        muzyka.push_back(*stop);
    }
    void delSong(Music music){
        vector<Music>::iterator x=muzyka.begin();
        for (Music u:muzyka){
            if(u.getId()!=music.getId()){
                x++;
                break;
            }
        }
        muzyka.erase(x);
    }
    void print(){
        for(Music u:muzyka){
            u.print();
        }
    }
};

int main ()
{
    int wybor, temp=0;
    string str;
    cout<<"Podaj tekst: ";
    getline(cin,str);
    for ( string::iterator it=str.begin(); it!=str.end(); ++it) {
        *it= toupper(*it);
        cout << *it;
    }
    cout << '\n';

    vector<Music> muzyka;
    muzyka.emplace_back(1, "Marco Polo", "idk");
    muzyka.emplace_back(2, "Polskie Tango", "idk");
    muzyka.emplace_back(3, "On My Way", "idk");
    muzyka.emplace_back(4, "Angel With a Shotgun", "iddk");
    muzyka.emplace_back(5, "PMA", "idk");
    muzyka.emplace_back(6, "Courtesy Call", "idk");

    Playlista pl1;

    pl1.addSong(&muzyka[1]);
    pl1.addSong(&muzyka[3]);
    pl1.print();
    pl1.delSong(muzyka[1]);
    pl1.print();

    return 0;
}