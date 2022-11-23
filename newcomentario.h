#ifndef NEWCOMENTARIO_H
#define NEWCOMENTARIO_H

#include <QDialog>
#include<Avl.h>
#include<comentario.h>

namespace Ui {
class newComentario;
}

class newComentario : public QDialog
{
    Q_OBJECT

public:
     QListWidget*lista_coment;
    long long id_pub;

    BST<Comentario, long long>*BST_id_pub;

    explicit newComentario(QWidget *parent = nullptr);
    ~newComentario();
private slots:
    void agregar(Comentario c);

    void on_ok_accepted();

    void on_ok_rejected();

private:
    Ui::newComentario *ui;
};

#endif // NEWCOMENTARIO_H
