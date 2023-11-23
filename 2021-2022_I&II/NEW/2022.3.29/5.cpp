#include <bits/stdc++.h>
using namespace std;
class project
{
private:
    char *projname;
    int id;
    int stuid[3];
    int sum;

public:
    friend class student;
    project(int i, const char *s);
    void show();
};
class student
{
private:
    int id;
    int projid;

public:
    friend class project;
    void choose(project &p);
    void exit(project &p);
    student(int i);
    void show();
};

void student::choose(project &p)
{
    if (p.sum == 3)
    {
        cout << "project " << p.id << " full!!" << endl;
    }
    else
    {
        projid = p.id;
        p.stuid[p.sum] = id;
        p.sum++;
        cout << "student " << id << " succeed!" << endl;
    }
}
void student::exit(project &p)
{
    int check = 0;
    int i;
    for (i = 0; i < 3; i++)
    {
        if (p.stuid[i] == id)
        {
            check = 1;
            break;
        }
    }
    if (!check)
        cout << "wrong project!" << endl;
    else
    {

        if (i == 2)
            p.stuid[i] = -1;
        else
        {

            for (; i < 2; i++)
            {
                p.stuid[i] = p.stuid[i + 1];
            }
            p.stuid[i] = -1;
            p.sum--;
            projid=-1;
        }
    }
}
void student::show()
{
    cout << "student No." << id;
    if(projid==-1)cout<<" project: none."<<endl;
    else cout<<" project No."<<projid<<endl;
}
project::project(int p, const char *s)
{
    id = p;
    projname = new char(strlen(s) + 1);
    strcpy(projname, s);
    for (int i = 0; i < 3; i++)
    {
        stuid[i] = -1;
    }
    sum = 0;
}
student::student(int i)
{
    id = i;
    projid=-1;
}
void project::show()
{
    cout << projname << " " << sum << " sutdents in total:";
    for (int i = 0; i < sum; i++)
    {
        cout << stuid[i] << " ";
    }
    cout << endl;
}
int main()
{
    student kinopio(1);
    student kinopiko(2);
    student mario(3);
    student luigi(4);
    project a(1, "dagong");
    project b(2, "hetang");
    kinopio.choose(a);
    kinopiko.choose(a);
    mario.choose(a);
    luigi.choose(a);
    luigi.choose(b);
    a.show();
    b.show();
    kinopiko.exit(b);
    kinopiko.exit(a);
    a.show();
    kinopiko.show();

    return 0;
}