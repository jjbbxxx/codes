#include<bits/stdc++.h>
#include"point.h"
using namespace std;
istream & operator >>(istream &in,Point &p){
    in>>p.x>>p.y;
    return in;
}
ostream & operator <<(ostream &out,const Point &p){
    out<<"["<<p.x<<","<<p.y<<"]";
    return out;
}
int Point::operator !=(int x){
    if(this->x+this->y!=x)
    return 1;
    else 
    return 0;
}
int Point::operator ==(const Point a){
    if(this->x==a.x&&this->y==a.y)
    return 1;
    else return 0;
}