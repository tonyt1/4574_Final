#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "httprequestworker.h"
#include "jsonkeys.h"
#include "randomfact.h"
#include <QMessageBox>

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
    void SendToken(QString username, QByteArray token);

private slots:
    void on_login_clicked();
    void on_createaccount_clicked();
    void handle_result(HttpRequestWorker *worker, QString StatusCode);
    void show_after_second_close();

private:
    Ui::MainWindow *ui;
    HttpRequestWorker *worker;
    RandomFact *fact_display;
};

#endif // MAINWINDOW_H
