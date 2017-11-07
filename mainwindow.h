#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QHBoxLayout>
#include "bdchart.h"
class QWebEngineView;
class BDChart;
class WebSocketClientWrapper;
class QWebChannel;
class QWebSocketServer;

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void connects();
private:
    Ui::MainWindow *ui;
    QWebEngineView *mWebView;
    BDChart *mChartManager;
    WebSocketClientWrapper *mWebSocketClientWrapper;
    QWebChannel *channel;
    QWebSocketServer* mServer;
};

#endif // MAINWINDOW_H
