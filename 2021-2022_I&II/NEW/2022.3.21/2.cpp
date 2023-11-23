#include <iostream>
#include <string.h>
using namespace std;
int f(char *x)
{
    if (strlen(x) != 6)
        return 0;
    for (int i = 0; i < 6; i++)
    {
        if ('0' >= *(x + i) || *(x + i) >= '9')
            return 0;
    }
    return 1;
}
class user
{
private:
    int id;

    char *nm;

public:
    char *pw;
    user(int no, char *string) : id(no)
    {
        pw = "000000";
        nm = new char[strlen(string) + 1];
        strcpy(nm, string);
    };
    ~ user();
    void print();
    void nmchg();
    void pwchg();
    void showpwd();
};
user:: ~user(){
    delete []nm;
}

void user::print()
{
    cout << "ID: " << id << " Name: " << nm << endl;
};
void user::nmchg()
{
    char string[100];
    cout << "input a new name for user " << id << ":";
    gets(string);
    nm = new char[strlen(string) + 1];
    strcpy(nm, string);
}
void user::pwchg()
{
    int x = 0, y = 0;
    while (x == 0)
    {
        char opwd[100];
        cout << "input original password:";
        cin >> opwd;
        if (strcmp(opwd, pw) != 0)
        {
            cout << "original password incorrect!!!" << endl;
        }
        else
        {
            while (y == 0)
            {
                char input[100];
                cout << "input new password:";
                cin >> input;
                char *npwd = input;
                if (f(npwd) == 0)
                {
                    cout << "format incorrect!" << endl;
                }
                else
                {
                    pw = input;
                    x = 1;
                    y = 1;
                }
            }
        }
    }
}
void user::showpwd()
{
    cout << "password: ";
    cout << pw << endl;
}
int main()
{
    user student(10086, "xiaolan");
    student.print();
    student.nmchg();
    student.print();
    student.showpwd();
    student.pwchg();
    student.showpwd();

    return 0;
}