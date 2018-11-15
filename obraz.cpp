#include "obraz.h"
#include "ui_obraz.h"
#include <QGridLayout>
using namespace HalconCpp;

obraz::obraz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::obraz)
{
    Disp = new QHalconWindow(this);
    Disp->setMinimumSize(1200,900);
    ui->setupUi(this);
}

obraz::~obraz()
{
    delete ui;
}


void obraz::wyswietl(HImage *Image)
{
    Hlong ImageWidth =0, ImageHeight =0;
    HTuple mull=1, add=1;
    (*Image).GetImageSize(&ImageWidth, &ImageHeight);
    //Disp->setMinimumSize(ImageWidth,ImageHeight);

    Disp->GetHalconBuffer()->SetPart(0, 0, ImageHeight-1, ImageWidth-1);
    Disp->GetHalconBuffer()->DispObj(*Image);
    Disp->GetHalconBuffer()->FlushBuffer();
}
