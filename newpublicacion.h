#ifndef NEWPUBLICACION_H
#define NEWPUBLICACION_H

#include <QDialog>
#include<Avl.h>
#include<publicacion.h>
#include<Pila_contenido.h>
namespace Ui {
class newPublicacion;
}

class newPublicacion : public QDialog
{
    Q_OBJECT

public:
    int ord=0;
      QListWidget* lista;
    BST<publicacion, QString>* BST_fecha;
    BST<publicacion, long long>* BST_like;
    BST<publicacion, QString>* BST_desc;
    Pila_contenido<QString>*titulo_first;

    explicit newPublicacion(QWidget *parent = nullptr);
    ~newPublicacion();
private slots:
    void AgregarJuego();
    void Cancelar();
    void EstadoOriginal();
    void agregar(publicacion j);
    void on_ok_accepted();

    void on_ok_rejected();

private:
    Ui::newPublicacion *ui;

};

#endif // NEWPUBLICACION_H
