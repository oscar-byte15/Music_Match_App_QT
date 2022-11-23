#include "login.h"
#include "ui_login.h"
#include<QFile>
#include<QDateTime>
#include<QMessageBox>
#include <stdlib.h>
login::login(QWidget *parent, Lista<QString>* lista, Node_Persona<QString>* usuario) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->usuario = usuario;
    this->lista_usuarios = lista;
    this->pila_Amigos = new Pila<QString>();
    this->titulo_first=new Pila_contenido<QString>();



    ui->USERNAME->setText(usuario->usuario);
    ui->USERNAME->setVisible(false);
    //----------------------------------
    this->BST_titulo_pub=new BST<publicacion,QString>([](publicacion p){return p.Gettitulo();});
    this->BST_fecha=new BST<publicacion,QString>([](publicacion p){return p.GetPub_Date();});
    this->BST_like=new BST<publicacion,long long>([](publicacion p){return p.GetLikes();});
    this->BST_id=new BST<publicacion,long long>([](publicacion p){return p.GetId();});

    this->BST_idPub=new BST<Comentario,long long>([](Comentario c){return c.GetIdPub();});
    this->BST_compartio=new BST<interaction,long long>([](interaction i){return i.GetIdPublicacion();});
    //this->BST_false_true=new BST<interaction,QString>([](interaction i){return i.GetCompartio();});

    connect(ui->publicar,SIGNAL(released()),this,SLOT(AgregarPub()));
    connect(ui->mas_likes,SIGNAL(released()),this,SLOT(ListarLike()));
     connect(ui->mas_reciente,SIGNAL(released()),this,SLOT(Listar_Fecha()));
      connect(ui->btn_fecha,SIGNAL(released()),this,SLOT(find_fecha()));
      connect(ui->find_comments,SIGNAL(released()),this,SLOT(find_comment()));
      connect(ui->btn_comentar,SIGNAL(released()),this,SLOT(Comentar_pub()));
      connect(ui->btn_compartir,SIGNAL(released()),this,SLOT(compartir()));
      connect(ui->mas_relevantes,SIGNAL(released()),this,SLOT(Listar_masRelevantes()));
       connect(ui->btn_first_word,SIGNAL(released()),this,SLOT(first_w_publicacion()));
          connect(ui->btn_last_word,SIGNAL(released()),this,SLOT(last_w_publication()));
          connect(ui->btn_no_finded,SIGNAL(released()),this,SLOT(word_no_finded()));
          connect(ui->btn_contenido_en,SIGNAL(released()),this,SLOT(contenido_en()));
          connect(ui->btn_igual_a,SIGNAL(released()),this,SLOT(igual_a()));

      this->ventana=new newPublicacion(this);
      this->ventana->BST_desc=this->BST_titulo_pub;
      this->ventana->BST_fecha=this->BST_fecha;
     this->ventana->BST_like=this->BST_like;
      this->ventana->lista=ui->listWidget;
       this->ventana->titulo_first=this->titulo_first;

      //vincluar el arbol de id_pub


      this->comentario= new newComentario(this);
      this->comentario->id_pub=ui->txt_idPub->text().toLongLong();
      this->comentario->lista_coment=ui->listWidget_comments;
     this->comentario->BST_id_pub=this->BST_idPub;

    this->CargarDatos();
      this->CargarComentarios();
      this->Cargar_Interactions();
    //this->ListarLike();
    //this->ListarCont();

      ui->listWidget->clear();
     // BST_desc->inorder(ui->listWidget);
      //this->ventana->ord = 0;

}

login::~login()
{
    delete ui;
}
bool press=false;
long long likes=0;

