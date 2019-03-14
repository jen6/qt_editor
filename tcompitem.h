#ifndef TCOMPITEM_H
#define TCOMPITEM_H

#include <QWidget>
#include <QListWidget>
#include "articlebutton.h"

class TCompItem: public QListWidgetItem
{
public:
    explicit TCompItem(QListWidget *parent=nullptr);
    virtual bool operator<(const QListWidgetItem &other) const override;
    virtual ~TCompItem() override;
};

#endif // TCOMPITEM_H
