#include <iostream>
#include <string>

using namespace std;

class Note{
private:
    string title;
    friend class TextNote;
public:
    string getTitle(){
        return title;
    }
    void setTitle(string title){
        this->title=title;
    }
    virtual string getContent()=0;
    virtual void setContent(string content)=0;
};

class TextNote: public Note{
private:
    string content;
public:
    string getContent(){
        return content;
    }
    void setContent(string content){
        this->content=content;
    }
};

int main() {
    TextNote test;
    string line;
    cout<<"Podaj tytul notatki: "<<endl;
    getline(cin, line);
    test.setTitle(line);
    cout<<"Podaj tresc notatki: "<<endl;
    getline(cin, line);
    test.setContent(line);
    cout << test.getTitle() <<endl;
    cout << test.getContent();
    return 0;
}
