#ifndef ARTICLE_H
#define ARTICLE_H

#endif // ARTICLE_H
#include <QString>
#include <QDateTime>

struct Article {
    int idx;
    QString title, content, abstractContent;
    QDateTime modifiedTime;
};
