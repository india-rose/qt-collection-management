#ifndef USER_H
#define USER_H

#include <QMap>
class QString;
class QUrlQuery;
class QNetworkRequest;

struct User
{
public:
    User(QString name,QString password,QString email);

    QString getName()const;
    QString getPassword()const;
    QString getEmail()const;

    void setName(QString name);
    void setPassword(QString password);
    void setEmail(QString email);

    void addName(QUrlQuery & url_query);
    void addEmail(QUrlQuery & url_query);
    void addPassword(QUrlQuery & url_query);
    void addAll(QUrlQuery & url_query);
    void addAuth(QNetworkRequest & request);

private:
    QMap<QString,QString> mUser;
};

#endif // USER_H
