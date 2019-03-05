#ifndef ARTICLEBUTTON_H
#define ARTICLEBUTTON_H

#include <QWidget>
#include <QPushButton>
#include "article.h"

namespace Ui {
class ArticleButton;
}

class ArticleButton : public QWidget
{
    Q_OBJECT

public:
    explicit ArticleButton(QWidget *parent = nullptr);
    ArticleButton(const Article &article, QWidget *parent = nullptr);
     virtual ~ArticleButton() override;
    int getIdx() const;
    bool isChecked() const;
    void setChecked(bool flag=false);

private:
    Ui::ArticleButton *ui;
    Article article;

signals:
    void clicked(int idx);
protected:
    bool checked_;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mousePressEvent(QMouseEvent* event) override;
};

#endif // ARTICLEBUTTON_H
