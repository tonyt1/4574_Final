#include <QtWidgets>
#include <QtTest/QtTest>
#include <QPointer>
#include "mainwindow.h"



const QString LOGIN_BUTTON_NAME = QString("login");
const QString CREATE_ACCOUNT_BUTTON_NAME = QString("createaccount");
const QString LOGIN_USER_NAME = QString("login_username");
const QString LOGIN_PASSWORD_NAME = QString("login_password");
const QString CREATE_ACCOUNT_USER_NAME = QString("create_username");
const QString CREATE_ACCOUNT_PASSWORD1_NAME = QString("create_password1");
const QString CREATE_ACCOUNT_PASSWORD2_NAME = QString("create_password2");
const QString INFO_ERROR = QString("Username Already Exists");

class TestGui: public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    void ClickCreat_WithInfo();
    void ClickCreate_SameInfo();
    void ClickLogin_WithInfo();


private:
    void GetButtons();
    void CheckErrorMB();
    void CheckFactMB();
    MainWindow *m_window;
    QPushButton *m_LoginBut;
    QPushButton *m_CreateAccountBut;
    QLineEdit *m_LoginUsername;
    QLineEdit *m_LoginPassword;
    QLineEdit *m_CreateAccountUsername;
    QLineEdit *m_CreateAccountPassword1;
    QLineEdit *m_CreateAccountPassword2;
};

void TestGui::ClickCreat_WithInfo()
{
    //QSignalSpy executeSignal(m_window,SIGNAL(SendHTTPRequest(HttpRequestInput*)));

    m_CreateAccountUsername->setText("TestCreateUsername");
    m_CreateAccountPassword1->setText("TestCreatePassword");
    m_CreateAccountPassword2->setText("TestCreatePassword");

    QTest::mouseClick(m_CreateAccountBut,Qt::LeftButton,Qt::NoModifier);

    //int signalcount = executeSignal.count();
    //QVERIFY2(signalcount == 1,"Did not send out the correct number of requests for a create account.");
    //CheckFactMB();
}

void TestGui::ClickCreate_SameInfo()
{
    //QSignalSpy executeSignal(m_window,SIGNAL(SendHTTPRequest(HttpRequestInput*)));

    m_CreateAccountUsername->setText("TestCreateUsername");
    m_CreateAccountPassword1->setText("TestCreatePassword");
    m_CreateAccountPassword2->setText("TestCreatePassword");

    QTest::mouseClick(m_CreateAccountBut,Qt::LeftButton,Qt::NoModifier);

    //int signalcount = executeSignal.count();
    //QVERIFY2(signalcount == 0,"Sent out request with different created passwords.");

    //server should recognize existing account
    CheckErrorMB();

}



void TestGui::ClickLogin_WithInfo()
{
 //   QSignalSpy executeSignal(m_window,SIGNAL(SendHTTPRequest(HttpRequestInput*)));


    m_LoginUsername->setText("TestCreateUsername");
    m_LoginPassword->setText("TestCreatePassword");

    QTest::mouseClick(m_LoginBut,Qt::LeftButton,Qt::NoModifier);

    //int signalcount = executeSignal.count();
    //QVERIFY2(signalcount == 1,"Did not send out the correct number of requests for a login.");

    //verfiy a fact came back after logging in
    CheckFactMB();
}





void TestGui::GetButtons()
{
    m_LoginBut = m_window->findChild<QPushButton *>(LOGIN_BUTTON_NAME);
    m_CreateAccountBut = m_window->findChild<QPushButton *>(LOGIN_BUTTON_NAME);
    m_LoginUsername = m_window->findChild<QLineEdit *>(LOGIN_USER_NAME);
    m_LoginPassword = m_window->findChild<QLineEdit *>(LOGIN_PASSWORD_NAME);
    m_CreateAccountUsername = m_window->findChild<QLineEdit *>(CREATE_ACCOUNT_USER_NAME);
    m_CreateAccountPassword1 = m_window->findChild<QLineEdit *>(CREATE_ACCOUNT_PASSWORD1_NAME);
    m_CreateAccountPassword2 = m_window->findChild<QLineEdit *>(CREATE_ACCOUNT_PASSWORD2_NAME);

    QVERIFY2(m_LoginBut != NULL || m_CreateAccountBut != NULL || m_LoginUsername != NULL ||
            m_LoginPassword != NULL || m_CreateAccountUsername != NULL || m_CreateAccountPassword1 != NULL ||
            m_CreateAccountPassword2 != NULL ,"Not all gui widgets present.");

}

void TestGui::CheckErrorMB()
{
    //get the QmessageBox that should of popped up
    QMessageBox *mb = qobject_cast<QMessageBox *>(QApplication::activeModalWidget());

    QVERIFY2(mb != NULL, "Error Message box did not appear");
    QVERIFY2(mb->text() == INFO_ERROR, "Error Message box did not contain correct text");
}

void TestGui::CheckFactMB()
{
    //get the QmessageBox that should of popped up
    QMessageBox *mb = qobject_cast<QMessageBox *>(QApplication::activeModalWidget());

    QVERIFY2(mb != NULL, "Fact Message box did not appear");
    QVERIFY2(mb->text() != "", "Fact Message box did not contain text");
}


// Called before every test case
// Constructs a ShapeMaster object but doesn't set the playground
// Verifies that all of the accessible widgets have been created and are properly set up
void TestGui::init()
{
    qRegisterMetaType<HttpRequestInput*>("HttpRequestInput*");
    m_window = new MainWindow;
    Q_ASSERT(m_window != NULL);
    m_window->show();
    QTest::qWait(500);
    GetButtons();
}

// Called after every test case
void TestGui::cleanup()
{
    m_window->close();
    delete m_window;
   /* delete m_LoginBut;
    delete m_CreateAccountBut;
    delete m_LoginUsername;
    delete m_LoginPassword;
    delete m_CreateAccountUsername;
    delete m_CreateAccountPassword1;
    delete m_CreateAccountPassword2;*/

}

QTEST_MAIN(TestGui)
#include "testgui.moc"
