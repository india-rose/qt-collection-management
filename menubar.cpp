#include "menubar.hpp"

#include <QMenuBar>
#include <QMenu>
#include <QVector>
#include <QList>
#include <QAction>
#include <QApplication>
#include <QInputDialog>
#include <QFileDialog>

#ifdef QT_DEBUG
#include <QDebug>
#endif

MenuBar::MenuBar(QObject *parent) : QObject(parent)
{
    mMenuBar=new QMenuBar();
    mHostDialog=new QInputDialog();
    mFileDialog=new QFileDialog();


    QVector<QMenu*> listMenu;
    QList<QAction*> listActions;

    listMenu.append(new QMenu(tr("&File")));
    listMenu.append(new QMenu(tr("&Settings")));

    listActions.append(new QAction(tr("Open"),this));
    connect(listActions.at(0),SIGNAL(triggered()),this,SLOT(slotOpen()));
    listMenu.at(0)->addActions(listActions);
    listActions.clear();

    listActions.append(new QAction(tr("Host"),this));
    listActions.append(new QAction(tr("About"),this));
    connect(listActions.at(0),SIGNAL(triggered()),this,SLOT(slotHost()));
    connect(listActions.at(1),SIGNAL(triggered()),this,SLOT(slotAbout()));
    listMenu.at(1)->addActions(listActions);

    for(int cpt=0 ; cpt < listMenu.size() ; ++cpt)
    {
        mMenuBar->addMenu(listMenu.at(cpt));
    }
}

MenuBar::~MenuBar()
{
}

QMenuBar* MenuBar::getMenuBar() const
{
    return mMenuBar;
}

void MenuBar::slotOpen()
{
#ifdef QT_DEBUG
    qDebug() << "slotOpen";
#endif
    mFileDialog->show();
}

void MenuBar::slotAbout()
{
#ifdef QT_DEBUG
    qDebug() << "slotAbout";
#endif
    QApplication::aboutQt();
}

void MenuBar::slotHost()
{
    QString host=mHostDialog->getText(0,QString(tr("Host")),QString(tr("Hostname:")),QLineEdit::Normal,QString(tr("127.0.0.1")));

#ifdef QT_DEBUG
    qDebug() << "emit signalHost" << host;
#endif
    emit signalHost(host);
}
