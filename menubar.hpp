#ifndef MENUBAR_H
#define MENUBAR_H

#include <QObject>

class QMenuBar;
class QInputDialog;
class QFileDialog;

class MenuBar : public QObject
{
    Q_OBJECT
public:
    explicit MenuBar(QObject *parent = 0);
    ~MenuBar();

    QMenuBar* getMenuBar()const;

signals:
    void signalHost(QString host);

private slots:
    void slotOpen();

    void slotAbout();
    void slotHost();

private:
    QMenuBar* mMenuBar;
    QInputDialog* mHostDialog;
    QFileDialog* mFileDialog;
};

#endif // MENUBAR_H
