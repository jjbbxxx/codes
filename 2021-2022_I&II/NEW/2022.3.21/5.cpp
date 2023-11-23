#include <iostream>
#include <string.h>
using namespace std;
class String
{
public:
    String(const char *str = NULL); // Constructor
    String(const String &other)
    {
        m_data = other.m_data;
    };         // Copy Constructor
    ~String(); // Destructor
    void set(const char *str);
    void show();

private:
    char *m_data; // hold strings
};
String::String(const char *str)
{
    m_data = new char[strlen(str) + 1];
    strcpy(m_data, str);
}; // Constructor

String::~String()
{
    delete[] m_data;
}; // Destructor
void String::set(const char *str)
{
    m_data = new char[strlen(str) + 1];
    strcpy(m_data, str);
};
void String::show()
{
    cout << m_data << endl;
}

int main()
{
    char s[7] = "hahaha";
    char *str = s;
    String a("hello");
    a.show();
    String b(str);
    b.show();
    String c("12345");
    c.set("abcde");
    c.show();
    String d(c);
    d.show();
    return 0;
}
