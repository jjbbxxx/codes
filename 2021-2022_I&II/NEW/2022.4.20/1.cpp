#include <bits/stdc++.h>
using namespace std;
class Vehicle
{
protected:
    char *name;

public:
    virtual void show() = 0;
    Vehicle(const char *s)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }
};
class Car : public Vehicle
{
    char *brand;

public:
    void show()
    {
        cout << name << ',' << brand<<endl;
    }
    Car(const char *s, const char *b) : Vehicle(s)
    {

        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
    }
};
class Truck : public Vehicle
{
    int weight;

public:
    void show()
    {
        cout << name << ',' << weight<<endl;
    }
    Truck(const char* s,int w):Vehicle(s),weight(w){};
};
class Boat : public Vehicle
{
    int depth;

public:
    void show()
    {
        cout << name << ',' << depth<<endl;
    }
    Boat(const char* s,int d):Vehicle(s),depth(d){};
};

int main()
{
    Car c("Lambo","Lamborghini");
    Truck t("trucktruck",3000);
    Boat b("dalian",50);
    c.show();
    t.show();
    b.show();
    return 0;
}