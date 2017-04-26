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
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QTextBrowser *fact_display;

    void setupUi(QWidget *RandomFact)
    {
        if (RandomFact->objectName().isEmpty())
            RandomFact->setObjectName(QStringLiteral("RandomFact"));
        RandomFact->resize(288, 338);
        verticalLayoutWidget = new QWidget(RandomFact);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 258, 327));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        fact_display = new QTextBrowser(verticalLayoutWidget);
        fact_display->setObjectName(QStringLiteral("fact_display"));

        verticalLayout->addWidget(fact_display);


        retranslateUi(RandomFact);

        QMetaObject::connectSlotsByName(RandomFact);
    } // setupUi

    void retranslateUi(QWidget *RandomFact)
    {
        RandomFact->setWindowTitle(QApplication::translate("RandomFact", "Form", 0));
        textBrowser->setHtml(QApplication::translate("RandomFact", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Click the Button Below for a Random Fact. </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Add a subject to narrow random fact</p></body></html>", 0));
        label_2->setText(QApplication::translate("RandomFact", "Subject: ", 0));
        pushButton_2->setText(QApplication::translate("RandomFact", "Get Random Fact", 0));
    } // retranslateUi

};

namespace Ui {
    class RandomFact: public Ui_RandomFact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMFACT_H
