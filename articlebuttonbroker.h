#ifndef ARTICLEBUTTONBROKER_H
#define ARTICLEBUTTONBROKER_H

#include <functional>
#include <QObject>

class ArticleButtonBroker
{
public:
    ArticleButtonBroker() = default;
    ArticleButtonBroker(const ArticleButtonBroker &) = default;
    ~ArticleButtonBroker() = default;
    ArticleButtonBroker(const std::function<qint64()> &func);
    qint64 invoke();

private:
    std::function<qint64()> func_;
};
Q_DECLARE_METATYPE(ArticleButtonBroker*);

#endif // ARTICLEBUTTONBROKER_H
