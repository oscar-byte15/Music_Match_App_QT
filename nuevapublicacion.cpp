#include "nuevapublicacion.h"
#include "ui_nuevapublicacion.h"
#include<QDateTime>
nuevaPublicacion::nuevaPublicacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nuevaPublicacion)
{




    connect(ui->aceptar,SIGNAL(released()),this,SLOT(AgregarJuego()));
    connect(ui->cancelar,SIGNAL(released()),this,SLOT(Cancelar()));

    ui->setupUi(this);
}

nuevaPublicacion::~nuevaPublicacion()
{
    delete ui;
}

void nuevaPublicacion::AgregarJuego()
{
    if(ui->p_titulo->text()!="" && ui->p_desc->text()!="")
    {
    QString fecha=QDate::currentDate().toString();
    long long id=0;
    long long id_u=1+rand()%(1000000-1);
    long long likes=1+rand()%(90-1);
    QString titulo= ui->p_titulo->text();
    QString descrip=ui->p_desc->text();
        //  publicacion(long long id,long long id_u, QString titulo,QString contenido, QString pub_date,long long likes):
        agregar(publicacion(id++,id_u,titulo,descrip,fecha,likes));

    }

}

void nuevaPublicacion::Cancelar()
{
    EstadoOriginal();
    this->hide();


}

void nuevaPublicacion::EstadoOriginal()
{
    ui->p_titulo->setText("");
    ui->p_desc->setText("");
}

void nuevaPublicacion::agregar(publicacion j)
{
    this->BST_fecha->add(j);
    this->BST_like->add(j);
    this->BST_desc->add(j);

}
