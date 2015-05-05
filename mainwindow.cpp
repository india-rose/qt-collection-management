#include "mainwindow.hpp"

#include <QString>
#include <QDebug>
#include <QScreen>
#include <QGuiApplication>
#include <QSize>
#include <QDockWidget>
#include <QWidget>
#include <QStatusBar>

#ifdef QT_DEBUG
#include <QDebug>
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mMenu=new MenuBar();
    mStatusBar=new QStatusBar(this);
    mLeftDock=new QDockWidget(tr("List of devices"),this);
    mRight=new QDockWidget(tr("Images"),this);
    mRightBottom=new QDockWidget(tr("Informations"),this);
    mScreenSize=QGuiApplication::screens().at(0)->availableSize();

    mStatusBar->showMessage(tr("Ready"));
    mStatusBar->show();
    setStatusBar(mStatusBar);

    mLeftDock->setAllowedAreas(Qt::LeftDockWidgetArea);
    mLeftDock->setWidget(new QWidget);
    mLeftDock->setMaximumSize(mScreenSize.width()/10,mScreenSize.height()-mScreenSize.height()/10);
    mLeftDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    addDockWidget(Qt::LeftDockWidgetArea, mLeftDock);

    setMenuBar(mMenu->getMenuBar());

    mRight->setWidget(new QWidget);
    mRight->setFeatures(QDockWidget::NoDockWidgetFeatures);
    splitDockWidget(mLeftDock,mRight,Qt::Horizontal);

    mRightBottom->setWidget(new QWidget);
    mRightBottom->setFeatures(QDockWidget::NoDockWidgetFeatures);
    splitDockWidget(mRight,mRightBottom,Qt::Vertical);

    setWindowTitle(tr("Desktop Application for India Rose"));
    setMaximumSize(mScreenSize);
    setMinimumSize(mScreenSize/2);
    showMaximized();

    mRightBottom->setMaximumSize(mRightBottom->width(),2*mRightBottom->height()/3);
}

MainWindow::~MainWindow()
{
}
