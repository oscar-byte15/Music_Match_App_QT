#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <QTextStream>
class Comentario{

long long id;
long long idPub;
QString date;
QString text;

public:
Comentario(long long id, long long idPub,QString date, QString text):
    id(id),
    idPub(idPub),
    date(date),
    text(text){}
long long GetId(){return this->id;}
long long GetIdPub(){return this->idPub;}
QString GetDate(){return this->date;}
QString GetText(){return this->text;}
QString fill_space(QString fill, int n = 15){
    int sep = n-fill.size();
    if(sep % 2 != 0)
        return QString((sep/2),' ') + fill + QString((sep/2)+1,' ');
    return QString((sep/2),' ') + fill + QString((sep/2),' ');
}
QString toString(){

    QString id=id.number(this->id);
    QString idPub=idPub.number(this->idPub);
   return fill_space(id,6)+" | "+fill_space(idPub,6)+" | "+fill_space(this->date,6)+" | "+fill_space(this->text,6);
}

};

#endif // COMENTARIO_H
