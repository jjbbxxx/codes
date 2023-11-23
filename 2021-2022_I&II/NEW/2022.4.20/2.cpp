#include <bits/stdc++.h>
using namespace std;
class Publication
{
protected:
    char *name;

public:
    virtual void show() = 0;
    Publication(const char *s)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }
};
class Time
{
public:
    int y, m, d;
    Time(int y = 0, int m = 0, int d = 0) : y(y), m(m), d(d) {}
    void show()
    {
        cout << y << '/' << m << '/' << d;
    }
};
class Library
{
    Publication *publications[100]; // All collections, assuming a collection limit of 100
    static int total;               // Actual holdings
public:
    void add(Publication &p); // Add new collection (this function needs to be completed)
    void show()               // Output corresponding information of all collections
    {
        for (int i = 0; i < total; i++)
            publications[i]->show();
    }
    // ¡°show()¡± function is used to output the corresponding information of all collection
    // Such as:    C++   zhengli
    //         Thames     2010/1/1
    //         DuZhe      2011/5/1  Issue 10
    // Note that different types of publications will output different types of information.
};
void Library::add(Publication &p){
    publications[total]=&p;
    total+=1;

}

class Book : public Publication
{
    char *auth;

public:
    void show();
    Book(const char *s, const char *a) : Publication(s)
    {
        auth = new char[strlen(a) + 1];
        strcpy(auth, a);
    }
};
class Newspaper : public Publication
{
    Time t;

public:
    void show();
    Newspaper(const char *s, int y, int m, int d) : Publication(s)
    {
        t.y = y;
        t.m = m;
        t.d = d;
    }
};
class Magazine : public Publication
{
    Time t;
    int id;

public:
    void show();
    Magazine(const char *s, int y, int m, int d, int id) : Publication(s), id(id)
    {
        t.y = y;
        t.m = m;
        t.d = d;
    }
};
int Library::total = 0;
void Book::show()
{
    cout << name << "   " << auth << endl;
}
void Newspaper::show()
{
    cout << name << "   ";
    t.show();
    cout << endl;
}
void Magazine::show()
{
    cout << name << "   ";
    t.show();
    cout<<"    "<<id<<endl;
}
int main()
{
    Library cpp;
    Book buk1("hello cpp","jbx");
    Newspaper nws1("cpp news",2022,1,1);
    Magazine mag1("cpp learners",2022,4,20,123);
    cpp.add(buk1);
    cpp.add(nws1);
    cpp.add(mag1);
    cpp.show();
    return 0;
}