#include "newdialog.h"
#include "ui_newdialog.h"
#include "globals.h"



newDialog::newDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newDialog)
{
    ui->setupUi(this);
    qDebug()<<"Wywolanie konstruktora newdialog";
    this->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowMinMaxButtonsHint );
    this->setWindowTitle(tr("Okno logowania"));
    QPixmap icon(":/Icons/Resources/logging.png");
    this->setWindowIcon(icon);
    isLoged=false;

    logindb=QSqlDatabase::addDatabase("QSQLITE");
    logindb.setDatabaseName(QDir::currentPath() +"/Resources/mydb.db");
    if(logindb.open())
        ui->label_3->setText(tr("Db has been opened succesfully"));
    else
    {
        ui->label_3->setText(tr("Failed to open db"));
    }
}

newDialog::~newDialog()
{
    delete ui;
    qDebug()<<"Wywolanie destruktora newdialog";
    if(!isLoged)
        this->logging_window_closed();
}

void newDialog::on_pushButtonLog_clicked()
{
    QString login=ui->lineEdit_login->text();
    QString password=ui->lineEdit_password->text();

    if(!logindb.isOpen())
    {
        qDebug()<<"Failed to open the database";
        this->logging_window_closed();
        return;
    }
    QSqlQuery qry;
    if(qry.exec("select *  from workers where username='"+login+"' and password='"+password+"'"))
     {
        int count=0;
        while(qry.next())
        {
            count++;
            qDebug()<<count;
        }
        if(count==1)
        {

            ui->label_3->setText(tr("login and password is correct"));
            QSqlQuery q("select *  from workers where username='"+login+"' and password='"+password+"'");
            QSqlRecord record = q.record();
            //ui->label_3->setText(QString::number(record.count()));
            qDebug() << "Number of columns: " << record.count();

            int surnameCol = record.indexOf("surname"); // index of the field "name"
            int firstnameCol= record.indexOf("name");
            int permissionCol= record.indexOf("permission");
            q.next();
            currentUser= q.value(firstnameCol).toString()+" "+q.value(surnameCol).toString();
            if(q.value(permissionCol).toString()=="admin")
                isAdmin=true;
            else
                isAdmin=false;
            //delay(1);
            this->update_label(currentUser);
            isLoged=true;
            logindb.close();
            //QSqlDatabase::removeDatabase( QSqlDatabase::defaultConnection );
            close();
        }
        if(count>1)
            ui->label_3->setText(tr("Duplicate login and password is correct"));
        if(count<1)
        {
            ui->label_3->setText(tr("login and password is not correct"));
            QMessageBox msgBox;
            if(false)
            {
            //this is alternative method but it work worse and require more time
            msgBox.setWindowIcon(QPixmap(":/Icons/Resources/failed.png"));
            msgBox.setInformativeText("  Niepowodzenie         ");
            msgBox.setWindowTitle("ERR");
            msgBox.setWindowFlag(Qt::WindowStaysOnTopHint);
            msgBox.exec();
            }else
            msgBox.critical(this,tr("Niepowodzenie"),tr("Dane niepoprawne"));

        }
    }
}


void newDialog::delay(int sec)
{
    QTime dieTime= QTime::currentTime().addSecs(sec);
       while (QTime::currentTime() < dieTime)
           QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
