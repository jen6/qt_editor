#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QList>
#include <QSqlDatabase>
#include "article.h"

class dataBase : public QObject
{
public:
    dataBase(QObject *parent = nullptr);
    void loadArticles(QList<Article> &articles);
   // void updateArticle(const Article &article);
   // void deleteArticle(int idx);

private:
    QSqlDatabase db;

};

#endif // DATABASE_H
