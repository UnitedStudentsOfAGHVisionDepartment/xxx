#ifndef MODIFYUSERSDIALOG_H
#define MODIFYUSERSDIALOG_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QSqlQuery>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class ModifyUsersDialog;
}

class ModifyUsersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyUsersDialog(QWidget *parent = nullptr);
    ~ModifyUsersDialog();

private slots:
    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_Add_clicked();

    void on_pushButton_Update_clicked();

    void on_pushButton_Delete_clicked();

private:
    Ui::ModifyUsersDialog *ui;
    void showEvent(QShowEvent *event);
    QSqlDatabase logindb;
    void delay(int sec);
    void Update_Teable_View();
};

#endif // MODIFYUSERSDIALOG_H
