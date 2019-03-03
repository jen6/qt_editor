#ifndef ARTICLEBUTTON_H
#define ARTICLEBUTTON_H

#include <QWidget>

namespace Ui {
class ArticleButton;
}

class ArticleButton : public QWidget
{
    Q_OBJECT

public:
    explicit ArticleButton(QWidget *parent = nullptr);
    ~ArticleButton();

private:
    Ui::ArticleButton *ui;
};

#endif // ARTICLEBUTTON_H
