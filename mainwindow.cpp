#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcompitem.h"
#include "articlebuttonbroker.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(56, 57, 57)");
    ui->horizontalLayout->setSpacing(0);
    ui->horizontalLayout->setMargin(0);

    ui->sidebarList->setSortingEnabled(false);

    ui->sidebarFrame->setContentsMargins(0,0,0,0);
    ui->contentFrame->setContentsMargins(0,0,0,0);

    ui->articleTitleEdit->setTextColor(QColor("black"));
    ui->articleContentEdit->setTextColor(QColor("black"));

    ui->articleTitleEdit->setText(QString("New Article Title"));
    ui->articleContentEdit->setText(QString("New Content"));

    ui->addArticleButton->raise();

    titleTimer = new QTimer(this);
    titleTimer->setSingleShot(true);
    contentTimer = new QTimer(this);
    contentTimer->setSingleShot(true);

    connect(titleTimer, &QTimer::timeout, [=](){
      QString title = ui->articleTitleEdit->toPlainText();
      emit this->articleTitleChanged(title);
      if(this->currentSelectedButton != nullptr) {
        this->currentSelectedButton->updateTitle(title);
        ui->sidebarList->sortItems(Qt::DescendingOrder);
      }
      isTextChanged = false;
    });

    connect(contentTimer, &QTimer::timeout, [=](){
      QString content = ui->articleContentEdit->toPlainText();
      emit this->articleContentChanged(content);
      if(this->currentSelectedButton != nullptr) {
          if(content.size() > 20) {
              this->currentSelectedButton->updateContent(content.mid(0,20));
          } else {
              this->currentSelectedButton->updateContent(content.mid(0));
          }
        ui->sidebarList->sortItems(Qt::DescendingOrder);
      }
      isTextChanged = false;
    });
    connect(ui->articleTitleEdit, &QTextEdit::textChanged, [=](){
      isTextChanged = true;
        this->titleTimer->start(this->inputTimeout);
    });
    connect(ui->articleContentEdit, &QTextEdit::textChanged, [=](){
      isTextChanged = true;
        this->contentTimer->start(this->inputTimeout);
    });
    connect(ui->addArticleButton, &QPushButton::clicked, [=](){emit this->newArticleAdd();});
}

void MainWindow::addArticle(const Article &article){
    ArticleButton *btn = new ArticleButton(
                article,
                ui->sidebarList
        );
    buttons.push_front(btn);
    currentSelectedButton = btn;
    btn->setChecked(true);

    connect(btn, &ArticleButton::clicked, this, &MainWindow::changeSelectedArticle);
    connect(btn, &ArticleButton::clicked, [=](){
        if(isTextChanged) {
            emit this->articleTitleChanged(ui->articleTitleEdit->toPlainText());
            emit this->articleContentChanged(ui->articleContentEdit->toPlainText());
        }
        emit this->articleOpen(btn->getIdx());
        currentSelectedButton = btn;
    });

    if(isTextChanged) {
            emit this->articleTitleChanged(ui->articleTitleEdit->toPlainText());
            emit this->articleContentChanged(ui->articleContentEdit->toPlainText());
    }
    changeSelectedArticle(article.idx);

    tCompItem *item = new tCompItem(ui->sidebarList);
    std::function<qint64()> func = [=](){return btn->getModifiedTime();};
    articleButtonBroker *broker = new articleButtonBroker(func);
    item->setData(0, qVariantFromValue(broker));
    item->setBackgroundColor(Qt::white);
    item->setSizeHint(btn->minimumSizeHint());
    ui->sidebarList->addItem(item);
    ui->sidebarList->setItemWidget(item, btn);
    ui->sidebarList->sortItems(Qt::DescendingOrder);
}

void MainWindow::articleBufferChanged(const Article &article){
    //block signal while article buffer chainging. If not textChanged fire and undifined behavior
    ui->articleTitleEdit->blockSignals(true);
    ui->articleContentEdit->blockSignals(true);

    ui->articleTitleEdit->setText(article.title);
    ui->articleContentEdit->setText(article.content);

    ui->articleTitleEdit->blockSignals(false);
    ui->articleContentEdit->blockSignals(false);
}

void MainWindow::changeSelectedArticle(int idx) {
    for(auto article : buttons) {
        if(article->isChecked() && (article->getIdx() != idx)) {
            article->setChecked();
            break;
        }
    }
}

MainWindow::~MainWindow()
{
    for(auto btn : buttons){
        if (btn != nullptr)
            delete btn;
    }

    if(contentTimer != nullptr)
            delete contentTimer;
    if(titleTimer != nullptr)
            delete titleTimer;

    delete ui;
}

void MainWindow::showEvent(QShowEvent *event) {
    QWidget::showEvent( event );
    emit mainWindowLoaded();
}
