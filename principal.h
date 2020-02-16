#ifndef PRINCIPAL_H
#define PRINCIPAL_H


#include <QMainWindow>
#include"hashh.h"

#include<QPixmap>
#include<QGraphicsScene>

namespace Ui {
class principal;
}

class principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit principal(QWidget *parent = 0);
    ~principal();

private slots:
    void on_cargartxt_clicked();

private:
    Hash *p=new Hash();

    QGraphicsScene *scene =  new QGraphicsScene;
    /*
    vector<string> v1 = h.get();*/
    Ui::principal *ui;
};

#endif // PRINCIPAL_H
