#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection
{
public:
    Connection();
    bool createconnect(); // fonction pour établir la connexion
};

#endif // CONNECTION_H

