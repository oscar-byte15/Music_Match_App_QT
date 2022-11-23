#ifndef NODO_AVL_H
#define NODO_AVL_H

template<class J>
struct JNodo {
    J elemento;
    JNodo* izq;
    JNodo* der;
    long long altura;
    JNodo() {
        izq = nullptr;
        der = nullptr;
        altura = 0;
    }
};
#endif // NODO_AVL_H
