#include "articlebutton.h"
#include "ui_articlebutton.h"

ArticleButton::ArticleButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArticleButton)
{
    ui->setupUi(this);
}

ArticleButton::~ArticleButton()
{
    delete ui;
}
