#include "mainwindow.h"
#include "ui_mainwindow.h"


const QString BASE_URL = QString("enter/url/here");
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
    delete ui;
}

//login
void MainWindow::on_login_clicked()
{
    //create an request with the url and specific type of request
    HttpRequestInput input(BASE_URL, GET_REQUEST);

    //example of adding a json body to the request
    //input.add_json(json);

    //this signal executes the request
    //emit SendHTTPRequest(&input);
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
    //set up the random fact widget
    fact_display = new RandomFact(this);

    connect(this, SIGNAL(SendToken(QByteArray)), fact_display, SLOT(AcceptToken(QByteArray)));

    //when we get a valid token, emit the token to randomfact.cpp
    //emit SendToken(token);

    //if the login was unsuccessfull, delete the fact_display
    //delete fact_display;

    //delete these two lines
    Q_UNUSED(worker);
    Q_UNUSED(StatusCode);


    //if we get a successful login response then open fact display widget
    // fact_display->show();

}