void login::on_pushButton_clicked()
{
    //conectar con usuarios
    int res;
    Matchusers form(this, lista_usuarios, usuario);
    setWindowTitle("Matched");
    res=form.exec();

    // asignar a la pila de amigos de la clase LOGIN la pila de amigos auxiliar que se acaba de crear en el form MATCHUSERS
    setamigos(form.get_amigos());

    cleardatos();

    QString nd;
    //ya le ha agregado antes a la pila
    for (int i=1; i<=pila_Amigos->size(); i++){
        nd.append("       REGISTRO      ");nd.append("\r\n");
        nd.append("USER: ");nd.append(this->pila_Amigos->get_user_inpos(i)->usuario);nd.append("\r\n");
        nd.append("NOMBRE: ");nd.append(this->pila_Amigos->get_user_inpos(i)->nombre);nd.append("\r\n");
        nd.append("PASSWORD: ");nd.append(this->pila_Amigos->get_user_inpos(i)->contra);nd.append("\r\n");
        nd.append("CANCION: ");nd.append(this->pila_Amigos->get_user_inpos(i)->cancion);nd.append("\r\n");
    }

    setdatos(nd, usuario->usuario);


    if(res==QDialog::Rejected){
        return;
    }
}





void login::on_pushButton_2_clicked()
{
    //lista de amigos
    int res;
    Amigos newform(this, usuario);
    setWindowTitle("friends");
    res=newform.exec();
    //usuario->setamigos(newform.getamigos());
    if(res==QDialog::Rejected){
        return;
    }
}






//EXPLICAME ESTO
void login::setamigos(Pila<QString>* pila){
    bool bandera = true;
        for (int i=1; i<=pila->size(); i++){
            bandera = true;
            for (int j=1; j<=pila_Amigos->size(); j++){
                if (pila->get_user_inpos(i)->id == pila_Amigos->get_user_inpos(j)->id){
                    bandera = false;
                }
            }
            if (bandera) pila_Amigos->push_node(pila->get_user_inpos(i));
        }
}






void login::setdatos(QString amigos, QString usuario){
    QString contAnt;
    QString contAct;

    QString user_id = usuario + "_Amigos.txt";
    QFile log(user_id);

    //primera lectura para obtener datos
    if(log.open(QIODevice::ReadOnly)){
        QTextStream leer(&log);
        contAnt.append(leer.readAll());
        log.close();
    }

    //escribir los datos
    if(log.open(QIODevice::WriteOnly)){
        QTextStream escribir(&log);
        escribir<<contAnt;
        escribir<<amigos;
        log.close();
    }

    //obtener lo utlimo que se ha escrito
    if(log.open(QIODevice::ReadOnly)){
        QTextStream leer(&log);
        contAct.append(leer.readAll());
        log.close();
    }
}

void login::on_pushButton_3_clicked()
{
    this->reject();
}



void login::cleardatos(){
    QString user_id = usuario->usuario + "_Amigos.txt";

    QFile log(user_id);
    if(log.open(QIODevice::WriteOnly)){
    QTextStream escribir(&log);
    escribir<<"";
    log.close();
    }

}



//---------------------------------------------------------


bool login::getPress(){
    return press;
}
long long login::getLikes(){
    return likes;
}



/*

void login::on_publicar_clicked()
{

    QString coment;
    QString titulo;

    QString day,month,year;
    QString hora;
     int hora1;
     hora=QTime::currentTime().toString();
     hora1=QTime::currentTime().hour();


    //fecha=QDate::currentDate().toString();

     day=day.number(QDate::currentDate().day());
     month=month.number(QDate::currentDate().month());
     year=year.number(QDate::currentDate().year());

     //descomponiendo la hora
      coment=ui->comentario->text();

      //tiutlo de publicacion

      titulo=ui->titulo_pub->text();

 // publicacion(long long id,long long id_u, QString titulo,QString contenido, QString pub_date,long long likes)


    ui->listWidget->addItem("Titulo: "+titulo +"\n"+"Fecha: "+day+"/"+month+"/"+year+"\n"+"Hora: "+hora+"\n"+"Contenido: "+coment+"\n");
    //agregarPublicacion(publicacion(titulo,coment,likes,0));


    if(coment.isEmpty()) return;




}

*/

void login::on_eliminar_clicked()
{
    delete ui->listWidget->currentItem();
}
/*
void login::on_like_clicked()

{
QString l=l.number(getLikes());

press=true;

  if(ui->listWidget->currentItem()->isSelected()==press)
  {
      ++likes;
      ui->n_likes->setText(l);

      press=false;
  }
  else

  {


  }

}
*/

