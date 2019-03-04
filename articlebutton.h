#ifndef ARTICLEBUTTON_H
#define ARTICLEBUTTON_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class ArticleButton;
}

class ArticleButton : public QPushButton
{
    Q_OBJECT

public:
    explicit ArticleButton(QWidget *parent = nullptr);
    ArticleButton(QString title = "", QString content = "", QWidget *parent = nullptr);
     virtual ~ArticleButton();

private:
    Ui::ArticleButton *ui;
    QString title, content;
};

#endif // ARTICLEBUTTON_H
