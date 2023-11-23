#include <iostream>
using namespace std;
class carlo
{
private:
    int price, weight;

public:
    static int tw;
    static int tp;
    carlo(int p, int w);
    ~carlo();
    friend void print();
} def(0, 0);
carlo ::carlo(int p, int w) : price(p), weight(w)
{
    carlo::tw += w;
    carlo::tp += p;
}
carlo::~carlo()
{
    carlo::tw -= weight;
    carlo::tp -= price;
}
void print()
{
    cout << "total weight: " << carlo::tw << endl;
    cout << "total price: " << carlo::tp << endl;
}
int carlo::tw = 0;
int carlo::tp = 0;
int main()
{

    carlo item_a(1, 5);
    carlo item_b(2, 4);
    print();
    item_b.~carlo();
    print();

    return 0;
}