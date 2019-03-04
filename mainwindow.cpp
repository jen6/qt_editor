#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(56, 57, 57)");
    ui->horizontalLayout->setSpacing(0);

    connect(ui->addArticleButton, SIGNAL(clicked()), this, SLOT(addArticle()));

    ui->horizontalLayout->setMargin(0);

    ui->sidebarLayout->setSpacing(10);
    ui->sidebarLayout->setMargin(0);
    ui->sidebarLayout->setAlignment(Qt::AlignTop);

    ui->sidebarFrame->setContentsMargins(0,0,0,0);
    ui->contentFrame->setContentsMargins(0,0,0,0);

    ui->textEdit->setTextColor(QColor("black"));
    ui->addArticleButton->raise();
}

void MainWindow::addArticle(){
    int currentSize = buttons.size();
    ArticleButton *btn = new ArticleButton(
                QString::number(currentSize),
                QString("content, content"),
                ui->sidebarFrame
        );
    buttons.push_back(btn);
    ui->sidebarLayout->insertWidget(0, btn);
}

MainWindow::~MainWindow()
{
    for(auto btn : buttons)
        delete btn;
    delete ui;
}
