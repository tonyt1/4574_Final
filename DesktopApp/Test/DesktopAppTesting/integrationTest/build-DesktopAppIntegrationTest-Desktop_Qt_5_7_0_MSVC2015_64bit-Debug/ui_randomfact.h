/********************************************************************************
** Form generated from reading UI file 'randomfact.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDOMFACT_H
#define UI_RANDOMFACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RandomFact
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *subject;
    QPushButton *getfact_but;
    QTextBrowser *fact_display;
    QPushButton *logout_but;

    void setupUi(QWidget *RandomFact)
    {
        if (RandomFact->objectName().isEmpty())
            RandomFact->setObjectName(QStringLiteral("RandomFact"));
        RandomFact->resize(276, 338);
        verticalLayoutWidget = new QWidget(RandomFact);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 258, 327));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        subject = new QLineEdit(verticalLayoutWidget);
        subject->setObjectName(QStringLiteral("subject"));

        horizontalLayout->addWidget(subject);


        verticalLayout->addLayout(horizontalLayout);

        getfact_but = new QPushButton(verticalLayoutWidget);
        getfact_but->setObjectName(QStringLiteral("getfact_but"));

        verticalLayout->addWidget(getfact_but);

        fact_display = new QTextBrowser(verticalLayoutWidget);
        fact_display->setObjectName(QStringLiteral("fact_display"));

        verticalLayout->addWidget(fact_display);

        logout_but = new QPushButton(verticalLayoutWidget);
        logout_but->setObjectName(QStringLiteral("logout_but"));

        verticalLayout->addWidget(logout_but);


        retranslateUi(RandomFact);

        QMetaObject::connectSlotsByName(RandomFact);
    } // setupUi

    void retranslateUi(QWidget *RandomFact)
    {
        RandomFact->setWindowTitle(QApplication::translate("RandomFact", "Form", 0));
        label->setText(QApplication::translate("RandomFact", "Click the Button Below for a Random Fact. \n"
"Add a subject to narrow random fact", 0));
        label_2->setText(QApplication::translate("RandomFact", "Subject: ", 0));
        getfact_but->setText(QApplication::translate("RandomFact", "Get Random Fact", 0));
        logout_but->setText(QApplication::translate("RandomFact", "Logout", 0));
    } // retranslateUi

};

namespace Ui {
    class RandomFact: public Ui_RandomFact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMFACT_H
