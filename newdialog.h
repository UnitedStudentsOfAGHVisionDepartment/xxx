#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlQuery>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QInputEvent>
#include <QMainWindow>
#include <QtWidgets>
//#include "mainwindow.h"

namespace Ui {
class newDialog;
}

class newDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newDialog(QWidget *parent = nullptr);

    ~newDialog();

private slots:
    void on_pushButtonLog_clicked();
    void keyPressEvent(QKeyEvent *e);
signals:
    void update_label(QString name);
    void logging_window_closed();
private:
    Ui::newDialog *ui;
    QSqlDatabase logindb;
    void delay(int sec);
    bool isLoged=false;
    QStatusBar *bar = new QStatusBar(this);
};

#endif // NEWDIALOG_H

