#ifndef REQUESTS_H
#define REQUESTS_H

#include <QObject>

#include "user.hpp"
class QNetworkAccessManager;
class QNetworkReply;
class QString;
class QNetworkRequest;
class QJsonDocument;

class Requests : public QObject
{
    Q_OBJECT
public:
    User mUser;

    explicit Requests(QObject *parent = 0,QString name="",QString password="",QString email="");

    void login(QString url);
    void signIn(QString url,User user);
    void signIn(QString url);
    void deleteUser(QString url);
    void editName(QString url,QString value);
    void editPassword(QString url,QString value);
    void editEmail(QString url,QString value);
    void settings(QString url);
    void editContent(QString url,QString value);
    void editVersion(QString url,QString value);
    void getSettingsVersion(QString url,QString versionNumber);

private:
    QNetworkAccessManager* manager;
    void getInformationWithAuth(QString url);
    void edit(QString key,QString value,QString url);
    void setAuth(QNetworkRequest & request,QString url);
    void setBasic(QNetworkRequest & request,QString url);
signals:
    void signalRecvJson(QJsonDocument & json);
public slots:
    void reply(QNetworkReply* network);
};

#endif // REQUESTS_H
