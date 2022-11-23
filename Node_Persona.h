#ifndef NODE_PERSONA_H
#define NODE_PERSONA_H
#include <QString>

template<class T_variable>
struct Node_Persona {
    Node_Persona(T_variable, T_variable, T_variable, T_variable, long long);
    T_variable usuario;
    T_variable nombre;
    T_variable contra;
    T_variable cancion;
    long long id;

    Node_Persona* siguiente;

    void setcancion(T_variable new_cancion){ cancion = new_cancion;}
};

template<typename T_var>
Node_Persona<T_var>::Node_Persona(T_var user, T_var nombre, T_var contra, T_var cancion, long long tamanho) {
    this->usuario = user;
    this->nombre = nombre;
    this->contra = contra;
    this->cancion = cancion;
    this->id = tamanho;
    siguiente = nullptr;
}

#endif // NODE_PERSONA_H
