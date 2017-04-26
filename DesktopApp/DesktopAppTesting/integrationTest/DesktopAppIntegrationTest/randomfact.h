#ifndef RANDOMFACT_H
#define RANDOMFACT_H

#include <QWidget>

namespace Ui {
class RandomFact;
}

class RandomFact : public QWidget
{
    Q_OBJECT

public:
    explicit RandomFact(QWidget *parent = 0);
    ~RandomFact();

private:
    Ui::RandomFact *ui;
};

#endif // RANDOMFACT_H
