#include "ui_registro.h"
#include"registro.h"

Registro::Registro(QWidget *parent, Lista<QString>* list) :
    QDialog(parent),
    ui(new Ui::Registro)
{
    //Nodo
    nuevo_usuario = nullptr;
    //node_user=nullptr;
    ui->setupUi(this);

    //lista
    lista_usuarios = list;
}

Registro::~Registro()
{
    delete ui;
}

void Registro::setdatos(QString renglon){
        QString contAnt;
        QString contAct;
        QFile log("log.txt");
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
            escribir<<renglon;

            log.close();
        }

        //obtener lo utlimo que se ha escrito
        if(log.open(QIODevice::ReadOnly)){
            QTextStream leer(&log);
            contAct.append(leer.readAll());
            log.close();
        }
}


void Registro::on_box_rejected()
{
    this->hide();
}
/*
void Registro::cargar_users()
{
    QFile file("users.txt");
    if(file.open(QIODevice::ReadOnly)){ //WriteOnly
        QTextStream in(&file); // in << palabras[1] << "\n";
        QString linea = in.readLine();
        while(!in.atEnd()){
            linea = in.readLine();
            QStringList palabras = linea.split("\t");
            //long long id=palabras[0].toLongLong();
            QString id=palabras[0];
            QString email=palabras[1];
            QString name=palabras[2];
            QString joindate=palabras[3];

             node_user=new Node_user<QString>(id, email,  name,  joindate);
            // publicacion(long long id,long long id_u, QString titulo,QString contenido, QString pub_date,long long likes)
            //Agregar_Interactions(interaction(id,id_pub,palabras[2],palabras[3]));
        }
        file.close();
    }
}
*/
void Registro::on_box_accepted()
{
    //si el username ya esta usado el bool sera verdadero y no permitira registrar al usuario
    bool usernameused = false;

    for (int i=0;i< lista_usuarios->get_tamanho(); i++){
        if (ui->reg_user->text() == lista_usuarios->getuser_inpos(i)->usuario) usernameused = true;
    }



    if (ui->reg_password->text() != ui->reg_password2->text()){
        QMessageBox::critical(this,"ERROR","Las contraseñas deben coincidir!");  
    } else{

        //r para generar _user_id_
        int r = rand() % 10;

        if (usernameused) {
            QMessageBox::critical(this,"ERROR","Usuario ya registrado");
        }
        else  {
            nuevo_usuario = new Node_Persona<QString>(ui->reg_user->text(), ui->reg_nombre->text(), ui->reg_password->text(), ui->reg_cancion->text(), lista_usuarios->get_tamanho() + r);
            accept();
            QMessageBox::information(this,"REGISTRADO","REGISTRO EXITOSO");

                        //Registramos al usuario en nuestro archivo log.txt con nuestra funcion setdatos


            QString nd;
            nd.append("       REGISTRO      ");nd.append("\r\n");

            nd.append("USER: ");nd.append(ui->reg_user->text());nd.append("\r\n");
            nd.append("NOMBRE: ");nd.append(ui->reg_nombre->text());nd.append("\r\n");
            nd.append("PASSWORD: ");nd.append(ui->reg_password->text());nd.append("\r\n");
            nd.append("CANCION: ");nd.append(ui->reg_cancion->text());nd.append("\r\n");
            setdatos(nd);

        }
    }
}

