#ifndef LISTA_USUARIO_H
#define LISTA_USUARIO_H

#include <iostream>
#include<QString>
#include "Node_Persona.h"

using namespace std;

template<class T_varLista>
class Lista_user {
private:
    Node_Persona<T_varLista>* primero;
    Node_Persona<T_varLista>* ultimo;
    int tamanho;

public:
    Lista_user();
    void push_front(T_varLista,T_varLista, T_varLista, T_varLista, long long);
    void push_back(T_varLista,T_varLista, T_varLista, T_varLista,long long);
    void push_back_node( Node_Persona<T_varLista>* Node);
    void pop_back();
    void pop_front();

   //QString showbysong(QString can);
     Node_Persona<T_varLista>* getfirstuser() {
        return primero;
    }
     Node_Persona<T_varLista>* getuser_inpos(int n) {
         Node_Persona<T_varLista>* Node_Persona = primero;
        for (int i = 0; i < n-1; i++) {
            Node_Persona = Node_Persona->siguiente;
        }
        return Node_Persona;
    }
     Node_Persona<T_varLista>* getlastuser() {
        return ultimo;
    }
    int get_tamanho() {
        return tamanho;
    }
};

template<typename T_var>
Lista_user<T_var>::Lista_user() {
    this->primero = this->ultimo = nullptr;
    this->tamanho = 0;
}

//Agregar elemento al principio
template<typename T_var>
//T_var user, T_var nombre, T_var contra, T_var cancion, long long tamanho
void Lista_user<T_var>::push_front(T_var user, T_var nombre, T_var contra, T_var cancion, long long tamanho) {
    //Creamos el nuevo Node_Persona
    Node_Persona<T_var>* nuevo = new Node_Persona<T_var>(user, nombre, contra, cancion, tamanho);

    //Si no hay elementos indicamos que el primero y ultimo son el mismo. SINO, el nuevo Node_Persona apunta al primero y el primero se vuelve el nuevo Node_Persona.
    if (this->tamanho == 0) {
        primero =  ultimo = nuevo;
    }
    else {
        nuevo->siguiente = primero;
        primero = nuevo;
    }
    nuevo->id = tamanho;
    //aumentamos el tamanho de nuestra lista
    this->tamanho++;
}


//Agregar elemento al final
template<typename T_var>
void Lista_user<T_var>::push_back(T_var user, T_var nombre, T_var contra, T_var cancion, long long tamanho) {
    //Creamos el nuevo Node_Persona
    Node_Persona<T_var>* nuevo = new  Node_Persona<T_var>(user, nombre, contra, cancion, tamanho);

    //   Si no hay elementos indicamos que el primero y ultimo son el mismo. SINO, el ultimo elemento actual de la lista
    //	    													apunta al nuevo Node_Persona y el ultimo se vuelve el nuevo Node_Persona.
    if (this->tamanho > 0) {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
        this->tamanho++;
    }
    else {
        push_front(user, nombre, contra, cancion, tamanho);
    }
}

template <typename T_var>
void Lista_user<T_var>::push_back_node(Node_Persona<T_var>* Node){
    push_back(Node->id,Node->email,Node->name,Node->joindate);
}

//Eliminar elemento al principio
template<typename T_var>
void Lista_user<T_var>::pop_front() {
    if (tamanho == 1) {
        delete primero;
        primero = ultimo = nullptr;
    }
    else {
        Node_Persona<T_var>* Eliminado = primero;
        primero = Eliminado->siguiente;
        Eliminado->siguiente = nullptr;
        delete Eliminado;
    }
    this->tamanho--;
}

