#include "newpublicacion.h"
#include "ui_newpublicacion.h"
#include<QDateTime>

newPublicacion::newPublicacion(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::newPublicacion)
{




    ui->setupUi(this);

    //connect(ui->ok,SIGNAL(released()),this,SLOT(AgregarJuego()));
    //connect(ui->cancelar,SIGNAL(released()),this,SLOT(Cancelar()));
}

newPublicacion::~newPublicacion()
{
    delete ui;
}
void newPublicacion::AgregarJuego()
{

   //Cancelar();
}
void newPublicacion::EstadoOriginal()
{
    ui->p_titulo->setText("");
    ui->p_desc->setText("");
}

void newPublicacion::Cancelar()
{
reject();
//EstadoOriginal();
//this->hide();

}




void newPublicacion::agregar(publicacion j)
{
    this->BST_fecha->add(j);
    this->BST_like->add(j);
    this->BST_desc->add(j);

}

void newPublicacion::on_ok_accepted()
{
    if(ui->p_titulo->text()!="" || ui->p_desc->text()!="")
    {
    QString fecha=QDate::currentDate().toString();
    long long id=1234;
    long long id_u=1+rand()%(10000-1);
    long long likes=21;
    QString titulo= ui->p_titulo->text();
    QString descrip=ui->p_desc->text();
        //  publicacion(long long id,long long id_u, QString titulo,QString contenido, QString pub_date,long long likes):
        agregar(publicacion(id,id_u,titulo,descrip,fecha,likes));
        //falta agregar a mi pila titulo_pub
        titulo_first->push(titulo);
        lista->clear();


        switch(ord){
        case 0:BST_desc->inorder(lista);break;
        case 1: BST_fecha->inorder(lista);break;
        case 2: BST_like->inorder(lista);break;
        }

        ui->p_titulo->setText("");
        ui->p_desc->setText("");
        this->hide();
    }
}

void newPublicacion::on_ok_rejected()
{
    reject();
}
