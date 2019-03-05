#ifndef ARTICLEBUTTONBROKER_H
#define ARTICLEBUTTONBROKER_H

#include <functional>
#include <QObject>

class articleButtonBroker
{
public:
    articleButtonBroker() = default;
    articleButtonBroker(const articleButtonBroker &) = default;
    ~articleButtonBroker() = default;
    articleButtonBroker(const std::function<qint64()> &func);
    qint64 invoke();

private:
    std::function<qint64()> func_;
};
Q_DECLARE_METATYPE(articleButtonBroker*);

#endif // ARTICLEBUTTONBROKER_H
