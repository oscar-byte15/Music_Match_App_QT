#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "matchusers.h"
#include <Lista_Usuario.h>
#include "amigos.h"
#include <Avl.h>
#include <comentario.h>
#include<Pila_contenido.h>

#include<newpublicacion.h>
#include<newcomentario.h>
#include<interaction.h>
#include<string>
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT
    newComentario*comentario;
    newPublicacion*ventana;
    BST<publicacion, QString>* BST_fecha;
    BST<publicacion, long long>* BST_like;
    BST<publicacion, QString>* BST_titulo_pub;
    BST<publicacion, long long>*BST_id;

    BST<Comentario,long long>*BST_idPub;

    BST<interaction,long long>*BST_compartio;
    //BST<interaction,QString>*BST_false_true;

    //BST<publicacion,long long>*BST_id_usuario;

public:
    explicit login(QWidget *parent = nullptr, Lista<QString>* lista_usuarios = nullptr,
    Node_Persona<QString>* usuario = nullptr);

    ~login();




    void setdatos(QString amigos, QString usuario);
    void cleardatos();
   bool getPress();
   long long getLikes();





private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void setamigos(Pila<QString>* pila);
    void on_pushButton_3_clicked();

   // void on_publicar_clicked();

    void on_eliminar_clicked();

    //void on_like_clicked();


     void CargarDatos();
     void AgregarPub();
     void Listar_masRelevantes();
     void ListarLike();
     void Listar_Fecha();
     void find_fecha();
     void find_comment();
     void AgregarJuego_toBST(publicacion j);
     void CargarComentarios();
     void Agregar_Comentarios_toBst(Comentario c);
     void Comentar_pub();
     void Cargar_Interactions();
     void Agregar_Interactions(interaction i);
     void compartir();
     void first_w_publicacion();
     void last_w_publication();
     void word_no_finded();
     void contenido_en();
     void igual_a();
private:
    Ui::login *ui;
    Lista<QString>* lista_usuarios;
    //como usas la pila si no hay la liberia
    Pila<QString>* pila_Amigos;
      Pila_contenido<QString>*titulo_first;
    Node_Persona<QString>* usuario;

 Pila_contenido<QString>*comentarios_en_1pub;

};

#endif // LOGIN_H
