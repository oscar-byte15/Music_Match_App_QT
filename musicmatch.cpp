#include "musicmatch.h"
#include "ui_musicmatch.h"



musicmatch::musicmatch(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::musicmatch)
{
    ui->setupUi(this);
    this->usuarios = new Lista<QString>();
    //encriptar tu contraseña
    ui->password->setEchoMode(QLineEdit::Password);

    //abre el archivo ya con la informacion de amigos en el archivo log
        //esta parte no entiendo
    QFile log("log.txt");
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

            int r = rand() % 10;
            usuarios->push_front(fusuario, fnombre, fapellido, fcancion, usuarios->get_tamanho() + r);
        }
        log.close();
    }

}

musicmatch::~musicmatch()
{
    delete ui;
}


void musicmatch::on_pushButton_2_clicked()
{
    //register
    int res;
    Registro newregister(this, usuarios);
    setWindowTitle("Registro");
        //abre ventana de registro
    res=newregister.exec();

    if(res==QDialog::Rejected){
        return;
    }
    else {

        usuarios->push_back_node(newregister.getusuario());

    }

}

void musicmatch::on_pushButton_clicked()
{
    //login
    if (usuarios->get_tamanho() > 0){
        for (int i=0; i <= usuarios->get_tamanho(); i++){
            //usuario ya registrado guardado en lista, para iniciar sesion
            if (ui->usuario->text() == usuarios->getuser_inpos(i)->usuario){
                if (ui->password->text() == usuarios->getuser_inpos(i)->contra   ){
                    //Se abre la ventana de Match with friends;
                    usuario = usuarios->getuser_inpos(i);
                    int res;
                    //para que aparezcan los datos ya registrados
                    login newform(this, usuarios, usuario);
                    setWindowTitle("Login");
                    res=newform.exec();
                    if(res==QDialog::Rejected){
                        return;
                    }
                }else {
                    QMessageBox::critical(this,"ERROR","                Contraseña invalida");
                    return;
                }
            }
        }
    } else {
        QMessageBox::critical(this,"ERROR","               No hay usuarios registrados");
        return;
    }
}
