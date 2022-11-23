#ifndef NODO_PERSONA_H
#define NODO_PERSONA_H

#include <QString>

template<class T_variable>
class Nodo_Persona {
public:
    Nodo_Persona(T_variable, T_variable, T_variable, T_variable, long long);
    Nodo_Persona(Nodo_Persona<T_variable>*);

    T_variable usuario;
    T_variable nombre;
    T_variable contra;
    T_variable cancion;
    //Pila<T_variable>* pilaamigos;
    long long id;

    Nodo_Persona* siguiente;

    void setcancion(QString new_cancion){ cancion = new_cancion;}
    //void setamigos( Pila<T_variable>* pila){
    //    this->amigos = pila;
   // }
};


#endif // NODO_PERSONA_H
