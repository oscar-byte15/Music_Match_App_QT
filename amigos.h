#ifndef AMIGOS_H
#define AMIGOS_H

#include <QDialog>
#include "login.h"
#include <Avl.h>
#include<Follower.h>
namespace Ui {
class Amigos;
}

class Amigos : public QDialog
{
    Q_OBJECT

public:

           BST<Follower, long long>* seguidos;


    explicit Amigos(QWidget *parent = nullptr, Node_Persona<QString>* user_id = nullptr);
    ~Amigos();

private slots:
    void on_Buttonbox_rejected();

    void on_Buttonbox_accepted();
     void beFollowerof();
     void cargarDatos();
     void Agregar_toBst(Follower f);
     void Listar_id();
private:
    Ui::Amigos *ui;
    Pila<QString>* amigos;
    enum Columna{
        USUARIO, NOMBRE, CONTRASENA, ID
    };

};

#endif // AMIGOS_H
