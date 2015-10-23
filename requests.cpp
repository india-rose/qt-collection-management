#include "requests.hpp"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QVariant>
#include <QUrlQuery>
#include <QJsonDocument>

#ifdef QT_DEBUG
#include <QDebug>
#endif

Requests::Requests(QObject *parent,QString name,QString password,QString email) : QObject(parent),mUser(name,password,email)
{
    manager=new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
}


void Requests::login(QString url)
{
#ifdef QT_DEBUG
    qDebug() << "LOGIN";
#endif
    getInformationWithAuth(url+"/api/v1/user");
}

void Requests::signIn(QString url,User user)
{
    QNetworkRequest request;
    QUrlQuery url_querry;

#ifdef QT_DEBUG
    qDebug() << "SIGN IN";
#endif

    user.addAll(url_querry);
    setBasic(request,url+"/api/v1/user");
    manager->post(request,url_querry.toString(QUrl::FullyEncoded).toUtf8());
}

void Requests::signIn(QString url)
{
    signIn(url,mUser);
}

void Requests::deleteUser(QString url)
{
    QNetworkRequest request;
    QUrlQuery url_querry;

#ifdef QT_DEBUG
    qDebug() << "DELETE";
#endif

    setAuth(request,url+"/api/v1/user/delete");
    manager->post(request,url_querry.toString(QUrl::FullyEncoded).toUtf8());
}

void Requests::editName(QString url,QString value)
{
#ifdef QT_DEBUG
    qDebug() << "EDIT Username";
#endif
    edit("username",value,url+"api/v1/user/edit");
}

void Requests::editPassword(QString url,QString value)
{
#ifdef QT_DEBUG
    qDebug() << "EDIT Password";
#endif
    edit("password",value,url+"api/v1/user/edit");
}

void Requests::editEmail(QString url,QString value)
{
#ifdef QT_DEBUG
    qDebug() << "EDIT Email";
#endif
    edit("email",value,url+"api/v1/user/edit");
}

void Requests::settings(QString url)
{
#ifdef QT_DEBUG
    qDebug() << "SETTINGS GET";
#endif
    getInformationWithAuth(url+"api/v1/settings");
}

void Requests::editContent(QString url,QString value)
{
#ifdef QT_DEBUG
    qDebug() << "SETTINGS EDIT CONTENT";
#endif
    edit("content",value,url+"api/v1/settings");
}

void Requests::editVersion(QString url,QString value)
{
#ifdef QT_DEBUG
    qDebug() << "SETTINGS EDIT VERSION";
#endif
    edit("version",value,url+"api/v1/settings");
}

void Requests::getSettingsVersion(QString url,QString versionNumber)
{
#ifdef QT_DEBUG
    qDebug() << "SETTINGS VERSION";
#endif
    getInformationWithAuth(url+"api/v1/settings"+versionNumber);
}


void Requests::getInformationWithAuth(QString url)
{
    QNetworkRequest request;

    setAuth(request,url);
    manager->get(request);
}

void Requests::edit(QString key,QString value,QString url)
{
    QNetworkRequest request;
    QUrlQuery url_querry;

    setAuth(request,url);
    url_querry.addQueryItem(key,value);
    manager->post(request,url_querry.toString(QUrl::FullyEncoded).toUtf8());
}

void Requests::setAuth(QNetworkRequest & request, QString url)
{
    setBasic(request,url);
    mUser.addAuth(request);
}

void Requests::setBasic(QNetworkRequest &request, QString url)
{
    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/x-www-form-urlencoded"));
}

void Requests::reply(QNetworkReply *network)
{
    QJsonDocument recv_json(QJsonDocument::fromJson(QString(network->readAll()).toUtf8()));
#ifdef QT_DEBUG
    qDebug() << recv_json;
#endif
    emit signalRecvJson(recv_json);
}
