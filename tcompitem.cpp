#include "tcompitem.h"
#include "articlebuttonbroker.h"

TCompItem::TCompItem(QListWidget *parent)
    : QListWidgetItem (parent)
{
}


bool TCompItem::operator<(const QListWidgetItem &item) const {
    auto d1 = qvariant_cast<ArticleButtonBroker*>(data(0));
    auto d2 = qvariant_cast<ArticleButtonBroker*>(item.data(0));
    if(d2 == nullptr) {
        return true;
    }
    return d1->invoke() < d2->invoke();
}

TCompItem::~TCompItem() {
    auto d = qvariant_cast<ArticleButtonBroker*>(data(0));
    delete d;
}
