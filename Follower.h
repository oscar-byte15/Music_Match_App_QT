#ifndef FOLLOWER_H
#define FOLLOWER_H

#include <QTextStream>
class Follower{

    long long id;
    long long id_u;
    long long id_f;

public:
    Follower(long long id,long long id_u, long long id_f):
        id(id),
        id_u(id_u),
        id_f(id_f){}

    long long getId(){return this->id;}
    long long getID_U(){return this->id_u;}
    long long getId_F(){return this->id_f;}



    QString fill_space(QString fill, int n = 15){
        int sep = n-fill.size();
        if(sep % 2 != 0)
            return QString((sep/2),' ') + fill + QString((sep/2)+1,' ');
        return QString((sep/2),' ') + fill + QString((sep/2),' ');
    }

    QString toString(){

        QString id=id.number(this->id);
        QString id_u=id_u.number(this->id_u);
        QString id_f=id_f.number(this->id_f);
        return fill_space(id,6)+" | "+ fill_space(id_u,6)+" | "+ fill_space(id_f,6);
     }



};











#endif // FOLLOWER_H
