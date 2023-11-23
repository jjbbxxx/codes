#include <bits/stdc++.h>
using namespace std;
class rational
{
private:
    long a,b; // denom is the numerator
    // and den is the denominator
    //???? changed to a and b.
public:
    rational(int num = 0, int denom = 1);
    int operator<(rational r) const;
    int operator<=(rational r) const;
    int operator==(rational r) const;
    int operator!=(rational r) const;
    friend ostream &operator<<(ostream &out,const rational &r);
    // Add output operator << overload here
};
rational::rational(int num, int denom){
    b=num;
    a=denom;
}
int rational::operator<(rational r) const{
    return (b*r.a-a*r.b)<0?1:0;
}
int rational::operator<=(rational r) const{
    return (b*r.a-a*r.b)<=0?1:0;
}
int rational::operator==(rational r) const{
    return (b*r.a-a*r.b)==0?1:0;
}
int rational::operator!=(rational r) const{
    return (b*r.a-a*r.b)!=0?1:0;
}
ostream& operator<<(ostream &out,const rational &r){
    out<<r.b<<'/'<<r.a;
    return out;
}

int main()
{
    rational a(1,2);
    rational b(2,3);
    rational c(4,6);
    cout<<(a<b)<<endl;
    cout<<(c<=b)<<endl;
    cout<<(c==b)<<endl;
    cout<<(a!=b)<<endl;
    cout<<a<<';'<<b<<';'<<c<<endl;
    return 0;
}