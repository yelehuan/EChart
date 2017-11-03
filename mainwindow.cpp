#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWebEngineView>
#include <QWebChannel>
#include <QWebEngineSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mChartManager = new BDChart(this);
    mWebView = new QWebEngineView(this);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::PluginsEnabled,true);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::JavascriptEnabled,true);
    QWebChannel *channal = new QWebChannel(this);
    channal->registerObject(QStringLiteral("interactObj"), mChartManager);
    mWebView->page()->setWebChannel(channal);
    mWebView->load(QUrl("qrc:/chart/web/html/index.html"));
    mWebView->show();
    this->setCentralWidget(mWebView);
    this->resize(1000,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}
