#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "httprequestworker.h"
#include "randomfact.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void SendHTTPRequest(HttpRequestInput *input);

private slots:
    void on_login_clicked();
    void on_createaccount_clicked();
    void handle_result(HttpRequestWorker *worker, QString StatusCode);

private:
    Ui::MainWindow *ui;
    HttpRequestWorker *worker;
    RandomFact *fact_display;
};

#endif // MAINWINDOW_H
