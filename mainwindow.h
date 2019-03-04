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
public slots:
    void addArticle();

private:
    Ui::MainWindow *ui;
    QList<ArticleButton *> buttons;
};

#endif // MAINWINDOW_H
