#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "newdialog.h"
#include "modifyusersdialog.h"
namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionWyloguj_triggered();

    void on_pushButton_3_clicked();

    void update_label(QString);

    void logging_window_closed();

    void on_actionmodify_users_triggered();

    void showEvent( QShowEvent* event);

    void keyPressEvent(QKeyEvent *e);

private:
    Ui::MainWindow *ui;
    //ModifyUsersDialog modifyUsers;
    void open_Logging_window();
};

#endif // MAINWINDOW_H
