#include "nodo_persona.h"


template<typename T_var>
Nodo_Persona<T_var>::Nodo_Persona(T_var user, T_var nombre, T_var contra, T_var cancion, long long tamanho) {
    this->usuario = user;
    this->nombre = nombre;
    this->contra = contra;
    this->cancion = cancion;
    this->id = tamanho;
  //  this->pilaamigos = new Pila<T_var>();
    siguiente = nullptr;
}



template<typename T_var>
Nodo_Persona<T_var>::Nodo_Persona(Nodo_Persona<T_var>* nodo) {
    this->usuario = nodo->usuario;
    this->nombre = nodo->nombre;
    this->contra = nodo->contra;
    this->cancion = nodo->cancion;
    this->id = nodo->id;
  //  this->pilaamigos = new Pila<T_var>();
    siguiente = nullptr;
}
