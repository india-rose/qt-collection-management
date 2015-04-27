#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "menubar.hpp"

class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPushButton* button;
    int cpt;

public slots:
    void react();

private:
    MenuBar* menu;
};

#endif // MAINWINDOW_HPP
