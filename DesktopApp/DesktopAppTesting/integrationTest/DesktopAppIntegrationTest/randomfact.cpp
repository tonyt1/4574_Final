#include "randomfact.h"
#include "ui_randomfact.h"

RandomFact::RandomFact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RandomFact)
{
    ui->setupUi(this);
}

RandomFact::~RandomFact()
{
    delete ui;
}

void RandomFact::on_logout_but_clicked()
{

}
