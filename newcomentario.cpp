#include "newcomentario.h"
#include "ui_newcomentario.h"
#include<QDateTime>
newComentario::newComentario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newComentario)
{
    ui->setupUi(this);
}

newComentario::~newComentario()
{
    delete ui;
}

void newComentario::agregar(Comentario c)
{
    BST_id_pub->add(c);
}

void newComentario::on_ok_accepted()
{
    if(ui->txt_comment->text()!="")
    {
        //Comentario(long long id, long long idPub,QString date, QString text)
        QString date= QDate::currentDate().toString();


        agregar(Comentario(id_pub,id_pub,date,ui->txt_comment->text()));
        lista_coment->clear();
        BST_id_pub->postorder(lista_coment);
        /*
 //implementar cuando el find te retorne hasta los repetidos
    QString info= BST_id_pub->find(id_pub).toString();

  if(id_pub==BST_id_pub->find(id_pub).GetIdPub()){

       lista_coment->addItem(info);
      }
  */



        this->hide();
    }


}

void newComentario::on_ok_rejected()
{
    reject();
}
