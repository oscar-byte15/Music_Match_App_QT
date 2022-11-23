#ifndef PILA_USUARIO_H
#define PILA_USUARIO_H

#include<iostream>
#include "Node_Persona.h"
#include<QDebug>

using namespace std;
template <typename T>
class Pila {
    long long tamanho;

public:
    Pila() : _top(nullptr), tamanho(0) {}
    Node_Persona<T>*   _top;
    ~Pila();

    int     size()  { return tamanho; }
    bool    empty() { return tamanho == 0; }

    void    push(T usuario,T nombre, T password, T cancion, long long pos);
    void    push_node(Node_Persona<T>* Node);
    void    pop();
    Node_Persona<T>* get_user_inpos(int);
    Node_Persona<T>* gettop(){
        return _top;
    }
};

template<typename T_var>
Pila<T_var>::~Pila(){
    while (_top != nullptr) {
        Node_Persona<T_var>* aux = _top;
        _top = _top->siguiente;
        delete aux;
    }
}

template<typename T_var>
void Pila<T_var>::pop()
{
    if (tamanho > 0) {
        Node_Persona<T_var>* aux = _top;
        _top = _top->siguiente;
        delete aux;
        --tamanho;
    }
}

template<typename T_var>
void Pila<T_var>::push(T_var usuario,T_var nombre, T_var password, T_var cancion, long long pos)
{
    Node_Persona<T_var>* aux = _top;

    _top = new Node_Persona<QString>(usuario, nombre, password, cancion, pos);

    _top->siguiente = aux;

    ++tamanho;
}

template<typename T_var>
void Pila<T_var>::push_node(Node_Persona<T_var>* Node){
    push(Node->usuario, Node->nombre,Node->contra, Node->cancion, Node->id);
}

template<typename T_var>
Node_Persona<T_var>* Pila<T_var>::get_user_inpos(int pos){
    Node_Persona<T_var>* Node = _top;
    for (int i=0; i < pos-1; i++){
        Node = Node->siguiente;
    }
    return Node;
}


#endif // PILA_USUARIO_H
