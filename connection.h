#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
<<<<<<< HEAD
=======
#include <QString>
>>>>>>> 4229cbb (ajout arduino)

class Connection
{
public:
    Connection();
    bool createconnect();
<<<<<<< HEAD
=======
    QString getLastError() const { return lastError; }

private:
    QString lastError;
>>>>>>> 4229cbb (ajout arduino)
};

#endif // CONNECTION_H
