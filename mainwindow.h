#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "articlebutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void newArticleAdd();
    void articleTitleChanged(const QString &title);
    void articleContentChanged(const QString &content);
    void articleOpen(int idx);

public slots:
    void addArticle(const Article &article);
    void articleBufferChanged(const Article &article);
    void changeSelectedArticle(int idx);

private:
    Ui::MainWindow *ui;
    QList<ArticleButton *> buttons;
    Article articleBuffer;
};

#endif // MAINWINDOW_H
