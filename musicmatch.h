#ifndef MUSICMATCH_H
#define MUSICMATCH_H


#include <QMainWindow>
#include<QMessageBox>
#include "Lista_Usuario.h"
#include "registro.h"
#include "matchusers.h"
#include "login.h"

QT_BEGIN_NAMESPACE
namespace Ui { class musicmatch; }
QT_END_NAMESPACE

class musicmatch : public QMainWindow
{
    Q_OBJECT

public:
    musicmatch(QWidget *parent = nullptr);
    ~musicmatch();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::musicmatch *ui;
    Lista<QString>* usuarios;
    Node_Persona<QString>* usuario;

};
#endif // MUSICMATCH_H
