#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    ui->horizontalLayout->setSpacing(0);
    for(int i = 0; i < 5; ++i) {
            ArticleButton *btn = new ArticleButton(ui->sidebarFrame);
            ui->sidebarLayout->addWidget(btn);
    }

    ui->horizontalLayout->setMargin(0);

    ui->sidebarLayout->setSpacing(15);
    ui->sidebarLayout->setMargin(0);
    ui->sidebarLayout->setAlignment(Qt::AlignTop);

    ui->sidebarFrame->setContentsMargins(0,0,0,0);
    ui->contentFrame->setContentsMargins(0,0,0,0);

    ui->textEdit->setTextColor(QColor("black"));
    ui->addArticleButton->raise();

}

MainWindow::~MainWindow()
{
    delete ui;
}
