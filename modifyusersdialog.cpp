#include "modifyusersdialog.h"
#include "ui_modifyusersdialog.h"

ModifyUsersDialog::ModifyUsersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyUsersDialog)
{
    ui->setupUi(this);
    qDebug()<<"Wywolanie konstruktora modify user dialog";

}

ModifyUsersDialog::~ModifyUsersDialog()
{
    delete ui;
    //logindb.close();
    //QSqlDatabase::removeDatabase( QSqlDatabase::defaultConnection );
    qDebug()<<"Wywolanie destruktora modify user dialog";
}

void ModifyUsersDialog::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    logindb=QSqlDatabase::addDatabase("QSQLITE");
    logindb.setDatabaseName("C:/Users/Arkadiusz/Desktop/Pracka/Wersja Jarka/nienazwany2/Resources/mydb.db");

    if(logindb.open())
    {
        QSqlQueryModel *model =new QSqlQueryModel();
        QSqlQuery q("select *  from workers");
        q.exec();
        model->setQuery(q);
        ui->tableView->setModel(model);
    }
    else
    {
       qDebug()<<"Baza danych nie działa";
    }
}

void ModifyUsersDialog::delay(int sec)
{
    QTime dieTime= QTime::currentTime().addSecs(sec);
       while (QTime::currentTime() < dieTime)
           QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void ModifyUsersDialog::on_tableView_activated(const QModelIndex &index)
{
    QModelIndex newIndex=index.sibling(index.row(),0);
   QString val=ui->tableView->model()->data(newIndex).toString();
   if(!logindb.open())
   {
       qDebug()<<"Baza danych nie została otwarta";
       return;
   }
   qDebug()<<val<<'\n'<<index.row();
   QSqlQuery qry("select * from workers where id="+val);
   QSqlRecord record = qry.record();
   int surnameCol = record.indexOf("surname"); // index of the field "name"
   int firstnameCol= record.indexOf("name");
   int permissionCol= record.indexOf("permission");
   int usernameCol= record.indexOf("username");
   int passwordCol= record.indexOf("password");
   int idCol= record.indexOf("id");
   qry.next();
   ui->lineEdit_Id->setText(qry.value(idCol).toString());
   ui->lineEdit_Login->setText(qry.value(usernameCol).toString());
   ui->lineEdit_Name->setText(qry.value(firstnameCol).toString());
   ui->lineEdit_Password->setText(qry.value(passwordCol).toString());
   ui->lineEdit_Permission->setText(qry.value(permissionCol).toString());
   ui->lineEdit_Surname->setText(qry.value(surnameCol).toString());
}

void ModifyUsersDialog::on_pushButton_Add_clicked()
{
     QSqlQuery qry("insert into workers(surname,name,permission,username,password,id) values()");

}

void ModifyUsersDialog::on_pushButton_Update_clicked()
{
     QSqlQuery qry("update workers set  where id=");
}

void ModifyUsersDialog::on_pushButton_Delete_clicked()
{
     QSqlQuery qry("delete from workers where id="+ui->lineEdit_Id->text());
}

void ModifyUsersDialog::Update_Teable_View()
{
    QSqlQueryModel *model =new QSqlQueryModel();
    QSqlQuery q("select *  from workers");
    q.exec();
    model->setQuery(q);
    ui->tableView->setModel(model);
}
