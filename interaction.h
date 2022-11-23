#ifndef INTERACTION_H
#define INTERACTION_H
#include <QTextStream>
class interaction{
        long long id;
        long long id_pub;
    QString date;
    QString compartio;

public:
   interaction(long long id,long long id_pub, QString date,QString compartio):
       id(id),
      id_pub(id_pub),
      date(date),
      compartio(compartio){}


    QString GetDate(){
        return this->date;
    }
  QString GetCompartio(){
  return this->compartio;
  }

    long long GetId(){
        return this->id;
    }
    long long GetIdPublicacion(){
        return this->id_pub;
    }
 void setCompartio(QString v){this->compartio=v;}

    QString fill_space(QString fill, int n = 15){
        int sep = n-fill.size();
        if(sep % 2 != 0)
            return QString((sep/2),' ') + fill + QString((sep/2)+1,' ');
        return QString((sep/2),' ') + fill + QString((sep/2),' ');
    }

    QString toString(){

        QString id=id.number(this->id);
        QString id_pub=id_pub.number(this->id_pub);
       return fill_space(id,6)+" | "+fill_space(id_pub,6)+" | "+fill_space(this->date,6)+" | "+fill_space(this->compartio,6);
    }

};
#endif // INTERACTION_H