//Eliminar elemento al final
template<typename T_var>
void Lista_user<T_var>::pop_back() {
    if (tamanho > 1) {
        Node_Persona<T_var>* eliminado = ultimo;
         Node_Persona<T_var>* puntero = primero;
        while (puntero->siguiente != eliminado) {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nullptr;
        ultimo = puntero;
        delete eliminado;
       this->tamanho--;
    }
    else push_front();
}















template<class T_varLista>
class Lista {
private:
    Node_Persona<T_varLista>* primero;
    Node_Persona<T_varLista>* ultimo;
    int tamanho;

public:
    Lista();
    void push_front(T_varLista,T_varLista, T_varLista, T_varLista, long long);
    void push_back(T_varLista,T_varLista, T_varLista, T_varLista, long long);
    void push_back_node(Node_Persona<T_varLista>* Node);
    void pop_back();
    void pop_front();

   QString showbysong(QString can);

    Node_Persona<T_varLista>* getfirstuser() {
        return primero;
    }
    Node_Persona<T_varLista>* getuser_inpos(int n) {
        Node_Persona<T_varLista>* Node_Persona = primero;
        for (int i = 0; i < n-1; i++) {
            Node_Persona = Node_Persona->siguiente;
        }
        return Node_Persona;
    }
    Node_Persona<T_varLista>* getlastuser() {
        return ultimo;
    }
    int get_tamanho() {
        return tamanho;
    }
};

template<typename T_var>
Lista<T_var>::Lista() {
    this->primero = this->ultimo = nullptr;
    this->tamanho = 0;
}

//Agregar elemento al principio
template<typename T_var>
void Lista<T_var>::push_front(T_var usuario, T_var nombre, T_var password, T_var cancion, long long tamanho) {
    //Creamos el nuevo Node_Persona
    Node_Persona<T_var>* nuevo = new Node_Persona<T_var>(usuario, nombre, password, cancion, tamanho);

    //Si no hay elementos indicamos que el primero y ultimo son el mismo. SINO, el nuevo Node_Persona apunta al primero y el primero se vuelve el nuevo Node_Persona.
    if (this->tamanho == 0) {
        primero =  ultimo = nuevo;
    }
    else {
        nuevo->siguiente = primero;
        primero = nuevo;
    }
    nuevo->id = tamanho;
    //aumentamos el tamanho de nuestra lista
    this->tamanho++;
}


//Agregar elemento al final
template<typename T_var>
void Lista<T_var>::push_back(T_var user, T_var nombre, T_var password, T_var cancion, long long tamanho) {
    //Creamos el nuevo Node_Persona
    Node_Persona<T_var>* nuevo = new Node_Persona<T_var>(user, nombre, password, cancion, tamanho);

    //   Si no hay elementos indicamos que el primero y ultimo son el mismo. SINO, el ultimo elemento actual de la lista
    //	    													apunta al nuevo Node_Persona y el ultimo se vuelve el nuevo Node_Persona.
    if (this->tamanho > 0) {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
        this->tamanho++;
    }
    else {
        push_front(user, nombre, password, cancion, tamanho);
    }
}

template <typename T_var>
void Lista<T_var>::push_back_node(Node_Persona<T_var>* Node){
    push_back(Node->usuario, Node->nombre, Node->contra, Node->cancion, Node->id);
}

//Eliminar elemento al principio
template<typename T_var>
void Lista<T_var>::pop_front() {
    if (tamanho == 1) {
        delete primero;
        primero = ultimo = nullptr;
    }
    else {
        Node_Persona<T_var>* Eliminado = primero;
        primero = Eliminado->siguiente;
        Eliminado->siguiente = nullptr;
        delete Eliminado;
    }
    this->tamanho--;
}

//Eliminar elemento al final
template<typename T_var>
void Lista<T_var>::pop_back() {
    if (tamanho > 1) {
        Node_Persona<T_var>* eliminado = ultimo;
        Node_Persona<T_var>* puntero = primero;
        while (puntero->siguiente != eliminado) {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nullptr;
        ultimo = puntero;
        delete eliminado;
       this->tamanho--;
    }
    else push_front();
}


#endif // LISTA_USUARIO_H
