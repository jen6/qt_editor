#include "articlebuttonbroker.h"

ArticleButtonBroker::ArticleButtonBroker(const std::function<qint64()> &func)
    : func_(func)
{
}

qint64 ArticleButtonBroker::invoke()
{
    return func_();
}
