#include "mainwindow.hpp"

#include <QString>
#include <QDebug>
#include <QScreen>
#include <QGuiApplication>
#include <QSize>
#include <QDockWidget>
#include <QWidget>
#include <QStatusBar>
#include <QToolBar>

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
    mToolBar=new QToolBar(this);
    mScreenSize=QGuiApplication::screens().at(0)->availableSize();

    mStatusBar->showMessage(tr("Ready"));
    mStatusBar->show();
    setStatusBar(mStatusBar);

    mLeftDock->setAllowedAreas(Qt::LeftDockWidgetArea);
    mLeftDock->setWidget(new QWidget);
    mLeftDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    addDockWidget(Qt::LeftDockWidgetArea, mLeftDock);

    setMenuBar(mMenu->getMenuBar());

    mRight->setWidget(new QWidget);
    mRight->setFeatures(QDockWidget::NoDockWidgetFeatures);
    splitDockWidget(mLeftDock,mRight,Qt::Horizontal);

    mRightBottom->setWidget(new QWidget);
    mRightBottom->setFeatures(QDockWidget::NoDockWidgetFeatures);
    splitDockWidget(mRight,mRightBottom,Qt::Vertical);

    mToolBar->addAction(tr("Add Image"));
    mToolBar->addAction(tr("Login in"));
    addToolBar(mToolBar);

    setWindowTitle(tr("Desktop Application for India Rose"));
    setMaximumSize(mScreenSize);
    setMinimumSize(mScreenSize/2);
    showMaximized();

    // Put the size of the qdock after the show function
    mLeftDock->setMaximumWidth(mScreenSize.width()/3);
    mRightBottom->setMaximumHeight(mScreenSize.height()/2);
}

MainWindow::~MainWindow()
{
}
