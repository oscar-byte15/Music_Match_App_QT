#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <vector>
#include <time.h>
#include <functional>
#include <QTextStream>
#include <QListWidget>


using namespace std;

template <typename T>
class Node{
  public:
  T data;
  Node* left;
  Node* right;
  Node(T data, Node* left = nullptr, Node* right = nullptr): data(data), left(left), right(right){}
};

template <typename OBJ,typename KEY = OBJ>
class BST{
  public:
  Node<OBJ>* root;
  function<KEY(OBJ)> key;

  BST(function<KEY(OBJ)> key = [](OBJ obj){return obj;},Node<OBJ>* root = nullptr):key(key),root(root){}

  void add(OBJ val){add(this->root, val);}
  void add(Node<OBJ>*& node, OBJ val){
    Node<OBJ>* new_node = new Node<OBJ>(val);
    if(node == nullptr){
      node = new_node;
      return;
    }
    if(key(val) <= key(node->data)){
      add(node->left, val);
    }else{ //VAL > NODE->DATA
      add(node->right, val);
    }
  }


  OBJ find(KEY attr) {

        auto node = find(root, attr);
        //return node == nullptr? nullptr: node->data;

            return node->data;

    }

  Node<OBJ>*& find(Node<OBJ>*& node, KEY attr) {
         if (node == nullptr) {

             return node=nullptr;
         } else if (attr == key(node->data)) {
             return node;
         } else if (attr < key(node->data)) {
             return find(node->left, attr);
         } else {
             return find(node->right, attr);
         }
         // return find((attr < key(node->elem)? node->left: node->right, attr);
     }
  void find2(Node<OBJ>*& node, KEY attr, vector<QString> &vect) {
          if (node == nullptr) {
              return;
          }
          if (attr == key(node->data)) {
              vect.push_back(node->data.toString());
          }
          find2(node->left, attr, vect);
          find2(node->right, attr, vect);
      }

   vector<QString> findAll(KEY attr) {
          Node<OBJ>*& node = root;
          vector<QString> vect;
          if (node == nullptr) {
              return vect;
          }
          if (attr == key(node->data)) {
              vect.push_back(node->data.toString());
          }
          find2(node->left, attr, vect);
          find2(node->right, attr, vect);
          return vect;
      }
  int cantidad() {
      Node<OBJ>raiz=nullptr;
          return _cantidad(raiz);
      }
  int _cantidad(Node<OBJ>* nodo) {
          //La cantidad de nodos del �rbol es:
          //	0 si es vac�o
          //	1 + la cantidad de nodos por la izquierda + la cantidad de nodos por la derecha

          if (nodo == nullptr)
              return 0;
          else
          {
              int ci, cd;
              ci = _cantidad(nodo->izq);
              cd = _cantidad(nodo->der);
              return 1 + ci + cd;
          }

      }

  void del(OBJ val){del(this->root, val);}
  void del(Node<OBJ>*& node, OBJ val){
    //CASO BASE
    if(node == nullptr) return;

    if(key(val) < key(node->data)){
      del(node->left, val);
    } else if(key(val) > key(node->data)){
      del(node->right, val);
    }else{
      if(node->left == nullptr){//NO TEIENE HIJO IZQUIERDO
        node = node->right;
      } else if(node->right == nullptr){//NO TIENE HIJO DERECHO
        node = node->left;
      }else{
        //TODO: MIN_NODE
        Node<OBJ>* temp = min_node(node->right);
        node->data = temp->data;
        del(node->right, temp->data);
      }
    }
  }

  void inorder(QListWidget* lista){ inorder(lista, this->root);}
  void inorder(QListWidget* lista, Node<OBJ>* node){
    //CASO BASE
    if(node == nullptr) return;


    inorder(lista,node->left);
    if(lista->count()<50){
    lista->addItem(node->data.toString());
    }
    inorder(lista,node->right);


  }

  void postorder(QListWidget* lista){ postorder(lista, this->root);}
  void postorder(QListWidget* lista, Node<OBJ>* node){
    //CASO BASE
    if(node == nullptr) return;
    postorder(lista,node->right);
     if(lista->count()<50){
    lista->addItem(node->data.toString());
     }
    postorder(lista,node->left);
  }
  // %%% %%%
  //Lambda [](Juego j){return j.toString();}
  void inorder_l(function<void(OBJ)> imprimir) { inorder_l(imprimir, this->root);}
  void inorder_l(function<void(OBJ)> imprimir, Node<OBJ>* node){
    if(node == nullptr) return;
    inorder_l(imprimir,node->left);
    imprimir(node->data);
    inorder_l(imprimir,node->right);
  }

  Node<OBJ>* min_node(Node<OBJ>* node){
    if(node->left == nullptr) return node;
    while(node && node->left != nullptr){
      node = node->left;
    }
    return node;
  }


};



#endif // AVL_H
