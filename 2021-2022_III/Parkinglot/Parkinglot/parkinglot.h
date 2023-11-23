#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <QMainWindow>
#include <vector>
using namespace std;
namespace Ui {
class Parkinglot;
}


class car{
public:
    int place;
    char* number;
    bool ifreal;


    car();
    car(const char *c);



    int returnplace();



};





class chargesys{
    friend class Parkinglot;
    int charge(int time);
    int money;


public:
    int price;
};

class Log{
    friend class Parkinglot;

    int sum;
    vector <char*>number;
    vector <int>time;
    vector <int>pay;

    Log();
    void addlog(char *c,int t,int p);


};


class Parkinglot : public QMainWindow
{
    Q_OBJECT
public:
    explicit Parkinglot(QWidget *parent = 0);

    void display();

public slots:

    void on_init_2_clicked();

    void on_init_3_clicked();

private slots:
    void on_in_clicked();

    void on_out_clicked();

    void on_log_clicked();

    void on_park_clicked();

private:
    Ui::Parkinglot *ui;
    vector <car>place;
    int capacity;
    int capacityleft;
    int carnum;



    chargesys cgsys;
    Log lg;


    int ifempty(int x);
    int ifin(char *c);


    void in(car a,int p);
    void out(car a,int t);



};











#endif // PARKINGLOT_H
