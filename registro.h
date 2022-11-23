#ifndef REGISTRO_H
#define REGISTRO_H

#include "Lista_Usuario.h"
#include <QDialog>
#include <QFile>
#include<QTextStream>
#include<QMessageBox>

namespace Ui {
class Registro;
}

class Registro : public QDialog
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr, Lista<QString>* list = nullptr);
    ~Registro();


    Node_Persona<QString>* getusuario(){
        return nuevo_usuario;
    }

    void setdatos(QString renglon);

private slots:

    void on_box_accepted();

    void on_box_rejected();
    void cargar_users();

private:
    Ui::Registro *ui;
    Lista<QString>* lista_usuarios;
    Node_Persona<QString>* nuevo_usuario;

    //Lista_user<QString>*l_user;
    //Node_user<QString>*node_user;
};

#endif // REGISTRO_H
