#ifndef MATCHUSERS_H
#define MATCHUSERS_H

#include <QDialog>
#include "Lista_Usuario.h"
#include "Pila_Usuario.h"
#include <QMessageBox>

namespace Ui {
class Matchusers;
}

class Matchusers : public QDialog
{
    Q_OBJECT

public:
    explicit Matchusers(QWidget *parent = nullptr, Lista<QString>* lista = nullptr, Node_Persona<QString>* Node = nullptr);
    ~Matchusers();
    void setuser(Node_Persona<QString>* Node){
        usuario = Node;
    }
    Pila<QString>* get_amigos(){
        return pila_amigos;
    }

private slots:
    void on_Buttonbox_accepted();

    void on_Buttonbox_rejected();

    void on_pushButton_clicked();

private:
    Ui::Matchusers *ui;
    Lista<QString>* lista_usuarios;
    Pila<QString>* pila_amigos;
    Pila<QString>* pila_aux;
    Node_Persona<QString>* usuario;
    enum Columna{
        USUARIO, NOMBRE, CONTRASENA, ID
    };

};

#endif // MATCHUSERS_H
