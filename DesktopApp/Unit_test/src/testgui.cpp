#include <QtWidgets>
#include <QtTest/QtTest>
#include <QPointer>
#include "mainwindow.h"
#include <QUuid>


const QString LOGIN_BUTTON_NAME = QString("login");
const QString CREATE_ACCOUNT_BUTTON_NAME = QString("createaccount");
const QString LOGIN_USER_NAME = QString("login_username");
const QString LOGIN_PASSWORD_NAME = QString("login_password");
const QString CREATE_ACCOUNT_USER_NAME = QString("create_username");
const QString CREATE_ACCOUNT_PASSWORD1_NAME = QString("create_password1");
const QString CREATE_ACCOUNT_PASSWORD2_NAME = QString("create_password2");
const QString INFO_ERROR = QString("Username Already Exists");
const QString CREATE_STATUS = QString("create_status");
const QString LOGIN_STATUS = QString("login_status");
const QString SUBJECT = QString("subject");
const QString GETFACT_BUT = QString("getfact_but");
const QString FACT_DISPLAY = QString("fact_display");
const QString LOGOUT_BUT = QString("logout_but");
const QString FACT_STATUS = QString("fact_status");

class TestGui: public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    void ClickCreate_BadInfo();
    void ClickCreate_WithInfo();
    void ClickLogin_BadInfo();
    void ClickLogin_WithInfo();


private:
    void CheckSecondScreen();
    void GetFactButtons();
    void GetButtons();
    void CheckLoginStatus(QString errorMsg);
    void CheckCreateStatus(QString errorMsg);
    void CheckFactMB();
    MainWindow *m_window;
    QPushButton *m_LoginBut;
    QPushButton *m_CreateAccountBut;
    QLineEdit *m_LoginUsername;
    QLineEdit *m_LoginPassword;
    QLineEdit *m_CreateAccountUsername;
    QLineEdit *m_CreateAccountPassword1;
    QLineEdit *m_CreateAccountPassword2;
    QLabel *m_login_status;
    QLabel *m_create_status;
    QLineEdit *m_subject;
    QPushButton *m_getfact_but;
    QTextBrowser *m_fact_display;
    QPushButton *m_logout_but;
    QLineEdit *m_fact_status;
    QString m_uuid;
};


void TestGui::ClickCreate_BadInfo()
{
    QSignalSpy executeSignal(m_window,SIGNAL(SendHTTPRequest(HttpRequestInput*)));
    int signalcount = 0;

    ///////////////////////////////////////////////////////////////////////////////////

    m_CreateAccountUsername->setText("TestCreateUsername");
    m_CreateAccountPassword1->setText("");
    m_CreateAccountPassword2->setText("");

    QTest::mouseClick(m_CreateAccountBut,Qt::LeftButton,Qt::NoModifier);

    signalcount = executeSignal.count();
    QVERIFY2(signalcount == 0,"Sent out request with different created passwords.");

    //server should recognize existing account
    CheckCreateStatus("Password Field is empty");

    //////////////////////////////////////////////////////////////////////////////////


    m_CreateAccountUsername->setText("");
    m_CreateAccountPassword1->setText("TestCreatePassword");
    m_CreateAccountPassword2->setText("TestCreatePassword");

    QTest::mouseClick(m_CreateAccountBut,Qt::LeftButton,Qt::NoModifier);

    signalcount = executeSignal.count();
    QVERIFY2(signalcount == 0,"Sent out request with different created passwords.");

    //server should recognize existing account
    CheckCreateStatus("Username Field is empty");

    //////////////////////////////////////////////////////////////////////////////////


    m_CreateAccountUsername->setText("TestCreateUsername");
    m_CreateAccountPassword1->setText("TestCreatePassword1");
    m_CreateAccountPassword2->setText("TestCreatePassword2");

    QTest::mouseClick(m_CreateAccountBut,Qt::LeftButton,Qt::NoModifier);

    signalcount = executeSignal.count();
    QVERIFY2(signalcount == 0,"Sent out request with different created passwords.");

    //server should recognize existing account
    CheckCreateStatus("Two Passwords do not Match");
}


void TestGui::ClickCreate_WithInfo()
{
    QSignalSpy executeSignal(m_window,SIGNAL(SendHTTPRequest(HttpRequestInput*)));

    m_uuid = QString(QUuid::createUuid().toByteArray());

    m_CreateAccountUsername->setText(m_uuid);
    m_CreateAccountPassword1->setText("TestCreatePassword");
    m_CreateAccountPassword2->setText("TestCreatePassword");

    QTest::mouseClick(m_CreateAccountBut,Qt::LeftButton,Qt::NoModifier);

    int signalcount = executeSignal.count();
    QVERIFY2(signalcount == 1,"Did not send out the correct number of requests for a create account.");

    QTest::qWait(1000);

    CheckSecondScreen();
}

