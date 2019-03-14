#include "articlebutton.h"
#include "ui_articlebutton.h"
#include <QMenu>
#include <QMouseEvent>

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
    if (event->button() == Qt::RightButton)
    {
        QWidget::mousePressEvent(event);
        return;
    }

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

void ArticleButton::updateTitle(const QString &title) {
    ui->articleTitle->setText(title);
    article.modifiedTime = QDateTime::currentDateTime();
}

void ArticleButton::updateContent(const QString &content) {
    ui->articleContent->setText(content);
    article.modifiedTime = QDateTime::currentDateTime();
}

qint64 ArticleButton::getModifiedTime() const {
    return article.modifiedTime.toMSecsSinceEpoch();

}


ArticleButton::~ArticleButton()
{
    delete ui;
}
