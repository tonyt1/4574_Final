#include "randomfact.h"
#include "ui_randomfact.h"


const QString BASE_URL = QString("enter/url/here");
const QString GET_REQUEST = QString("GET");
const QString PUT_REQUEST = QString("PUT");

RandomFact::RandomFact(QWidget *parent) :
    QWidget(parent, Qt::Window),
    worker(new HttpRequestWorker(this)),
    ui(new Ui::RandomFact)
{
    ui->setupUi(this);
    //connect request worker to parser handle_result
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*, QString)), this, SLOT(handle_result(HttpRequestWorker*, QString)));
    //ui signal to http request worker execute
    connect(this, SIGNAL(SendHTTPRequest(HttpRequestInput*)), worker, SLOT(execute(HttpRequestInput*)));
    //logout if window is closed
    connect(this, SIGNAL(destroyed()), this, SLOT(execute(on_logout_but_clicked())));

    HashToken = NULL;
    //this->show();

}

RandomFact::~RandomFact()
{
    delete ui;
}

void RandomFact::on_logout_but_clicked()
{
    //just discard hash token and close window
    //and close the window
    this->close();

}

void RandomFact::handle_result(HttpRequestWorker *worker, QString StatusCode)
{
    //if this widget is not open then dont do anything
    if(!this->isVisible())
        return;

    /*adding a "fact" to ui
    *
    * ui->fact_display->setText("add random fact here as a QString");
    *
    *
    */
}

void RandomFact::AcceptToken(QByteArray token)
{
    //this gets called when a valid token is received from mainwindow.cpp
}

void RandomFact::on_getfact_but_clicked()
{
    //send http request to get a random fact
    //check the subject input
    /*
     *  if(ui->subject->text() == "")
     *      http request with no subject
     *  else
     *      http request with subject
     *
     */

}

void RandomFact::closeEvent(QCloseEvent *event)
{
    emit FactWindowClose();
}
