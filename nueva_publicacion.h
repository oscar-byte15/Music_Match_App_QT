#ifndef NUEVA_PUBLICACION_H
#define NUEVA_PUBLICACION_H
#include <QMainWindow>
#include <Avl.h>
#include <publicacion.h>

namespace Ui {
class NuevoJuego;
}

class NuevoJuego : public QMainWindow
{
    Q_OBJECT
public:
    int ord = 0; //0 nombre, 1 plat, 2 genero
    QListWidget* lista;
    BST<publicacion, QString>* BST_nombre;
    BST<publicacion, QString>* BST_plataforma;
    BST<publicacion, QString>* BST_genero;
    explicit NuevoJuego(QWidget *parent = nullptr);
    ~NuevoJuego();
private:
    Ui::NuevoJuego *ui;
private slots:
    void AgregarJuego();
    void Cancelar();
    void EstadoOriginal();
    void agregar(publicacion j);
};

#endif // NUEVA_PUBLICACION_H
