#include "amigos.h"
#include "ui_amigos.h"
#include <QFile>

Amigos::Amigos(QWidget *parent, Node_Persona<QString>* userid) :
    QDialog(parent),
    ui(new Ui::Amigos)
{
    ui->setupUi(this);

    amigos = new Pila<QString>();
    QStringList titulos;
    titulos<<"USUARIO"<<"NOMBRE"<<"CANCION"<<"ID";
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(titulos);

    QString nd;
    QString _id;
    long long pos=0;
//hemos pasado nodo userid

    QString user_id = userid->usuario + "_Amigos.txt";
// ABRE LA INFORMACION DE LOS AMIGOS que ya han sido guardados cuando hciste click en el boton guardar datos de amigos
    QFile log(user_id);
    if(log.open(QIODevice::ReadOnly)){
        QTextStream leer(&log);
        while(!log.atEnd()) {
            QString ftitle = log.readLine();
            QString fusuario = log.readLine();
            fusuario = fusuario.remove("USER: ");
            fusuario = fusuario.remove("\r\n");
            fusuario = fusuario.trimmed();
            QString fnombre = log.readLine();
            fnombre = fnombre.remove("NOMBRE: ");
            fnombre = fnombre.remove("\r\n");
            fnombre = fnombre.trimmed();
            QString fapellido = log.readLine();
            fapellido = fapellido.remove("PASSWORD: ");
            fapellido = fapellido.remove("\r\n");
            fapellido = fapellido.trimmed();
            QString fcancion = log.readLine();
            fcancion = fcancion.remove("CANCION: ");
            fcancion = fcancion.remove("\r\n");
            fcancion = fcancion.trimmed();

//agregando informacion de amigos con mismos gustos musicales en una pila
            this->amigos->push(fusuario, fnombre, fapellido, fcancion, pos++);
        }
        log.close();
    }

        for (int j=1; j<= this->amigos->size(); j++){
            //va mostrando la informacion de los amigos ya guardados en la pila.
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,USUARIO,new QTableWidgetItem(this->amigos->get_user_inpos(j)->usuario));
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,NOMBRE,new QTableWidgetItem(this->amigos->get_user_inpos(j)->nombre));
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,CONTRASENA,new QTableWidgetItem(this->amigos->get_user_inpos(j)->cancion));
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,ID,new QTableWidgetItem(_id.number(this->amigos->get_user_inpos(j)->id)));
        }



        connect(ui->seguir,SIGNAL(released()),this,SLOT(beFollowerof()));

        //----------------------------------

          this->seguidos=new BST<Follower,long long>([](Follower f){return f.getId();});

     this->cargarDatos();
        this->Listar_id();
}

Amigos::~Amigos()
{
    delete ui;
}

void Amigos::on_Buttonbox_rejected()
{
    reject();
}


void Amigos::on_Buttonbox_accepted()
{
    accept();

}

void Amigos::beFollowerof()
{
    for(int i=0;i<=this->amigos->size();++i){
        if(this->amigos->get_user_inpos(i)->id==ui->id_seguir->text().toLongLong()){
            QString nombre_seguido=this->amigos->get_user_inpos(i)->nombre;
            ui->listWidget_seguidos->addItem(nombre_seguido);
        }
    }

}

void Amigos::cargarDatos()
{
    QFile file("followers.csv");
    if(file.open(QIODevice::ReadOnly)){ //WriteOnly
        QTextStream in(&file); // in << palabras[1] << "\n";
        while(!in.atEnd()){
            QString linea = in.readLine();
            QStringList palabras = linea.split(",");
            long long id=palabras[1].toLongLong();
            long long id_u=palabras[2].toLongLong();
            long long id_f=palabras[3].toLongLong();

            // publicacion(long long id,long long id_u, QString titulo,QString contenido, QString pub_date,long long likes)
            Agregar_toBst(Follower(id,id_u,id_f));
        }
        file.close();
    }


}

void Amigos::Agregar_toBst(Follower f)
{
    this->seguidos->add(f);
}

void Amigos::Listar_id()
{
    ui->listWidget_seguidos->clear();
    seguidos->inorder(ui->listWidget_seguidos);



}
