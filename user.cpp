#include "user.hpp"

#include <QString>
#include <QMap>
#include <QUrlQuery>
#include <QNetworkRequest>

User::User(QString name, QString password, QString email)
{
    setName(name);
    setPassword(password);
    setEmail(email);
}

void User::setName(QString name)
{
    mUser.insert("username",name);
}

void User::setPassword(QString password)
{
    mUser.insert("password",password);
}

void User::setEmail(QString email)
{
    mUser.insert("email",email);
}

QString User::getName()const
{
    return mUser.value("username","");
}

QString User::getPassword()const
{
    return mUser.value("password","");
}

QString User::getEmail()const
{
    return mUser.value("email","");
}

void User::addName(QUrlQuery &url_query)
{
    url_query.addQueryItem("username",getName());
}

void User::addEmail(QUrlQuery &url_query)
{
    url_query.addQueryItem("email",getEmail());
}

void User::addPassword(QUrlQuery &url_query)
{
    url_query.addQueryItem("password",getPassword());
}

void User::addAll(QUrlQuery &url_query)
{
    addName(url_query);
    addEmail(url_query);
    addPassword(url_query);
}

void User::addAuth(QNetworkRequest &request)
{
    request.setRawHeader("Authorization","Basic " + QByteArray(QString("%1:%2").arg(getName()).arg(getPassword()).toUtf8()).toBase64());
}
