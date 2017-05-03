#include "randomfact.h"
#include "ui_randomfact.h"


const QString BASE_URL = QString("http://ec2-54-191-23-45.us-west-2.compute.amazonaws.com:8000/facts");
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
    connect(this, SIGNAL(destroyed()), this, SLOT(on_logout_but_clicked()));

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
    HashToken.clear();
    //qDebug() << " token token token : " << HashToken.toInt();
    this->close();

}

void RandomFact::handle_result(HttpRequestWorker *worker, QString StatusCode)
{
    //if this widget is not open then dont do anything
    if(!this->isVisible())
        return;
    QJsonParseError error;
    QJsonDocument Jdoc = QJsonDocument::fromJson(worker->response, &error);

    if(StatusCode == "404"){
        //QMessageBox::information(this, "", "Subject not found");
        ui->fact_status->setText("Subject not found");
        return;
    }else if(error.error != QJsonParseError::NoError || error.offset >= worker->response.size()){
        QMessageBox::information(this, "", "Bad json from server");
        return;
    }

    ui->fact_status->setText("Fact found");

    QJsonObject JObject = Jdoc.object();
    QString s = QString("Subject :" + JObject["subject"].toString() + '\n');
    QString f = QString("Facts :" + JObject["facts"].toString() + '\n');
    ui->fact_display->setText(s + f);

}

void RandomFact::AcceptToken(QString uid, QByteArray token)
{
    HashToken = token;
    this->username = uid;
}

void RandomFact::on_getfact_but_clicked()
{
    if(HashToken.size() != 0){
        if(ui->subject->text().size() != 0){
            HttpRequestInput input(BASE_URL + "/api/subject?topic=" + ui->subject->text(), GET_REQUEST);
            input.add_header_auth(username,"", HashToken);
            emit SendHTTPRequest(&input);
        }else{
            HttpRequestInput input(BASE_URL + "/api/random", GET_REQUEST);
            input.add_header_auth(username,"", HashToken);
            emit SendHTTPRequest(&input);
        }

    }
}

void RandomFact::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    emit FactWindowClose();
}
