#include "tcompitem.h"
#include "articlebuttonbroker.h"

tCompItem::tCompItem(QListWidget *parent)
    : QListWidgetItem (parent)
{
}


bool tCompItem::operator<(const QListWidgetItem &item) const {
    auto d1 = qvariant_cast<articleButtonBroker*>(data(0));
    auto d2 = qvariant_cast<articleButtonBroker*>(item.data(0));
    if(d2 == nullptr) {
        return true;
    }
    return d1->invoke() < d2->invoke();
}

tCompItem::~tCompItem() {
    auto d = qvariant_cast<articleButtonBroker*>(data(0));
    delete d;
}
