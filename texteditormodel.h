#ifndef TEXTEDITORMODEL_H
#define TEXTEDITORMODEL_H

#include <QObject>
#include <QTimer>
#include "article.h"
#include "database.h"

class textEditorModel : public QObject
{
    Q_OBJECT
public:
    explicit textEditorModel(QObject *parent = nullptr);
    virtual ~textEditorModel();

private:
    void saveArticle();

    Article *currentArticlePtr = nullptr;
    Article currentArticle;
    int currentArticleIdx;
    QList<Article> articles;
    dataBase db;
    const int abstractContentLength = 20;

signals:
    void changeShowingArticle(const Article& article);
    void articleListLoad(const QList<Article>& articles);
    void articleUpdated(const Article& article);
    void addArticle(const Article& article);

public slots:
    void newArticleAdd();
    void articleTitleChanged(const QString &title);
    void articleContentChanged(const QString &content);
    void articleOpen(int idx);
    void articleDelete(int idx);
    void loadArticlesFromDb();
};

#endif // TEXTEDITORMODEL_H
