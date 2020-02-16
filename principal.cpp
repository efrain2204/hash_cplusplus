#include "principal.h"
#include "ui_principal.h"

principal::principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principal)
{
    p->inicializar(30);
    ui->setupUi(this);

}

principal::~principal()
{
    delete ui;
}

void principal::on_cargartxt_clicked()
{
    if(ui->editTxt->text()!=""){
        scene->clear();
        string name=ui->editTxt->text().toStdString();
        p->cargar(name);
        p->display();

        QPixmap pixmap("out.png");
        scene->addPixmap(pixmap);
        ui->dibuja->setScene(scene);
        ui->dibuja->show();
    }
    cout<<"Tamano: "<<p->numReg<<endl;
    cout<<"Tamano: "<<p->maxSize()<<endl;
}
