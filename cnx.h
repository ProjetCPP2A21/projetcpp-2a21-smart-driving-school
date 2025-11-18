#ifndef CNX_H
#define CNX_H

#include <QSqlDatabase>

class Connection
{
public:
    Connection();
    bool createconnect(); // Crée et ouvre la connexion Oracle via ODBC
};

#endif // CNX_H
