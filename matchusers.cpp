#include "matchusers.h"
#include "ui_matchusers.h"

Matchusers::Matchusers(QWidget *parent, Lista<QString>* list, Node_Persona<QString>* Node) :
    QDialog(parent),
    ui(new Ui::Matchusers)
{
    ui->setupUi(this);
    lista_usuarios = list;
    usuario = Node;
    pila_amigos = new Pila<QString>();
    pila_aux = new Pila<QString>();


    QStringList titulos;
    titulos<<"USUARIO"<<"NOMBRE"<<"CANCION"<<"ID";
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(titulos);

    QString _id;
    if (lista_usuarios->get_tamanho() > 0){
    for (int i=1; i<=lista_usuarios->get_tamanho(); i++){
        if (usuario->usuario != lista_usuarios->getuser_inpos(i)->usuario){
            if (usuario->cancion == lista_usuarios->getuser_inpos(i)->cancion){
                pila_aux->push_node(lista_usuarios->getuser_inpos(i));
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,USUARIO,new QTableWidgetItem(lista_usuarios->getuser_inpos(i)->usuario));
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,NOMBRE,new QTableWidgetItem(lista_usuarios->getuser_inpos(i)->nombre));
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,CONTRASENA,new QTableWidgetItem(lista_usuarios->getuser_inpos(i)->cancion));
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,ID,new QTableWidgetItem(_id.number(lista_usuarios->getuser_inpos(i)->id)));
            }
        }
    }
    }
}

Matchusers::~Matchusers()
{
    delete ui;
}

void Matchusers::on_Buttonbox_accepted()
{
     if (ui->new_song->text() != "") {
         usuario->setcancion(ui->new_song->text());
     }else {
         QMessageBox::information(this,"NEWSONG","Ingrese cancion");
     }

     for (int i=ui->tableWidget->rowCount(); i >=0; i--){
         ui->tableWidget->removeRow(i);
     }

     QStringList titulos;
     titulos<<"USUARIO"<<"NOMBRE"<<"CANCION"<<"ID";
     ui->tableWidget->setColumnCount(4);
     ui->tableWidget->setHorizontalHeaderLabels(titulos);

     QString _id;
     for (int i=1; i<=lista_usuarios->get_tamanho(); i++){
         if (usuario->usuario != lista_usuarios->getuser_inpos(i)->usuario){
             if (usuario->cancion == lista_usuarios->getuser_inpos(i)->cancion){

                 pila_aux->push_node(lista_usuarios->getuser_inpos(i));

                 ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                 ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,USUARIO,new QTableWidgetItem(lista_usuarios->getuser_inpos(i)->usuario));
                 ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,NOMBRE,new QTableWidgetItem(lista_usuarios->getuser_inpos(i)->nombre));
                 ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,CONTRASENA,new QTableWidgetItem(lista_usuarios->getuser_inpos(i)->cancion));
                 ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,ID,new QTableWidgetItem(_id.number(lista_usuarios->getuser_inpos(i)->id)));
             }
         }
     }
}

void Matchusers::on_Buttonbox_rejected()
{
    reject();
}

void Matchusers::on_pushButton_clicked()
{
    //Añadir a tu pila de amigos
    if (pila_aux->size() > 0){
        for (int i = 1; i <= pila_aux->size(); i++){
            pila_amigos->push_node(pila_aux->get_user_inpos(i));
        }
    }

    if (pila_amigos->size() > 0){
        QMessageBox::information(this,"REGISTRADO","Amigos Guardados");
    } else {
        QMessageBox::warning(this,"ERROR","No se han encontrado usuarios para agregar como amigos  ");
    }
}
