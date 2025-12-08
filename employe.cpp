#include "employe.h"
#include<QDebug>
employe::employe()
{

}
void employe:: afficher(QSqlQueryModel *tabEmploye)
{
    tabEmploye->setQuery("Select * from Employe") ;
}
bool employe::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYE (ID_EMPLOYE, NOM, PRENOM, MDP, POSTE, EMAIL) "
                  "VALUES (:id, :nom, :prenom, :mdp, :poste, :email)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mdp", mdp);
    query.bindValue(":poste", poste);
    query.bindValue(":email", email);
    if (query.exec())
        return true;
    else
       return false;
}

bool employe::modiifer()
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE set nom = :nom, prenom = :prenom, mdp = :mdp , poste=:poste,email=:email WHERE ID_EMPLOYE = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mdp", mdp);
    query.bindValue(":poste", poste);
    query.bindValue(":email", email);
    qDebug () << id ;
    if (query.exec())
        return true;
    else
       return false;
}
bool employe:: supprimer()
{
    QSqlQuery query ;
        query.prepare("delete from EMPLOYE where ID_EMPLOYE=:id");
        query.bindValue(":id" , id);
        if(query.exec())
        {
            return true ;
        }
        else
        {
            return  false ;
        }
}
void employe:: trie(QSqlQueryModel *tabEmploye , QString critere)
{
    tabEmploye->setQuery("select * from employe order by " + critere) ;
}
void employe::  recherche(QSqlQueryModel *tabEmploye , QString critere , QString ch)
{
    tabEmploye->setQuery("select * from employe where " + critere + " like '%"+ ch + "%' order by " + critere) ;
}
int employe:: countPoste(QString poste)
{
    QSqlQueryModel *model = new QSqlQueryModel ;
    model->setQuery("select * from employe where poste like '" + poste + "'") ;
    return  model->rowCount();
}
bool employe:: login()
{
    QSqlQuery query ;
        query.prepare("select * from EMPLOYE where mdp=:mdp and email = :email");
        query.bindValue(":mdp" , mdp);
        query.bindValue(":email" , email);
        if(query.exec() && query.next())
        {
            return true ;
        }
        else
        {
            return  false ;
        }
}
bool employe::getPassword()
{
    QSqlQuery query;
    query.prepare("select * from EMPLOYE where email=:email");
    query.bindValue(":email",email);
    if(query.exec() && query.next())
    {
        mdp=query.value(3).toString();
        return true;
    }
    else
    {
        return false;
    }


}
bool employe::existe(QString id)
{
    QSqlQuery query;
    query.prepare("select * from EMPLOYE where ID_EMPLOYE=:id");
    query.bindValue(":id",id);
    if(query.exec() && query.next())
    {
        return true;
    }
    else
    {
        return false;
    }
}
