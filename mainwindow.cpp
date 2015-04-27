#include "mainwindow.hpp"

#include <QPushButton>
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    button=new QPushButton(th is);
    menu=new MenuBar();
    setMenuBar(menu->getMenuBar());
//    button->setText(tr("Trololo"));
    cpt=0;
//    connect(button,SIGNAL(clicked()),this,SLOT(react()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::react()
{
    QString* tmp=new QString("Trololo");
    ++cpt;
    *tmp+=" "+QString::number(cpt);
    qDebug() << tmp << *tmp << tmp->toStdString().c_str();
    button->setText(tr(tmp->toStdString().c_str()));
}
