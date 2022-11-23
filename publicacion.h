#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <QTextStream>
#include<Pila_contenido.h>
#include<iostream>
class publicacion{
        long long id;
        long long id_u;
    QString titulo;
    QString contenido;
        QString pub_date;
    long long likes;





public:
   publicacion(long long id,long long id_u, QString titulo,QString contenido, QString pub_date,long long likes):
       id(id),
       id_u(id_u),
       titulo(titulo),
       contenido(contenido),
       pub_date(pub_date),
       likes(likes){}

    QString Gettitulo(){
        return this->titulo;
    }
    QString GetFirstWord(){
        QString c=this->contenido;
        c=c[0];
        return c;
    }
    QString GetContenido(){
        return this->contenido;
    }
    long long GetLikes(){
        return this->likes;
    }
    QString GetPub_Date(){
        return this->pub_date;
    }

    long long GetId(){
        return this->id;
    }
    long long GetIdUusario(){
        return this->id_u;
    }
    void setTitulo(QString titulo){this->titulo=titulo;}
    void setContenido(QString contenido){this->contenido=contenido;}
    void setLikes(long long likes){this->likes=likes;}
    void setIndex(long long id){this->id=id;}
    void setIndexUusuario(long long id_u){this->id_u=id_u;}

    QString fill_space(QString fill, int n = 15){
        int sep = n-fill.size();
        if(sep % 2 != 0)
            return QString((sep/2),' ') + fill + QString((sep/2)+1,' ');
        return QString((sep/2),' ') + fill + QString((sep/2),' ');
    }

    QString toString(){
        QString likes=likes.number(this->likes);
        QString id=id.number(this->id);
        QString id_u=id_u.number(this->id_u);
       return fill_space(id,6)+" | "+fill_space(id_u,6)+" | "+fill_space(this->titulo,6)+" | "+fill_space(this->contenido,6)+" | "+fill_space(this->pub_date,6)+" | "+fill_space(likes,6);
    }

};
#endif // PUBLICACION_H
