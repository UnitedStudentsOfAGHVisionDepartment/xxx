#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "HalconCpp.h"
#include "oae.cpp"
#include "globals.h"
#include "modifyusersdialog.h"

using namespace HalconCpp;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_2->setText(currentUser);
    this->hide();
    open_Logging_window();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    HImage obrazek;
    HTuple we =0, wy;
    oae ( &obrazek, we , &wy);
    ui->widget->wyswietl(&obrazek);
}

void MainWindow::on_pushButton_2_clicked()
{
    open_Logging_window();
}

void MainWindow::on_actionWyloguj_triggered()
{
    open_Logging_window();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_2->setText(currentUser);
    ui->actionmodify_users->setVisible(false);
}

//obsługa syganłu
void MainWindow::update_label(QString name)
{
    ui->label_2->setText(name);
    if(isAdmin)
    {
        ui->actionmodify_users->setVisible(true);
    }
    else
    {
        ui->actionmodify_users->setVisible(false);
    }
}

void MainWindow::on_actionmodify_users_triggered()
{
    ModifyUsersDialog dialog;
    dialog.exec();
}

void MainWindow::logging_window_closed()
{
    close();
}
void MainWindow::open_Logging_window()
{
    newDialog window;
    window.setModal(true);
    QObject::connect(&window,SIGNAL(update_label(QString)),this,SLOT(update_label(QString)));
    QObject::connect(&window,SIGNAL(logging_window_closed()),this,SLOT(logging_window_closed()));
    window.exec();
}
