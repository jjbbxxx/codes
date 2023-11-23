#include <iostream>
using namespace std;
bool jdg(int c, int time)
{
    switch (c)
    {
    case 1:
        if (time > 23 || time < 0)
            return false;
        break;
    case 2:
        if (time > 59 || time < 0)
            return false;
        break;
    default:
        break;
    }
    return true;
}
class time
{
private:
    int hour, minute, second;

public:
    time(int h, int m, int s);
    time(time &t);
    void set(char c, int time);
    void allset(int h, int m, int s);
    void tick();
    void show();
};
time::time(int h = 0, int m = 0, int s = 0)
{
    if (jdg(1, h))
        hour = h;
    else
        cout << "invalid hour!" << endl;
    if (jdg(2, m))
        minute = m;
    else
        cout << "invalid minute!" << endl;
    if (jdg(2, s))
        second = s;
    else
        cout << "invalid second!" << endl;
}
time::time(time &t)
{
    hour = t.hour;
    minute = t.minute;
    second = t.second;
}
void time::set(char c, int time)
{
    switch (c)
    {
    case 'h':
        if (jdg(1, time))
            hour = time;
        else
            cout << "invalid hour!" << endl;
        break;
    case 'm':
        if (jdg(2, time))
            minute = time;
        else
            cout << "invalid minute!" << endl;
        break;
    case 's':
        if (jdg(2, time))
            second = time;
        else
            cout << "invalid second!" << endl;
        break;
    default:
        cout << "invalid case!" << endl;
    }
}
void time::allset(int h, int m, int s)
{
    if (jdg(1, h))
        hour = h;
    else
        cout << "invalid hour!" << endl;
    if (jdg(2, m))
        minute = m;
    else
        cout << "invalid minute!" << endl;
    if (jdg(2, s))
        second = s;
    else
        cout << "invalid second!" << endl;
}
void time::tick()
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
    }
    if (minute == 60)
    {
        minute = 0;
        hour++;
    }
    if (hour == 24)
        hour = 0;
}
void time::show()
{
    if (hour < 10)
        cout << 0;
    cout << hour << ":";
    if (minute < 10)
        cout << 0;
    cout << minute << ":";
    if (second < 10)
        cout << 0;
    cout << second << endl;
}
int main()
{
    time a(0);
    a.show();
    a.set('m',20);
    a.set('h',10);
    a.show();
    time b(a);
    b.show();
    b.allset(22,53,59);
    b.show();
    b.tick();
    b.show();
    b.allset(39,78,56);
    b.show();

    return 0;
}