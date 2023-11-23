
#include <iostream>
#pragma once
using namespace std;

class Point{
    private:
    int x,y;
    public:
    friend istream & operator >>(istream &in,Point &p);
    friend ostream & operator <<(ostream &out,const Point &p);
    int operator ==(const Point a);
    int operator !=(int x);
};
typedef char Mydata;