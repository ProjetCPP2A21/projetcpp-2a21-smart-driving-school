#include "connexion.h"

#include <QApplication>
<<<<<<< HEAD
=======
#include <QLocale>
#include <QTranslator>
>>>>>>> origin/main-original

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< HEAD
=======

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "integ-menu-examens_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
>>>>>>> origin/main-original
    connexion w;
    w.show();
    return a.exec();
}
