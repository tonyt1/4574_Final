/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *usernam_label;
    QLineEdit *login_username;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *login_password;
    QPushButton *login;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *create_username;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *create_password1;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *create_password2;
    QPushButton *createaccount;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(364, 317);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 6, 341, 264));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        usernam_label = new QLabel(verticalLayoutWidget);
        usernam_label->setObjectName(QStringLiteral("usernam_label"));

        horizontalLayout->addWidget(usernam_label);

        login_username = new QLineEdit(verticalLayoutWidget);
        login_username->setObjectName(QStringLiteral("login_username"));

        horizontalLayout->addWidget(login_username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        login_password = new QLineEdit(verticalLayoutWidget);
        login_password->setObjectName(QStringLiteral("login_password"));

        horizontalLayout_3->addWidget(login_password);


        verticalLayout->addLayout(horizontalLayout_3);

        login = new QPushButton(verticalLayoutWidget);
        login->setObjectName(QStringLiteral("login"));

        verticalLayout->addWidget(login);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        create_username = new QLineEdit(verticalLayoutWidget);
        create_username->setObjectName(QStringLiteral("create_username"));

        horizontalLayout_4->addWidget(create_username);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        create_password1 = new QLineEdit(verticalLayoutWidget);
        create_password1->setObjectName(QStringLiteral("create_password1"));

        horizontalLayout_6->addWidget(create_password1);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        create_password2 = new QLineEdit(verticalLayoutWidget);
        create_password2->setObjectName(QStringLiteral("create_password2"));

        horizontalLayout_7->addWidget(create_password2);


        verticalLayout->addLayout(horizontalLayout_7);

        createaccount = new QPushButton(verticalLayoutWidget);
        createaccount->setObjectName(QStringLiteral("createaccount"));

        verticalLayout->addWidget(createaccount);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 364, 20));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_2->setText(QApplication::translate("MainWindow", "Enter account info and click \"Login\" for a Random Fact.", 0));
        usernam_label->setText(QApplication::translate("MainWindow", "Username: ", 0));
        label_3->setText(QApplication::translate("MainWindow", "Password:", 0));
        login->setText(QApplication::translate("MainWindow", "Login", 0));
        label->setText(QApplication::translate("MainWindow", " If you do not have an account, an account can be created below.", 0));
        label_4->setText(QApplication::translate("MainWindow", "Username: ", 0));
        label_5->setText(QApplication::translate("MainWindow", "Password:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Re-enter Password: ", 0));
        createaccount->setText(QApplication::translate("MainWindow", "CreateAccount", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