void login::CargarDatos()
{
    QFile file("publications.tsv");
    if(file.open(QIODevice::ReadOnly)){ //WriteOnly
        QTextStream in(&file); // in << palabras[1] << "\n";
        QString linea = in.readLine();
        while(!in.atEnd()){
            linea = in.readLine();
            QStringList palabras = linea.split("\t");
            long long id=palabras[0].toLongLong();
            long long id_u=palabras[1].toLongLong();
            long long likes=palabras[5].toLongLong();

            // publicacion(long long id,long long id_u, QString titulo,QString contenido, QString pub_date,long long likes)
            AgregarJuego_toBST(publicacion(id,id_u,palabras[2],palabras[3],palabras[4],likes));
            //conte->push("Full Name");
            this->titulo_first->push(palabras[2]);



        }
        file.close();
    }

}


void login::AgregarPub()
{


    this->ventana->show();
}

void login::Listar_masRelevantes()
{
    //ui->listWidget->clear();
    //BST_desc->inorder(ui->listWidget);
    //this->ventana->ord=0;

    ui->listWidget->clear();

    for(int i=1;i<50;++i){

      if( BST_compartio->find(i).GetCompartio()=="TRUE"){
          //para corroborar quienes son true en "interactios.tsv"
          //QString info=BST_compartio->find(i).toString();
            // ui->listWidget->addItem(info);

          if(i==BST_id->find(i).GetId())
          {

              QString info=BST_id->find(i).toString();
              ui->listWidget->addItem(info);



             }
         }


      }
}

void login::ListarLike()
{


     ui->listWidget->clear();
     BST_like->postorder(ui->listWidget);
     this->ventana->ord=2;

}

void login::Listar_Fecha()
{
    ui->listWidget->clear();
    BST_fecha->postorder(ui->listWidget);
    this->ventana->ord=1;
}

void login::find_fecha()
{
    ui->listWidget->clear();

    vector<QString> info2 = BST_fecha->findAll(ui->txt_fecha->text());

    if(!info2.empty()) {
        for (auto i = info2.begin(); i != info2.end(); ++i) {
            ui->listWidget->addItem(*i);
        }
    }
}

void login::find_comment()
{
    ui->listWidget_comments->clear();

    vector<QString> info2 = BST_idPub->findAll(ui->txt_idPub->text().toLongLong());

    if(!info2.empty()) {
        for (auto i = info2.begin(); i != info2.end(); ++i) {
            ui->listWidget_comments->addItem(*i);
        }
    }

    this->comentario->id_pub=ui->txt_idPub->text().toLongLong();
}

void login::AgregarJuego_toBST(publicacion j)
{
    this->BST_fecha->add(j);
    this->BST_like->add(j);
    this->BST_titulo_pub->add(j);
    this->BST_id->add(j);
}

void login::CargarComentarios()
{
    QFile file("comment.tsv");
    if(file.open(QIODevice::ReadOnly)){ //WriteOnly
        QTextStream in(&file); // in << palabras[1] << "\n";
        QString linea = in.readLine();
        while(!in.atEnd()){
            linea = in.readLine();
            QStringList palabras = linea.split("\t");
            long long id=palabras[0].toLongLong();
            long long id_pub=palabras[1].toLongLong();

            // publicacion(long long id,long long id_u, QString titulo,QString contenido, QString pub_date,long long likes)
            Agregar_Comentarios_toBst(Comentario(id,id_pub,palabras[2],palabras[3]));


        }
        file.close();
    }

}

void login::Agregar_Comentarios_toBst(Comentario c)
{
    this->BST_idPub->add(c);
}

void login::Comentar_pub()
{
    this->comentario->show();
}

void login::Cargar_Interactions()
{

    QFile file("interaction.tsv");
    if(file.open(QIODevice::ReadOnly)){ //WriteOnly
        QTextStream in(&file); // in << palabras[1] << "\n";
        QString linea = in.readLine();
        while(!in.atEnd()){
            linea = in.readLine();
            QStringList palabras = linea.split("\t");
            long long id=palabras[0].toLongLong();
            long long id_pub=palabras[1].toLongLong();

            // publicacion(long long id,long long id_u, QString titulo,QString contenido, QString pub_date,long long likes)
            Agregar_Interactions(interaction(id,id_pub,palabras[2],palabras[3]));
        }
        file.close();
    }

}

