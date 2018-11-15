#ifndef OBRAZ_H
#define OBRAZ_H

#include <QWidget>
#include "qhalconwindow.h"
namespace Ui {
class obraz;
}

class obraz : public QWidget
{
    Q_OBJECT

public:
    explicit obraz(QWidget *parent = nullptr);
    ~obraz();
    void wyswietl(HalconCpp::HImage *Image);

private:
    Ui::obraz *ui;
    QHalconWindow *Disp;
};

#endif // OBRAZ_H
