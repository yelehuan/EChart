#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "websocketclientwrapper.h"

#include <QWebEngineView>
#include <QWebChannel>
#include <QWebEngineSettings>
#include <QDebug>
#include <QWebSocketServer>
#include "previewpage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mChartManager = new BDChart(this);
    PreviewPage *page = new PreviewPage(this);
    mWebView = new QWebEngineView(this);
    mWebView->setPage(page);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::PluginsEnabled,true);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::JavascriptEnabled,true);
    channel = new QWebChannel(mWebView->page());
    channel->registerObject(QStringLiteral("chartManager"), mChartManager);
    mWebView->page()->setWebChannel(channel);
    mWebView->setUrl(QUrl("qrc:/chart/web/html/index.html"));
    this->setCentralWidget(mWebView);
    this->resize(1000,600);
    connects();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connects()
{
    connect(ui->actionSend, SIGNAL(triggered(bool)), mChartManager, SLOT(slotTest()));
}


