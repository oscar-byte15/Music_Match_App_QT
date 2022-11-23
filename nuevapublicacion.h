#ifndef NUEVAPUBLICACION_H
#define NUEVAPUBLICACION_H

#include <QMainWindow>
#include<Avl.h>
#include <QDialog>
#include<publicacion.h>

namespace Ui {
class nuevaPublicacion;
}

class nuevaPublicacion : public QMainWindow
{
    Q_OBJECT

public:
    QListWidget* lista;
    BST<publicacion, QString>* BST_fecha;
    BST<publicacion, long long>* BST_like;
    BST<publicacion, QString>* BST_desc;
    explicit nuevaPublicacion(QWidget *parent = nullptr);
    ~nuevaPublicacion();
private slots:
    void AgregarJuego();
    void Cancelar();
    void EstadoOriginal();
    void agregar(publicacion j);
private:
    Ui::nuevaPublicacion *ui;
};

#endif // NUEVAPUBLICACION_H
