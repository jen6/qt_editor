#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(56, 57, 57)");
    ui->horizontalLayout->setSpacing(0);
    ui->horizontalLayout->setMargin(0);

    ui->sidebarLayout->setSpacing(10);
    ui->sidebarLayout->setMargin(0);
    ui->sidebarLayout->setAlignment(Qt::AlignTop);

    ui->sidebarFrame->setContentsMargins(0,0,0,0);
    ui->contentFrame->setContentsMargins(0,0,0,0);

    ui->articleTitleEdit->setTextColor(QColor("black"));
    ui->articleContentEdit->setTextColor(QColor("black"));

    ui->articleTitleEdit->setText(QString("New Article Title"));
    ui->articleContentEdit->setText(QString("New Content"));

    ui->addArticleButton->raise();

    connect(ui->addArticleButton, &QPushButton::clicked, [=](){emit this->newArticleAdd();});
}

void MainWindow::addArticle(const Article &article){
    ArticleButton *btn = new ArticleButton(
                article,
                ui->sidebarFrame
        );
    connect(btn, &ArticleButton::clicked, this, &MainWindow::changeSelectedArticle);
    btn->setChecked(true);
    changeSelectedArticle(article.idx);
    buttons.push_front(btn);
    ui->sidebarLayout->insertWidget(0, btn);
}

void MainWindow::articleBufferChanged(const Article &article){
    articleBuffer = article;
    ui->articleTitleEdit->setText(articleBuffer.title);
    ui->articleContentEdit->setText(articleBuffer.content);
}

void MainWindow::changeSelectedArticle(int idx) {
    for(auto article : buttons) {
        if(article->isChecked() && (article->getIdx() != idx)) {
            article->setChecked();
            update();
            break;
        }
    }
}

MainWindow::~MainWindow()
{
    for(auto btn : buttons)
        delete btn;
    delete ui;
}

