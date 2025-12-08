#include "employes.h"
#include "email.h"
#include "ui_employes.h"
#include<QMessageBox>
#include<QDebug>
Employes::Employes(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Employes)
{
    ui->setupUi(this);
    tabEmploye = new QSqlQueryModel();


    ui->tabEmploye->setModel(tabEmploye);
    ui->grp_login->show();
    ui->Employe->hide();
    ui->grp_ajoutEmpl->hide();
    ui->grp_ModifierEmpl->hide();
    ui->menu->hide();
    e.afficher(tabEmploye);


    QRegularExpression rx("^[A-Za-z]+$");
    QValidator *validator2 = new QRegularExpressionValidator(rx, this);

    QRegularExpression rx2("^[0-9]+$");
    QValidator *validator1 = new QRegularExpressionValidator(rx2, this);

    ui->prenomEmploye->setValidator(validator2);
    ui->nomEmploye->setValidator(validator2);
    ui->idEmploye->setValidator(validator1) ;

}

Employes::~Employes()
{
    delete ui;
    delete tabEmploye ;
}


void Employes::on_ajoutEmpl_clicked()
{
    //ui->Employe->hide();
    //ui->grp_ajoutEmpl->show();
    //ui->grp_ModifierEmpl->hide();
    e.setId(ui->idEmploye->text());
    e.setNom(ui->nomEmploye->text());
    e.setPrenom(ui->prenomEmploye->text());
    e.setEmail(ui->emailEmploye->text());
    e.setPoste(ui->posteEmploye->currentText());
    e.setMdp(ui->mdpEmploye->text());
    if(!e.getId().isEmpty() || !e.getNom().isEmpty() || !e.getPrenom().isEmpty() || !e.getEmail().isEmpty()|| !e.getMdp().isEmpty())
    {
        QRegularExpression rxEmail(R"(^[A-Za-z0-9._%+\-]+@[A-Za-z0-9.\-]+\.[A-Za-z]{2,}$)");
        QValidator *emailValidator = new QRegularExpressionValidator(rxEmail, this);
        if(matchesValidator(emailValidator , e.getEmail()))
        {
            if(e.ajouter())
            {
                e.afficher(tabEmploye);

                ui->idEmploye->setText("");
                ui->prenomEmploye->setText("");
                ui->nomEmploye->setText("");
                ui->emailEmploye->setText("");
                ui->mdpEmploye->setText("");
                ui->posteEmploye->setCurrentText("");

                ui->Employe->show();
                ui->grp_ajoutEmpl->hide();
                ui->grp_ModifierEmpl->hide();
                QMessageBox::critical(nullptr, QObject::tr("ajout succes"),
                                    QObject::tr("ajout succes.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("ajout Faild"),
                                    QObject::tr("employe existe deja.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajout Faild"),
                                QObject::tr("Email Incorrect.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ajout failed"),
                            QObject::tr("veiller remplir tous les champs.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Employes::on_modifierEmpl_clicked()
{
   // ui->Employe->hide();
    //ui->grp_ajoutEmpl->hide();
    //ui->grp_ModifierEmpl->show();
    e.setId(ui->idEmploye->text());
    e.setNom(ui->nomEmploye->text());
    e.setPrenom(ui->prenomEmploye->text());
    e.setEmail(ui->emailEmploye->text());
    e.setPoste(ui->posteEmploye->currentText());
    e.setMdp(ui->mdpEmploye->text());
    if(!e.getId().isEmpty() || !e.getNom().isEmpty() || !e.getPrenom().isEmpty() || !e.getEmail().isEmpty()|| !e.getMdp().isEmpty())
    {
        QRegularExpression rxEmail(R"(^[A-Za-z0-9._%+\-]+@[A-Za-z0-9.\-]+\.[A-Za-z]{2,}$)");
        QValidator *emailValidator = new QRegularExpressionValidator(rxEmail, this);
        if(matchesValidator(emailValidator , e.getEmail()))
        {
            if(e.modiifer())
            {
                e.afficher(tabEmploye);


                ui->idEmploye->setText("");
                ui->nomEmpl_ajout->setText("");
                ui->prenomEmploye->setText("");
                ui->emailEmploye->setText("");
                ui->posteEmploye->setCurrentText("");
                ui->mdpEmploye->setText("");
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("modifier Faild"),
                                    QObject::tr("employe n'existe pas.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("modif Faild"),
                                QObject::tr("Email Incorrect.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modif Faild"),
                            QObject::tr("veiller remplir tous les champs.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Employes::on_retour_AjoutEmpl_clicked()
{
    ui->Employe->show();
    ui->grp_ajoutEmpl->hide();
    ui->grp_ModifierEmpl->hide();

}

void Employes::on_retoure_modifierEmpl_clicked()
{
    ui->Employe->show();
    ui->grp_ajoutEmpl->hide();
    ui->grp_ModifierEmpl->hide();
}
bool Employes::matchesValidator(QValidator *v, const QString &s) {
    int pos = 0;            // position du curseur (ignorée ici)
    QString copy = s;       // validate() peut modifier la chaîne
    return v->validate(copy, pos) == QValidator::Acceptable;
}

void Employes::on_confirmer_AjoutEmpl_clicked()
{
    e.setId(ui->idEmpl_ajout->text());
    e.setNom(ui->nomEmpl_ajout->text());
    e.setPrenom(ui->prenomEmpl_ajput->text());
    e.setEmail(ui->EmailEmpl_ajout->text());
    e.setPoste(ui->posteEmpl_ajout->currentText());
    e.setMdp(ui->mdpEmpl_ajout->text());
    if(!e.getId().isEmpty() || !e.getNom().isEmpty() || !e.getPrenom().isEmpty() || !e.getEmail().isEmpty()|| !e.getMdp().isEmpty())
    {
        QRegularExpression rxEmail(R"(^[A-Za-z0-9._%+\-]+@[A-Za-z0-9.\-]+\.[A-Za-z]{2,}$)");
        QValidator *emailValidator = new QRegularExpressionValidator(rxEmail, this);
        if(matchesValidator(emailValidator , e.getEmail()))
        {
            if(e.ajouter())
            {
                e.afficher(tabEmploye);

                ui->Employe->show();
                ui->grp_ajoutEmpl->hide();
                ui->grp_ModifierEmpl->hide();


                ui->idEmploye->setText("");
                ui->prenomEmploye->setText("");
                ui->nomEmploye->setText("");
                ui->emailEmploye->setText("");
                ui->mdpEmploye->setText("");

            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Ajout Faild"),
                                    QObject::tr("Employe existe deja.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajout Faild"),
                                QObject::tr("Email Incorrect.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajout Faild"),
                            QObject::tr("veiller remplir tous les champs.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void Employes::on_tabEmploye_clicked(const QModelIndex &index)
{
    ui->idEmploye->setText(tabEmploye->index(index.row() , 0).data().toString());
    ui->nomEmploye->setText(tabEmploye->index(index.row() , 1).data().toString()) ;
    ui->prenomEmploye->setText(tabEmploye->index(index.row() , 2).data().toString()) ;
    ui->mdpEmploye->setText(tabEmploye->index(index.row() , 3).data().toString()) ;
    ui->posteEmploye->setCurrentText(tabEmploye->index(index.row() , 4).data().toString()) ;
    ui->emailEmploye->setText(tabEmploye->index(index.row() , 5).data().toString()) ;

}



void Employes::on_supprimerEmploye_clicked()
{
    e.setId(ui->idEmploye->text());
    if(e.supprimer())
    {
        e.afficher(tabEmploye);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("supprimer Faild"),
                            QObject::tr("employe n'existe pas.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}





void Employes::on_trieEmpl_currentIndexChanged(const QString &arg1)
{
    e.trie(tabEmploye , arg1) ;
}

void Employes::on_rechercheEmpl_textChanged(const QString &arg1)
{
    e.recherche(tabEmploye ,ui->trieEmpl->currentText() , arg1 );
}

void Employes::on_PDFempl_clicked()
{
    QString content;

    // Insérer le logo avec styles CSS pour la taille et la position

    // Titre du document
    content += "<h1>Liste des Employer</h1>";

    // Début du tableau avec styles CSS
    content += "<style>"
               "table { border-collapse: collapse; width: 100%; }"
               "th, td { border: 1px solid black; padding: 8px; text-align: center; }"
               "th { background-color: lightgray; }" // Couleur de fond pour les en-têtes de colonne
               "</style>";
    content += "<table>";

    // Ajouter les en-têtes de colonne
    content += "<tr>";
    for (int col = 0; col < tabEmploye->columnCount(); ++col) {
        content += "<th>" + tabEmploye->headerData(col, Qt::Horizontal).toString() + "</th>";
    }
    content += "</tr>";

    // Ajouter les données du tableau
    for (int row = 0; row < tabEmploye->rowCount(); ++row) {
        content += "<tr>";
        for (int col = 0; col < tabEmploye->columnCount(); ++col) {
            content += "<td>" + tabEmploye->data(tabEmploye->index(row, col)).toString() + "</td>";
        }
        content += "</tr>";
    }

    // Fin du tableau
    content += "</table>";

    // Créer un objet QTextDocument et définir son contenu en utilisant le code HTML
    QTextDocument document;
    document.setHtml(content);

    // Créer un dialogue pour sélectionner l'emplacement de sauvegarde du PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "Employe", "Fichiers PDF (*.pdf)");

    if (!fileName.isEmpty())
    {
        // Créer un objet QPrinter pour générer le PDF
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);

        // Imprimer le document sur le PDF
        document.print(&printer);

        // Afficher un message à l'utilisateur pour confirmer l'exportation réussie
        QMessageBox::information(this, "Export PDF", "Le PDF a été créé avec succès.");
    }
}

void Employes::on_btn_statEmpl_clicked()
{
    QList<QWidget*> childWidgets = ui->lab_statEmpl->findChildren<QWidget*>();
        for (QWidget* childWidget : childWidgets) {
            childWidget->deleteLater();
        }
        //the clear didnt work, but my goal is when i second click this button it deleted old chart and renders a new one
        ui->lab_statEmpl->clear();
        ui->lab_statEmpl->hide();

    employe e;
    float s0, s1, s2;
    s0 = e.countPoste("Agent");
    s1 = e.countPoste("Admin");
    s2 = e.countPoste("RH");
    float stat = s0 + s1 + s2  ;
    float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
    float y = (stat != 0) ? (s1 * 100) / stat : 0.0;
    float z = (stat != 0) ? (s2 * 100) / stat : 0.0;

    QString ch1 = QString("Agent %1%").arg(x);
    QString ch2 = QString("Admin %1%").arg(y);
    QString ch3 = QString("RH %1%").arg(z);

    QPieSeries *series=new QPieSeries();
    series->setHoleSize(0.35);



    QPieSlice *slice= series->append(ch1,x);
    slice->setLabelVisible();
    slice->setLabelColor(QColor(Qt::red));
    slice->setBrush(QColor(189, 76, 224, 1));
    QPieSlice *slice1= series->append(ch2,y);
    slice1->setLabelVisible();
    slice1->setLabelColor(QColor(Qt::red));
    slice1->setBrush(QColor(84, 16, 149, 1));
    QPieSlice *slice2= series->append(ch3,z);
    slice2->setLabelVisible();

    slice2->setLabelColor(QColor(Qt::red));
        slice2->setBrush(QColor(Qt::green));


        QChart *chart=new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QBrush backgroundBrush(QColor(187,93,87,0));
        chart->setBackgroundBrush(backgroundBrush);
        QChartView *chartview=new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setFixedSize(ui->lab_statEmpl->size());
        chartview->setParent(ui->lab_statEmpl);
        ui->lab_statEmpl->setStyleSheet("background:transparent; color:white; ");
        ui->lab_statEmpl->show();
}

void Employes::on_btn_connexion_clicked()
{
    e.setMdp(ui->lineEdit_motdepasse->text());
    e.setEmail(ui->lineEdit_adresse->text());
    if(e.login())
    {
        ui->grp_login->hide();
        ui->Employe->show();
        ui->grp_ajoutEmpl->hide();
        ui->grp_ModifierEmpl->hide();
        ui->menu->show();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("login faild"),
                            QObject::tr("mot de passe ou email incorrecte.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Employes::on_btn_motdepasse_oublie_clicked()
{

    QString bdy = R"(
<html>
  <body style="font-family: Arial, sans-serif; background-color: #f9f9f9; padding: 20px;">
    <div style="max-width: 600px; margin: auto; background: #ffffff; border-radius: 8px; box-shadow: 0 2px 6px rgba(0,0,0,0.1); padding: 20px;">
      <h2 style="color: #2a9df4; text-align: center;">🔒 Réinitialisation de votre mot de passe</h2>
      <p>Bonjour,</p>
      <p>Vous avez demandé à récupérer votre mot de passe. Voici vos informations de connexion :</p>
      <div style="background-color: #f2f2f2; border-left: 4px solid #2a9df4; padding: 10px; margin: 15px 0;">
        <strong>Mot de passe :</strong> <span style="color: #333;">%1</span>
      </div>
      <p>Pour des raisons de sécurité, pensez à changer votre mot de passe après connexion.</p>
      <p style="font-size: 12px; color: #777;">Ceci est un message automatique, merci de ne pas y répondre.</p>
    </div>
  </body>
</html>
)";


    e.setEmail(ui->lineEdit_adresse->text());
    if(e.getPassword())
    {
        mailer m;
        if(m.sendEmail(e.getEmail(),"mot de passe oublié",bdy.arg(e.getMdp()))!=-1)
        {
            QMessageBox::critical(nullptr, QObject::tr("email envoyé"),
                                  QObject::tr("password a été envoyé à votre email\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("failed envoie email "),
                                  QObject::tr("problem\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("email non trouvé"),
                              QObject::tr("email n'existe pas\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

