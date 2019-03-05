#include "articlebutton.h"
#include "ui_articlebutton.h"

ArticleButton::ArticleButton(QWidget *parent) :
    QWidget(parent), ui(new Ui::ArticleButton), checked_(false){
    ui->setupUi(this);
    ui->articleTitle->setTextColor(QColor("black"));
    ui->articleContent->setTextColor(QColor("black"));
    ui->articleTitle->setAlignment(Qt::AlignLeft);
    ui->articleContent->setAlignment(Qt::AlignLeft);

    QObject::connect(this, &ArticleButton::clicked,  [=](){qInfo("clicked");});
}

ArticleButton::ArticleButton(
        const Article &article,
        QWidget *parent
        ) :
    QWidget(parent),
    ui(new Ui::ArticleButton),
    article(article), checked_(false)
{
    ui->setupUi(this);
    ui->articleTitle->setTextColor(QColor("black"));
    ui->articleContent->setTextColor(QColor("black"));
    ui->articleTitle->setAlignment(Qt::AlignLeft);
    ui->articleContent->setAlignment(Qt::AlignLeft);

    ui->articleTitle->setText(article.title);
    ui->articleContent->setText(article.abstractContent);
}

void  ArticleButton::paintEvent(QPaintEvent *event) {
    if(checked_) {
       ui->selectedBar->setStyleSheet("background-color: blue");
    } else {
       ui->selectedBar->setStyleSheet("background-color: white");
    }
}

void ArticleButton::mousePressEvent(QMouseEvent *event){
    //ignore if alreay selected
    if(checked_) {
        return;
    }
    checked_ = !checked_;
    emit clicked(article.idx);
}

int ArticleButton::getIdx() const {
    return article.idx;
}

bool ArticleButton::isChecked() const {
    return checked_;
}

void ArticleButton::setChecked(bool flag) {
    checked_ = flag;
}

ArticleButton::~ArticleButton()
{
    delete ui;
}
