#include <bits/stdc++.h>
using namespace std;
class person
{
protected:
    char *name;
    int id;

public:
    person(int id = 0, const char *s = "null") : id(id)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }
    ~person()
    {
        delete[] name;
    }
};
class student : virtual public person
{
protected:
    int Class;
    int grade;

public:
    student(int id = 0, const char *s = "null", int Class = 0, int grade = 0) : person(id, s), Class(Class), grade(grade) {}
    ~student() {}
    void display();
};
class teacher : virtual public person
{
protected:
    char *title;
    char *department;

public:
    teacher(int id = 0, const char *s = "null", const char *t = "null", const char *d = "null") : person(id, s)
    {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        department = new char[strlen(d) + 1];
        strcpy(department, d);
    }
    ~teacher() {
        delete []title;
        delete []department;
    }
    void display();
};
class assistant : public student, public teacher
{
protected:
    int aid;
teacher t;
public:
    assistant(int id = 0, int aid = 0, const char *s = "null", int Class = 0, const char *t = "null") : person(id, s), student(id, s, Class, 0), teacher(0, t, "null", "null"), aid(aid)
    {
    }
    ~assistant(){}
    void display();
};
void student::display()
{
    cout << "type:student id:" << id << " name:" << name << " class:" << Class << " grade:" << grade << endl;
}
void teacher::display()
{
    cout << "type:teacher id:" << id << " name:" << name << " title:" << title << " department:" << department << endl;
}
void assistant::display()
{
    cout << "type:assistant student id:" << id << " assistant id:" << aid << " name:" << student::name << " class:" << Class << " teacher:" << teacher::name << endl;
}
int main()
{
    student a(1, "Xixi", 2108, 100);
    a.display();
    teacher b(2, "Xiaowei", "professor", "cpp");
    b.display();
    assistant c(2, 3, "Yifei", 2108, "Xiaowei");
    c.display();
    return 0;
}