void TestGui::ClickLogin_BadInfo()
{
    QSignalSpy executeSignal(m_window,SIGNAL(SendHTTPRequest(HttpRequestInput*)));
    int signalcount = 0;

    ///////////////////////////////////////////////////////////////////////////////////

    m_LoginUsername->setText("TestCreateUsername");
    m_LoginPassword->setText("");

    QTest::mouseClick(m_LoginBut,Qt::LeftButton,Qt::NoModifier);

    signalcount = executeSignal.count();
    QVERIFY2(signalcount == 0,"Sent out request with different created passwords.");

    //server should recognize existing account
    CheckLoginStatus("Password Field is empty");

    //////////////////////////////////////////////////////////////////////////////////


    m_LoginUsername->setText("");
    m_LoginPassword->setText("TestCreatePassword");

    QTest::mouseClick(m_LoginBut,Qt::LeftButton,Qt::NoModifier);

    signalcount = executeSignal.count();
    QVERIFY2(signalcount == 0,"Sent out request with different created passwords.");

    //server should recognize existing account
    CheckLoginStatus("Username Field is empty");
}


void TestGui::ClickLogin_WithInfo()
{
    QSignalSpy executeSignal(m_window,SIGNAL(SendHTTPRequest(HttpRequestInput*)));


    m_LoginUsername->setText(m_uuid);
    m_LoginPassword->setText("TestCreatePassword");

    QTest::mouseClick(m_LoginBut,Qt::LeftButton,Qt::NoModifier);

    int signalcount = executeSignal.count();
    QVERIFY2(signalcount == 1,"Did not send out the correct number of requests for a login.");

    //verfiy a fact came back after logging in
    //CheckFactMB();


}

void TestGui::CheckSecondScreen()
{

    QSignalSpy executeSignal(m_window->fact_display,SIGNAL(SendHTTPRequest(HttpRequestInput*)));
    int signalcount = 0;
    GetFactButtons();

    //////////////////////////////////////////////////////////////////////////////////////////
    m_subject->setText("");

    QTest::mouseClick(m_getfact_but,Qt::LeftButton,Qt::NoModifier);

    signalcount = executeSignal.count();
    QVERIFY2(signalcount == 1,"Did not send out the correct number of requests for a fact.");

    //////////////////////////////////////////////////////////////////////////////////////////
    m_subject->setText("pizza");

    QTest::mouseClick(m_getfact_but,Qt::LeftButton,Qt::NoModifier);

    signalcount = executeSignal.count();
    QVERIFY2(signalcount == 2,"Did not send out the correct number of requests for a fact.");


}

void TestGui::GetFactButtons()
{

    m_subject = m_window->findChild<QLineEdit *>(SUBJECT);
    m_getfact_but = m_window->findChild<QPushButton *>(GETFACT_BUT);
    m_fact_display = m_window->findChild<QTextBrowser *>(FACT_DISPLAY);
    m_logout_but = m_window->findChild<QPushButton *>(LOGOUT_BUT);
    m_fact_status = m_window->findChild<QLineEdit *>(FACT_STATUS);

}





void TestGui::GetButtons()
{
    m_LoginBut = m_window->findChild<QPushButton *>(LOGIN_BUTTON_NAME);
    m_CreateAccountBut = m_window->findChild<QPushButton *>(CREATE_ACCOUNT_BUTTON_NAME);
    m_LoginUsername = m_window->findChild<QLineEdit *>(LOGIN_USER_NAME);
    m_LoginPassword = m_window->findChild<QLineEdit *>(LOGIN_PASSWORD_NAME);
    m_CreateAccountUsername = m_window->findChild<QLineEdit *>(CREATE_ACCOUNT_USER_NAME);
    m_CreateAccountPassword1 = m_window->findChild<QLineEdit *>(CREATE_ACCOUNT_PASSWORD1_NAME);
    m_CreateAccountPassword2 = m_window->findChild<QLineEdit *>(CREATE_ACCOUNT_PASSWORD2_NAME);
    m_login_status = m_window->findChild<QLabel *>(LOGIN_STATUS);
    m_create_status = m_window->findChild<QLabel *>(CREATE_STATUS);


    QVERIFY2(m_LoginBut != NULL || m_CreateAccountBut != NULL || m_LoginUsername != NULL ||
            m_LoginPassword != NULL || m_CreateAccountUsername != NULL || m_CreateAccountPassword1 != NULL ||
            m_CreateAccountPassword2 != NULL ,"Not all gui widgets present.");

}

void TestGui::CheckLoginStatus(QString errorMsg)
{
    QVERIFY2(m_login_status->text() == errorMsg, "Login status did not contain correct text");
}
void TestGui::CheckCreateStatus(QString errorMsg)
{
    QVERIFY2(m_create_status->text() == errorMsg, "Create account status did not contain correct text");
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
