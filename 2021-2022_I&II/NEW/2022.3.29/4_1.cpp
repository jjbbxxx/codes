#include<bits/stdc++.h>
using namespace std;
class point{
    private:
    float x;
    float y;
    public:
    friend double distance(point &p1,point &p2);
    point(float a=0,float b=0):x(a),y(b){};
    void set(float a,float b);
};
void point::set(float a=0,float b=0){
    x=a;
    y=b;
}
double distance(point &p1,point &p2){
    double d;
    d=sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2));
    return d;
}

int main(){
    point a(2,3);
    point b(3,4);
    cout<<distance(a,b)<<endl;
    return 0;
}