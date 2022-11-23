#include "nueva_publicacion.h"
#include "ui_

NuevoJuego::NuevoJuego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NuevoJuego)
{
    ui->setupUi(this);
    connect(ui->BAceptar,SIGNAL(released()),this,SLOT(AgregarJuego()));
    connect(ui->BCancelar,SIGNAL(released()),this,SLOT(Cancelar()));
}

NuevoJuego::~NuevoJuego()
{
    delete ui;
}

void NuevoJuego::EstadoOriginal(){
  ui->INombre->setText("");
  ui->IPlataforma->setCurrentIndex(0);
  ui->IGenero->setCurrentIndex(0);
}

void NuevoJuego::Cancelar(){
    EstadoOriginal();
    this->hide();
}

void NuevoJuego::AgregarJuego(){
    if(ui->INombre->text() != ""){
        QString nombre = ui->INombre->text();
        QString plataforma = ui->IPlataforma->currentText();
        QString genero = ui->IGenero->currentText();
        agregar(Juego(nombre,plataforma,genero));
        //actualizar lista
        lista->clear();

        //TODO: INVERSO
        switch(ord){
        case 0: BST_nombre->inorder(lista);break;
        case 1: BST_plataforma->inorder(lista);break;
        case 2: BST_genero->inorder(lista);break;
        }
    }
    Cancelar();
}

void NuevoJuego::agregar(Juego j){
    this->BST_nombre->add(j);
    this->BST_genero->add(j);
    this->BST_plataforma->add(j);

}