void login::Agregar_Interactions(interaction i)
{
    this->BST_compartio->add(i);
}

void login::compartir()
{


    if(ui->txt_id_comp_pub->text()!=""){
    //comparar el id_publicacion del interaction y publicacion, tambien si interaccion.getCompartio()=="TRUE", entonces message box
    long long id_publicacion=BST_id->find(ui->txt_id_comp_pub->text().toLongLong()).GetId();
    long long id_publicacion_interaction=BST_compartio->find(ui->txt_id_comp_pub->text().toLongLong()).GetIdPublicacion();
                      QString false_true= BST_compartio->find(ui->txt_id_comp_pub->text().toLongLong()).GetCompartio();
    if(ui->txt_id_comp_pub->text().toLongLong()==id_publicacion && id_publicacion==id_publicacion_interaction && false_true=="TRUE"){
        QMessageBox::information(this,"COMPARTIDO","esto ya fue compartido");
    }
    else{
        BST_compartio->find(ui->txt_id_comp_pub->text().toLongLong()).setCompartio("TRUE");
        QMessageBox::information(this,"RECIEN COMPARTIDO","primera vez compartido");


    }
}

}

void login::first_w_publicacion()
{

    ui->listWidget->clear();

    //toda la info del comentario gracias al id
   // QString id=BST_desc->find(ui->txt_first_word->text()).toString();


 for(int i=0;i<titulo_first->size();++i){
 QString id_pub=BST_titulo_pub->find(titulo_first->get_user_inpos(i)->contenido).Gettitulo();
 QString info=BST_titulo_pub->find(titulo_first->get_user_inpos(i)->contenido).toString();



   if(ui->txt_first_word->text()==id_pub.at(0)&&ui->txt_first_word->text()!="")
        {
                ui->listWidget->addItem(info);


        }
   }



}

void login::last_w_publication()
{
        ui->listWidget->clear();
        for(int i=0;i<titulo_first->size();++i){
        QString id_pub=BST_titulo_pub->find(titulo_first->get_user_inpos(i)->contenido).Gettitulo();
        QString info=BST_titulo_pub->find(titulo_first->get_user_inpos(i)->contenido).toString();

        //poner id_pub.size()-1 para encontrar por ultima letra

          if(ui->txt_first_word->text()==id_pub.at(id_pub.size()-1) &&ui->txt_first_word->text()!="")
               {
                       ui->listWidget->addItem(info);


               }
        }
}

void login::word_no_finded()
{

       ui->listWidget->clear();

       for(int i=0;i<titulo_first->size();++i)
       {
            string id_pub=BST_titulo_pub->find(titulo_first->get_user_inpos(i)->contenido).Gettitulo().toStdString();
              QString info=BST_titulo_pub->find(titulo_first->get_user_inpos(i)->contenido).toString();
              string word=ui->txt_no_finded->text().toStdString();


              if(id_pub.find(word)==string::npos&& word!=""){
                  ui->listWidget->addItem(info);
              }
       }


}

void login::contenido_en()
{


     ui->listWidget->clear();

     for(int i=0;i<titulo_first->size();++i)
     {
          string id_pub=BST_titulo_pub->find(titulo_first->get_user_inpos(i)->contenido).Gettitulo().toStdString();
            QString info=BST_titulo_pub->find(titulo_first->get_user_inpos(i)->contenido).toString();
            string word=ui->txt_contenido_en->text().toStdString();


            if(id_pub.find(word)!=string::npos && word!=""){
                ui->listWidget->addItem(info);
            }
     }


}

void login::igual_a()
{

    ui->listWidget->clear();


QString info_completa=BST_titulo_pub->find(ui->txt_igual_a->text()).toString();


QString titulo_pub=BST_titulo_pub->find(ui->txt_igual_a->text()).Gettitulo();


 if(ui->txt_igual_a->text()==titulo_pub && ui->txt_igual_a->text()!="")
 {
  ui->listWidget->addItem(info_completa);
 }

}
