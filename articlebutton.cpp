#include "articlebutton.h"
#include "ui_articlebutton.h"

ArticleButton::ArticleButton(QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::ArticleButton)
{
    ui->setupUi(this);
    ui->articleTitle->setTextColor(QColor("black"));
    ui->articleContent->setTextColor(QColor("black"));
    ui->articleTitle->setAlignment(Qt::AlignLeft);
    ui->articleContent->setAlignment(Qt::AlignLeft);
}

ArticleButton::ArticleButton(
        QString title,
        QString content,
        QWidget *parent
        ) :
    QPushButton(parent),
    ui(new Ui::ArticleButton),
    title(title),
    content(content)
{
    ui->setupUi(this);
    ui->articleTitle->setTextColor(QColor("black"));
    ui->articleContent->setTextColor(QColor("black"));
    ui->articleTitle->setAlignment(Qt::AlignLeft);
    ui->articleContent->setAlignment(Qt::AlignLeft);

    ui->articleTitle->setText(title);
    ui->articleContent->setText(content);

}



ArticleButton::~ArticleButton()
{
    delete ui;
}
