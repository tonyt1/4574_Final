#include "mainwindow.h"
#include "ui_mainwindow.h"


const QString BASE_URL = QString("http://ec2-54-191-23-45.us-west-2.compute.amazonaws.com:8000/facts");
const QString GET_REQUEST = QString("GET");
const QString PUT_REQUEST = QString("POST");


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    worker(new HttpRequestWorker(this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect request worker to parser handle_result
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*, QString)), this, SLOT(handle_result(HttpRequestWorker*, QString)));
    //ui signal to http request worker execute
    connect(this, SIGNAL(SendHTTPRequest(HttpRequestInput*)), worker, SLOT(execute(HttpRequestInput*)));
}

MainWindow::~MainWindow()
{
    //qDebug() << "main window destructor called";
    //delete fact_display;
    delete ui;

}

//login
void MainWindow::on_login_clicked()
{

    if(ui->login_username->text() == ""){
        //QMessageBox::information(this, "", "Username Field is empty");
        ui->login_status->setText("Username Field is empty");
        return;
    }

    if(ui->login_password->text() == ""){
        //QMessageBox::information(this, "", "Password Field is empty");
        ui->login_status->setText("Password Field is empty");
        return;
    }


    //create an request with the url and specific type of request
    HttpRequestInput input(BASE_URL + "/accounts", GET_REQUEST);
    input.add_header_auth(ui->login_username->text(), ui->login_password->text(), "");

    //example of adding a json body to the request
    //input.add_json(json);

    //this signal executes the request
    worker->handler = LOGIN_ACCOUNT;
    emit SendHTTPRequest(&input);
    ui->login_password->clear();
}

//set up creating an account
void MainWindow::on_createaccount_clicked()
{
    if(ui->create_username->text() == ""){
        //QMessageBox::information(this, "", "Username Field is empty");
        ui->create_status->setText("Username Field is empty");
        return;
    }
    if(ui->create_password1->text() == ""){
        //QMessageBox::information(this, "", "Password Field is empty");
        ui->create_status->setText("Password Field is empty");
        return;
    }
    if(ui->create_password1->text() != ui->create_password2->text()){
        //QMessageBox::information(this, "", "Two Passwords do not Match");
        ui->create_status->setText("Two Passwords do not Match");
        return;
    }


    HttpRequestInput input(BASE_URL + "/accounts", PUT_REQUEST);
    input.add_header_auth(ui->create_username->text(), ui->create_password1->text(), "");
    worker->handler = CREATE_ACCOUNT;
    emit SendHTTPRequest(&input);
    ui->create_password1->clear();
    ui->create_password2->clear();
}

//here we should parse to see whether we sucessfully logged in or not, this should also include
// the random fact to display in the message body (worker->response)
void MainWindow::handle_result(HttpRequestWorker *worker, QString StatusCode)
{
    QByteArray token;
    QJsonParseError error;
    QJsonDocument Jdoc = QJsonDocument::fromJson(worker->response, &error);
    if(error.error != QJsonParseError::NoError || error.offset >= worker->response.size()){
        QMessageBox::information(this, "Error", "Bad json from server");
        return;
    }
    QJsonObject JObject = Jdoc.object();
    switch(worker->handler){
    case CREATE_ACCOUNT:
        if(JObject["Status"]!="Created Account"){
            //QMessageBox::information(this, "Error", JObject["Status"].toString());
            ui->create_status->setText(JObject["Status"].toString());
            return;
        }
        //QMessageBox::information(this, "", JObject["Status"].toString());
        ui->create_status->setText(JObject["Status"].toString());
        token = JObject[token_str].toString().toUtf8();

        fact_display = new RandomFact(this);
        fact_display->setWindowTitle("Log in as " + ui->create_username->text());
        connect(this, SIGNAL(SendToken(QString, QByteArray)), fact_display, SLOT(AcceptToken(QString, QByteArray)));
        connect(fact_display, SIGNAL(FactWindowClose()), this, SLOT(show_after_second_close()));
        emit SendToken(ui->create_username->text(), token);
        fact_display->show();
        this->hide();
        break;
    case LOGIN_ACCOUNT:
        if(JObject["Status"]!="Successful Login") {
            QMessageBox::information(this, "Error", JObject["Status"].toString());
            return;
        }
        //QMessageBox::information(this, "", JObject["Status"].toString());
        ui->login_status->setText(JObject["Status"].toString());
        token = JObject[token_str].toString().toUtf8();
        fact_display = new RandomFact(this);
        fact_display->setWindowTitle("Log in as " + ui->login_username->text());
        connect(this, SIGNAL(SendToken(QString, QByteArray)), fact_display, SLOT(AcceptToken(QString, QByteArray)));
        connect(fact_display, SIGNAL(FactWindowClose()), this, SLOT(show_after_second_close()));
        emit SendToken(ui->login_username->text(), token);
        fact_display->show();
        this->hide();
        break;
    }
}

void MainWindow::show_after_second_close()
{
    //qDebug() << "I am showing";
    this->show();
}
