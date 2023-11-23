#include<iostream>
using namespace std;
class counter{
        private:
        int num;
        public:
        counter(){num=0;};
        void add(){num++;};
        void sub(){num--;};
        void print(){cout<<num<<endl;}
    };
int main(){
    counter a;
    a.print();
    a.add();
    a.print();
    a.sub();
    a.print();

    return 0;
}