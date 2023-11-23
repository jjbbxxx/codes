#include "parkinglot.h"
#include "ui_parkinglot.h"
#include <string.h>
#include <QMessageBox>
#include <QDebug>
Parkinglot::Parkinglot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Parkinglot)
{
    ui->setupUi(this);
    capacity=0;
    ui->lineEdit_2->setFocus();
}

car::car(){
    ifreal=0;
    place=-1;
    number=NULL;
}
car::car(const char*c){
    ifreal=1;
    place=-1;
    number=new char[strlen(c)+1];
    strcpy(number,c);
}

int car::returnplace(){
    if(place==-1){
        QMessageBox::warning(NULL,"错误","车未在停车场中");
        return -1;
    }
    else return place;
}






void Parkinglot::on_init_3_clicked()
{



    int x=ui->lineEdit_2->text().toInt();
    if(x<=0){
        QMessageBox::warning(this,"错误","车费有误！");
        ui->lineEdit_2->clear();
        return;
    }
    cgsys.price=x;
    cgsys.money=0;
    ui->price->display(cgsys.price);
    ui->money->display(cgsys.money);
    ui->init_2->setEnabled(true);
    ui->in->setEnabled(true);
    ui->out->setEnabled(true);
    ui->log->setEnabled(true);
    ui->park->setEnabled(true);
    ui->lineEdit_2->clear();
    this->display();
}



void Parkinglot::on_init_2_clicked()
{
    int x=ui->lineEdit->text().toInt();
    if(x<=0){
        QMessageBox::warning(this,"错误","车位数有误！");
        ui->lineEdit->clear();
        return;
    }
    capacity=x;
    capacityleft=x;
    carnum=0;
    place.resize(capacity);
    for(int i=0;i<capacity;i++){
        place[i].ifreal=0;
    }
    ui->place->display(capacity);
    ui->carnum->display(0);
    ui->placeleft->display(capacityleft);
    lg.sum=0;
    lg.number.resize(1);
    lg.time.resize(1);
    lg.pay.resize(1);
    ui->lineEdit->clear();
    this->display();

}


int Parkinglot::ifempty(int x){
    if(x>capacity||x<=0)return -1;
    else if(place[x-1].ifreal==1) return 0;
    else return 1;


}
int Parkinglot::ifin(char *c){
    for(int i=0;i<capacity;i++){
        if(place[i].ifreal==1&&strcmp(place[i].number,c)==0)return 1;
    }
    return 0;

}

void Parkinglot:: in(car a, int p){
    if(ifin(a.number)==1){
        QMessageBox::warning(this,"错误","车已在停车场中！");
        ui->incarnumber->clear();
        ui->incarplace->clear();
        return ;
    }

    if(ifempty(p)==-1){
        QMessageBox::warning(this,"错误","车位号错误！");
        ui->incarplace->clear();
        return;
    }
    else if(ifempty(p)==0){
        QMessageBox::warning(this,"错误","车位已占用！");
        ui->incarplace->clear();
        return;
    }
    else{
        place[p-1]=a;
        a.place=p;
        a.ifreal=1;
        carnum+=1;
        capacityleft-=1;
        ui->carnum->display(this->carnum);
        ui->placeleft->display(this->capacityleft);
        ui->incarnumber->clear();
        ui->incarplace->clear();
    }
}





int chargesys::charge(int time){
    int ch=time*price;
    money+=ch;
    return ch;
}

Log::Log(){
    sum=0;
    number.resize(1);
    time.resize(1);
    pay.resize(1);
}
void Log::addlog(char *c, int t, int p){
    number[sum]=c;
    time[sum]=t;
    pay[sum]=p;
    sum++;
    number.resize(sum+1);
    time.resize(sum+1);
    pay.resize(sum+1);
}


void Parkinglot::on_in_clicked()
{
    char *c;
    QByteArray ba=ui->incarnumber->text().toLatin1();
    c=ba.data();
    int x=ui->incarplace->text().toInt();
    car *a=new car(c);
    this->in(*a,x);
    delete a;
    this->display();
}

void Parkinglot::on_out_clicked()
{
    char *c;
    QByteArray ba=ui->outcarnumber->text().toLatin1();
    c=ba.data();
    int x=ui->outcartime->text().toInt();
    car *a=new car(c);
    this->out(*a,x);
    delete a;
    this->display();
}


void Parkinglot::out(car a,int t){
    if(ifin(a.number)==0){
        QMessageBox::warning(this,"错误","车不在停车场中！");
        ui->outcarnumber->clear();
        ui->outcartime->clear();
        return;
    }
    else if(t<=0){
        QMessageBox::warning(this,"错误","停车时长有误！");
        ui->outcarnumber->clear();
        ui->outcartime->clear();
    }
    else{
        for(int i=0;i<capacity;i++){
            if(place[i].ifreal==1&&strcmp(place[i].number,a.number)==0)
            {
                place[i].ifreal=0;
                break;
            }
        }
        int pay=cgsys.charge(t);
        ui->charge->display(pay);
        carnum-=1;
        capacityleft+=1;
        ui->money->display(cgsys.money);
        ui->carnum->display(this->carnum);
        ui->placeleft->display(this->capacityleft);
        ui->outcarnumber->clear();
        ui->outcartime->clear();
        lg.addlog(a.number,t,pay);
    }

}

void Parkinglot::display(){
    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText("车位情况：");
    ui->textBrowser->append("------------------------");
    for(int i=0;i<capacity;i++)
    {
        if(place[i].ifreal==0)
        {
            QString s1=QString("车位%1 |  empty   ").arg(i+1);
            ui->textBrowser->append(s1);
        }
        if(place[i].ifreal==1)
        {
            QString s2=QString("车位%1 |  车牌号: %2 ").arg(i+1).arg(place[i].number);
            ui->textBrowser->append(s2);
        }
    }
    ui->textBrowser->append("------------------------");
}

void Parkinglot::on_log_clicked()
{
    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText("收费记录：");
    ui->textBrowser->append("------------------------");
    for(int i=0;i<lg.sum;i++)
    {

        QString s1=QString("%1. 车牌号: %2 时长: %3 费用: %4").arg(i+1).arg(lg.number[i]).arg(lg.time[i]).arg(lg.pay[i]);
        ui->textBrowser->append(s1);

    }
    ui->textBrowser->append("------------------------");
}


void Parkinglot::on_park_clicked()
{
    this->display();
}
