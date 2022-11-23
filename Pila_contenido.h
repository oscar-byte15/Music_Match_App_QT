#ifndef PILA_CONTENIDO_H
#define PILA_CONTENIDO_H

#include<iostream>
#include<QDebug>

using namespace std;
template <typename T>
struct Nodo_Persona {
   Nodo_Persona(T);
 T contenido;
    Nodo_Persona* siguiente;

};
template<typename T_var>
Nodo_Persona<T_var>::Nodo_Persona(T_var contenido) {
    this->contenido=contenido;
    siguiente = nullptr;
}
template <typename T>
class Pila_contenido {

    long long tamanho;

public:
    Pila_contenido() : _top(nullptr), tamanho(0) {}
    Nodo_Persona<T>*   _top;
    ~Pila_contenido();

    int     size()  { return tamanho; }
    bool    empty() { return tamanho == 0; }

    void    push(T contenido);
    void    push_node(Nodo_Persona<T>* Node);
    void    pop();
    Nodo_Persona<T>* get_user_inpos(int);
    Nodo_Persona<T>* gettop(){
        return _top;
    }
};

template<typename T_var>
Pila_contenido<T_var>::~Pila_contenido(){
    while (_top != nullptr) {
        Nodo_Persona<T_var>* aux = _top;
        _top = _top->siguiente;
        delete aux;
    }
}

template<typename T_var>
void Pila_contenido<T_var>::pop()
{
    if (tamanho > 0) {
        Nodo_Persona<T_var>* aux = _top;
        _top = _top->siguiente;
        delete aux;
        --tamanho;
    }
}

template<typename T_var>
void Pila_contenido<T_var>::push(T_var contenido)
{
   Nodo_Persona<T_var>* aux = _top;

    _top = new Nodo_Persona<QString>(contenido);

    _top->siguiente = aux;

    ++tamanho;
}

template<typename T_var>
void Pila_contenido<T_var>::push_node(Nodo_Persona<T_var>* Node){
    push(Node->contenido);
}

template<typename T_var>
Nodo_Persona<T_var>* Pila_contenido<T_var>::get_user_inpos(int pos){
   Nodo_Persona<T_var>* Node = _top;
    for (int i=0; i < pos-1; i++){
        Node = Node->siguiente;
    }
    return Node;
}


#endif // PILA_CONTENIDO_H
