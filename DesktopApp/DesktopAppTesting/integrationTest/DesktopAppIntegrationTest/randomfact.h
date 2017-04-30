#ifndef RANDOMFACT_H
#define RANDOMFACT_H

#include <QWidget>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include "httprequestworker.h"

namespace Ui {
class RandomFact;
}

class RandomFact : public QWidget
{
    Q_OBJECT

public:
    explicit RandomFact(QWidget *parent = 0);
    ~RandomFact();

signals:
    void SendHTTPRequest(HttpRequestInput *input);
    void FactWindowClose();

private slots:
    void on_logout_but_clicked();
    void handle_result(HttpRequestWorker *worker, QString StatusCode);
    void AcceptToken(QByteArray token);

    void on_getfact_but_clicked();

protected:
    void closeEvent(QCloseEvent * event);

private:
    Ui::RandomFact *ui;
    HttpRequestWorker *worker;
    QByteArray HashToken;
};

#endif // RANDOMFACT_H


