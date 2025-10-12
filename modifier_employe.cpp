#include "modifier_employe.h"
#include "ui_modifier_employe.h"
#include "employe.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

modifier_employe::modifier_employe(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::modifier_employe)
{
    ui->setupUi(this);
    
    // Configuration des validateurs
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionValidator *emailValidator = new QRegularExpressionValidator(emailRegex, this);
    ui->lineEdit_email->setValidator(emailValidator);
    
    QRegularExpression phoneRegex("^[0-9]{2,3}[ ]?[0-9]{3}[ ]?[0-9]{3}$");
    QRegularExpressionValidator *phoneValidator = new QRegularExpressionValidator(phoneRegex, this);
    ui->lineEdit_telephone->setValidator(phoneValidator);
    
    QRegularExpression idRegex("^[0-9]+$");
    QRegularExpressionValidator *idValidator = new QRegularExpressionValidator(idRegex, this);
    ui->lineEdit_id->setValidator(idValidator);
    
    // Configuration de la date par défaut
    ui->dateEdit_naissance->setDate(QDate::currentDate().addYears(-25));
    
    // Connexion des signaux
    connect(ui->pushButton_confirmer, &QPushButton::clicked, this, &modifier_employe::on_pushButton_confirmer_clicked);
    connect(ui->pushButton_annuler, &QPushButton::clicked, this, &modifier_employe::on_pushButton_annuler_clicked);
    connect(ui->BretourModifierEmploye, &QPushButton::clicked, this, &modifier_employe::on_BretourModifierEmploye_clicked);
}

modifier_employe::~modifier_employe()
{
    delete ui;
}

void modifier_employe::chargerEmploye(const QString &idEmploye)
{
    idEmployeActuel = idEmploye;
    chargerDonneesEmploye();
}

void modifier_employe::on_pushButton_confirmer_clicked()
{
    if (validerFormulaire()) {
        if (modifierEmploye()) {
            QMessageBox::information(this, "Succès", "Employé modifié avec succès !");
            this->close();
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la modification de l'employé.");
        }
    }
}

void modifier_employe::on_pushButton_annuler_clicked()
{
    this->close();
}

void modifier_employe::on_BretourModifierEmploye_clicked()
{
    // Retourner à la page employé
    employe *employePage = qobject_cast<employe*>(parent());
    if (employePage) {
        employePage->show();
    }
    this->close();
}

bool modifier_employe::validerFormulaire()
{
    // Vérification de l'ID
    if (ui->lineEdit_id->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir l'ID de l'employé.");
        ui->lineEdit_id->setFocus();
        return false;
    }
    
    // Vérification du nom
    if (ui->lineEdit_nom->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir le nom de l'employé.");
        ui->lineEdit_nom->setFocus();
        return false;
    }
    
    // Vérification du prénom
    if (ui->lineEdit_prenom->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir le prénom de l'employé.");
        ui->lineEdit_prenom->setFocus();
        return false;
    }
    
    // Vérification de l'email
    if (ui->lineEdit_email->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir l'email de l'employé.");
        ui->lineEdit_email->setFocus();
        return false;
    }
    
    if (!ui->lineEdit_email->hasAcceptableInput()) {
        QMessageBox::warning(this, "Attention", "Format d'email invalide.");
        ui->lineEdit_email->setFocus();
        return false;
    }
    
    // Vérification du téléphone
    if (ui->lineEdit_telephone->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir le numéro de téléphone.");
        ui->lineEdit_telephone->setFocus();
        return false;
    }
    
    if (!ui->lineEdit_telephone->hasAcceptableInput()) {
        QMessageBox::warning(this, "Attention", "Format de téléphone invalide (ex: 58 588 255).");
        ui->lineEdit_telephone->setFocus();
        return false;
    }
    
    // Vérification du poste
    if (ui->lineEdit_poste->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir le poste de l'employé.");
        ui->lineEdit_poste->setFocus();
        return false;
    }
    
    // Vérification du mot de passe
    if (ui->lineEdit_motdepasse->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir le mot de passe.");
        ui->lineEdit_motdepasse->setFocus();
        return false;
    }
    
    if (ui->lineEdit_motdepasse->text().length() < 6) {
        QMessageBox::warning(this, "Attention", "Le mot de passe doit contenir au moins 6 caractères.");
        ui->lineEdit_motdepasse->setFocus();
        return false;
    }
    
    // Vérification de l'unicité de l'email (en excluant l'employé actuel)
    if (!verifierEmailUnique(ui->lineEdit_email->text(), idEmployeActuel)) {
        QMessageBox::warning(this, "Attention", "Cet email est déjà utilisé par un autre employé.");
        ui->lineEdit_email->setFocus();
        return false;
    }
    
    return true;
}

bool modifier_employe::modifierEmploye()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données échouée.");
        return false;
    }
    
    QSqlQuery query;
    query.prepare("UPDATE employes SET id=?, nom=?, prenom=?, email=?, telephone=?, poste=?, date_naissance=?, mot_de_passe=? WHERE id=?");
    
    query.addBindValue(ui->lineEdit_id->text());
    query.addBindValue(ui->lineEdit_nom->text());
    query.addBindValue(ui->lineEdit_prenom->text());
    query.addBindValue(ui->lineEdit_email->text());
    query.addBindValue(ui->lineEdit_telephone->text());
    query.addBindValue(ui->lineEdit_poste->text());
    query.addBindValue(ui->dateEdit_naissance->date());
    query.addBindValue(ui->lineEdit_motdepasse->text());
    query.addBindValue(idEmployeActuel); // ID original pour la condition WHERE
    
    if (query.exec()) {
        return true;
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification : " + query.lastError().text());
        return false;
    }
}

bool modifier_employe::verifierEmailUnique(const QString &email, const QString &idExclu)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        return false;
    }
    
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM employes WHERE email = ? AND id != ?");
    query.addBindValue(email);
    query.addBindValue(idExclu);
    
    if (query.exec() && query.next()) {
        return query.value(0).toInt() == 0;
    }
    
    return false;
}

void modifier_employe::chargerDonneesEmploye()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données échouée.");
        return;
    }
    
    QSqlQuery query;
    query.prepare("SELECT id, nom, prenom, email, telephone, poste, date_naissance, mot_de_passe FROM employes WHERE id = ?");
    query.addBindValue(idEmployeActuel);
    
    if (query.exec() && query.next()) {
        ui->lineEdit_id->setText(query.value(0).toString());
        ui->lineEdit_nom->setText(query.value(1).toString());
        ui->lineEdit_prenom->setText(query.value(2).toString());
        ui->lineEdit_email->setText(query.value(3).toString());
        ui->lineEdit_telephone->setText(query.value(4).toString());
        ui->lineEdit_poste->setText(query.value(5).toString());
        ui->dateEdit_naissance->setDate(query.value(6).toDate());
        ui->lineEdit_motdepasse->setText(query.value(7).toString());
    } else {
        QMessageBox::critical(this, "Erreur", "Employé non trouvé ou erreur lors du chargement des données.");
    }
}
