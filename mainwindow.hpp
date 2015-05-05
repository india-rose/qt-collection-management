#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "menubar.hpp"

class QPushButton;
class QDockWidget;
class QStatusBar;
class QWidget;
class QSize;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    MenuBar* mMenu;
    QStatusBar* mStatusBar;
    QDockWidget* mLeftDock;
    QDockWidget* mRight;
    QDockWidget* mRightBottom;
    QSize mScreenSize;
};

#endif // MAINWINDOW_HPP
