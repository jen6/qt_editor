#ifndef TCOMPITEM_H
#define TCOMPITEM_H

#include <QWidget>
#include <QListWidget>
#include "articlebutton.h"

class tCompItem: public QListWidgetItem
{
public:
    explicit tCompItem(QListWidget *parent=nullptr);
    virtual bool operator<(const QListWidgetItem &other) const override;
    virtual ~tCompItem() override;
};

#endif // TCOMPITEM_H
