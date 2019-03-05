#include "articlebuttonbroker.h"

articleButtonBroker::articleButtonBroker(const std::function<qint64()> &func)
    : func_(func)
{
}

qint64 articleButtonBroker::invoke()
{
    return func_();
}
