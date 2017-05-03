#include "mainwindow.h"
#include "ui_mainwindow.h"


const QString BASE_URL = QString("enter/url/here");
const QString GET_REQUEST = QString("GET");


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
    HttpRequestInput input(BASE_URL, GET_REQUEST);

    //example of adding a json body to the request
    //input.add_json(json);

    //this signal executes the request
    //emit SendHTTPRequest(&input);
}

//here we should parse to see whether we sucessfully logged in or not, this should also include
// the random fact to display in the message body (worker->response)
void MainWindow::handle_result(HttpRequestWorker *worker, QString StatusCode)
{
    Q_UNUSED(worker);
    Q_UNUSED(StatusCode);

}