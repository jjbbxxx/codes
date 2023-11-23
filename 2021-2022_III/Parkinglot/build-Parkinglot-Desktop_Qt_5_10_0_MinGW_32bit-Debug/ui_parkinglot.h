/********************************************************************************
** Form generated from reading UI file 'parkinglot.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARKINGLOT_H
#define UI_PARKINGLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Parkinglot
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLCDNumber *place;
    QLineEdit *lineEdit;
    QPushButton *init_2;
    QLCDNumber *money;
    QLineEdit *lineEdit_2;
    QPushButton *init_3;
    QLCDNumber *price;
    QLineEdit *incarnumber;
    QPushButton *in;
    QLineEdit *outcarnumber;
    QPushButton *out;
    QLineEdit *outcartime;
    QLineEdit *incarplace;
    QLCDNumber *carnum;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLCDNumber *placeleft;
    QLabel *label_5;
    QLabel *label_6;
    QLCDNumber *charge;
    QTextBrowser *textBrowser;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QFrame *line;
    QPushButton *log;
    QPushButton *park;
    QLabel *label_13;
    QFrame *line_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Parkinglot)
    {
        if (Parkinglot->objectName().isEmpty())
            Parkinglot->setObjectName(QStringLiteral("Parkinglot"));
        Parkinglot->setEnabled(true);
        Parkinglot->resize(897, 809);
        centralWidget = new QWidget(Parkinglot);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(440, 120, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(16);
        label->setFont(font);
        place = new QLCDNumber(centralWidget);
        place->setObjectName(QStringLiteral("place"));
        place->setGeometry(QRect(550, 120, 91, 31));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(190, 110, 151, 51));
        init_2 = new QPushButton(centralWidget);
        init_2->setObjectName(QStringLiteral("init_2"));
        init_2->setEnabled(false);
        init_2->setGeometry(QRect(350, 120, 71, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(7);
        init_2->setFont(font1);
        money = new QLCDNumber(centralWidget);
        money->setObjectName(QStringLiteral("money"));
        money->setGeometry(QRect(800, 30, 81, 31));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 20, 151, 51));
        init_3 = new QPushButton(centralWidget);
        init_3->setObjectName(QStringLiteral("init_3"));
        init_3->setGeometry(QRect(350, 30, 71, 31));
        init_3->setFont(font1);
        price = new QLCDNumber(centralWidget);
        price->setObjectName(QStringLiteral("price"));
        price->setGeometry(QRect(550, 30, 91, 31));
        incarnumber = new QLineEdit(centralWidget);
        incarnumber->setObjectName(QStringLiteral("incarnumber"));
        incarnumber->setGeometry(QRect(110, 200, 151, 51));
        in = new QPushButton(centralWidget);
        in->setObjectName(QStringLiteral("in"));
        in->setEnabled(false);
        in->setGeometry(QRect(540, 210, 71, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        in->setFont(font2);
        outcarnumber = new QLineEdit(centralWidget);
        outcarnumber->setObjectName(QStringLiteral("outcarnumber"));
        outcarnumber->setGeometry(QRect(110, 280, 151, 51));
        out = new QPushButton(centralWidget);
        out->setObjectName(QStringLiteral("out"));
        out->setEnabled(false);
        out->setGeometry(QRect(540, 290, 71, 31));
        out->setFont(font2);
        outcartime = new QLineEdit(centralWidget);
        outcartime->setObjectName(QStringLiteral("outcartime"));
        outcartime->setGeometry(QRect(370, 280, 151, 51));
        incarplace = new QLineEdit(centralWidget);
        incarplace->setObjectName(QStringLiteral("incarplace"));
        incarplace->setGeometry(QRect(370, 200, 151, 51));
        carnum = new QLCDNumber(centralWidget);
        carnum->setObjectName(QStringLiteral("carnum"));
        carnum->setGeometry(QRect(800, 210, 81, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(440, 30, 71, 31));
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(670, 30, 91, 31));
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(670, 120, 121, 31));
        label_4->setFont(font);
        placeleft = new QLCDNumber(centralWidget);
        placeleft->setObjectName(QStringLiteral("placeleft"));
        placeleft->setGeometry(QRect(800, 120, 81, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(670, 210, 121, 31));
        label_5->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(670, 290, 121, 31));
        label_6->setFont(font);
        charge = new QLCDNumber(centralWidget);
        charge->setObjectName(QStringLiteral("charge"));
        charge->setGeometry(QRect(800, 290, 81, 31));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 420, 861, 331));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        textBrowser->setFont(font3);
        textBrowser->setAutoFillBackground(false);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 30, 121, 31));
        label_7->setFont(font);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 120, 151, 31));
        label_8->setFont(font);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 210, 81, 31));
        label_9->setFont(font);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 290, 81, 31));
        label_10->setFont(font);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(300, 210, 61, 31));
        label_11->setFont(font);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(300, 290, 61, 31));
        label_12->setFont(font);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setEnabled(true);
        line->setGeometry(QRect(20, 170, 861, 16));
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setWeight(50);
        line->setFont(font4);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        log = new QPushButton(centralWidget);
        log->setObjectName(QStringLiteral("log"));
        log->setEnabled(false);
        log->setGeometry(QRect(150, 380, 111, 31));
        log->setFont(font2);
        park = new QPushButton(centralWidget);
        park->setObjectName(QStringLiteral("park"));
        park->setEnabled(false);
        park->setGeometry(QRect(20, 380, 111, 31));
        park->setFont(font2);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(730, 760, 151, 20));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        font5.setStyleStrategy(QFont::PreferDefault);
        label_13->setFont(font5);
        label_13->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_13->setLayoutDirection(Qt::LeftToRight);
        label_13->setAutoFillBackground(false);
        label_13->setStyleSheet(QStringLiteral("color: rgb(197, 197, 197);"));
        label_13->setTextFormat(Qt::PlainText);
        label_13->setAlignment(Qt::AlignCenter);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setEnabled(true);
        line_2->setGeometry(QRect(20, 350, 861, 16));
        line_2->setFont(font4);
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        Parkinglot->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Parkinglot);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Parkinglot->setStatusBar(statusBar);

        retranslateUi(Parkinglot);

        QMetaObject::connectSlotsByName(Parkinglot);
    } // setupUi

    void retranslateUi(QMainWindow *Parkinglot)
    {
        Parkinglot->setWindowTitle(QApplication::translate("Parkinglot", "Parkinglot", nullptr));
        label->setText(QApplication::translate("Parkinglot", "\346\200\273\350\275\246\344\275\215\357\274\232", nullptr));
        init_2->setText(QApplication::translate("Parkinglot", "\345\210\235\345\247\213\345\214\226\350\275\246\345\234\272", nullptr));
        init_3->setText(QApplication::translate("Parkinglot", "\345\210\235\345\247\213\345\214\226\346\224\266\350\264\271", nullptr));
        in->setText(QApplication::translate("Parkinglot", "\350\277\233\345\205\245", nullptr));
        out->setText(QApplication::translate("Parkinglot", "\351\251\266\345\207\272", nullptr));
        label_2->setText(QApplication::translate("Parkinglot", "\345\215\225\344\273\267\357\274\232", nullptr));
        label_3->setText(QApplication::translate("Parkinglot", "\346\200\273\351\207\221\351\242\235\357\274\232", nullptr));
        label_4->setText(QApplication::translate("Parkinglot", "\345\211\251\344\275\231\350\275\246\344\275\215\357\274\232", nullptr));
        label_5->setText(QApplication::translate("Parkinglot", "\345\267\262\345\201\234\350\275\246\350\276\206\357\274\232", nullptr));
        label_6->setText(QApplication::translate("Parkinglot", "\346\234\254\346\254\241\350\275\246\350\264\271\357\274\232", nullptr));
        label_7->setText(QApplication::translate("Parkinglot", "\350\276\223\345\205\245\345\215\225\344\273\267\357\274\232", nullptr));
        label_8->setText(QApplication::translate("Parkinglot", "\350\276\223\345\205\245\350\275\246\344\275\215\346\225\260\357\274\232", nullptr));
        label_9->setText(QApplication::translate("Parkinglot", "\350\275\246\347\211\214\345\217\267", nullptr));
        label_10->setText(QApplication::translate("Parkinglot", "\350\275\246\347\211\214\345\217\267", nullptr));
        label_11->setText(QApplication::translate("Parkinglot", "\350\275\246\344\275\215", nullptr));
        label_12->setText(QApplication::translate("Parkinglot", "\346\227\266\351\225\277", nullptr));
        log->setText(QApplication::translate("Parkinglot", "\346\230\276\347\244\272\346\224\266\350\264\271\350\256\260\345\275\225", nullptr));
        park->setText(QApplication::translate("Parkinglot", "\346\230\276\347\244\272\350\275\246\345\234\272\346\203\205\345\206\265", nullptr));
        label_13->setText(QApplication::translate("Parkinglot", "\346\254\242\350\277\216\344\275\277\347\224\250\345\201\234\350\275\246\345\234\272by\350\245\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Parkinglot: public Ui_Parkinglot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARKINGLOT_H
