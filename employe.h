#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQueryModel>

#include<QSqlQuery>
class employe
{
private:
    QString id;
    QString nom;
    QString prenom;
    QString mdp;
    QString poste;
    QString email;
public:
    employe();
    // Getters
    QString getId() const { return id; }
    QString getNom() const { return nom; }
    QString getPrenom() const { return prenom; }
    QString getMdp() const { return mdp; }
    QString getPoste() const { return poste; }
    QString getEmail() const { return email; }

        // Setters
    void setId(const QString &value) { id = value; }
    void setNom(const QString &value) { nom = value; }
    void setPrenom(const QString &value) { prenom = value; }
    void setMdp(const QString &value) { mdp = value; }
    void setPoste(const QString &value) { poste = value; }
    void setEmail(const QString &value) { email = value; }

    void afficher(QSqlQueryModel *tabEmploye);
    bool supprimer();
    bool modiifer();
    bool ajouter();
    void trie(QSqlQueryModel *tabEmploye , QString critere);
    void recherche(QSqlQueryModel *tabEmploye , QString critere , QString ch);
    int countPoste(QString poste) ;
};

#endif // EMPLOYE_H
