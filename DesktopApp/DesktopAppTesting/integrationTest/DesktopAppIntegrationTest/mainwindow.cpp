#include "mainwindow.h"
#include "ui_mainwindow.h"


const QString BASE_URL = QString("http://ec2-54-191-23-45.us-west-2.compute.amazonaws.com:8000/facts");
const QString GET_REQUEST = QString("GET");
const QString PUT_REQUEST = QString("PUT");


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
    qDebug() << "main window destructor called";
    //delete fact_display;
    delete ui;

}

//login
void MainWindow::on_login_clicked()
{

    if(ui->login_username->text() == ""){
        QMessageBox::information(this, "", "Username Field is empty");
        return;
    }

    if(ui->login_password->text() == ""){
        QMessageBox::information(this, "", "Password Field is empty");
        return;
    }


    //create an request with the url and specific type of request
    HttpRequestInput input(BASE_URL + "/accounts", GET_REQUEST);
    input.add_header_auth(ui->login_username->text(), ui->login_password->text(), "");

    //example of adding a json body to the request
    //input.add_json(json);

    //this signal executes the request
    emit SendHTTPRequest(&input);
}

//set up creating an account
void MainWindow::on_createaccount_clicked()
{
    //create an request with the url and specific type of request
    HttpRequestInput input(BASE_URL, PUT_REQUEST);

    //example of adding a json body to the request
    //input.add_json(json);

    //this signal executes the request
    //emit SendHTTPRequest(&input);
}

//here we should parse to see whether we sucessfully logged in or not, this should also include
// the random fact to display in the message body (worker->response)
void MainWindow::handle_result(HttpRequestWorker *worker, QString StatusCode)
{
    //debug
    QMessageBox::information(this, "", worker->response);

    if(StatusCode.toInt() != 200){
        QMessageBox::information(this, "", "Incorrect Login Information");
        return;
    }

    //parse
    QJsonParseError error;
    QJsonDocument Jdoc = QJsonDocument::fromJson(worker->response, &error);

    if(error.error != QJsonParseError::NoError || error.offset >= worker->response.size()){
        QMessageBox::information(this, "", "Bad json from server");
        return;
    }


    QJsonObject JObject = Jdoc.object();

    QByteArray token = JObject[token_str].toString().toUtf8();

    qDebug() << " token token token : " << token;



    //set up the random fact widget
    fact_display = new RandomFact(this);

    connect(this, SIGNAL(SendToken(QByteArray)), fact_display, SLOT(AcceptToken(QByteArray)));
    connect(fact_display, SIGNAL(FactWindowClose()), this, SLOT(show_after_second_close()));


    //when we get a valid token, emit the token to randomfact.cpp
    emit SendToken("token");

    //if we get a successful login response then open fact display widget
    fact_display->show();
    this->hide();


}

void MainWindow::show_after_second_close()
{
    qDebug() << "I am showing";
    this->show();
}
