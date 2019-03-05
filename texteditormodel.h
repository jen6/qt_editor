#ifndef TEXTEDITORMODEL_H
#define TEXTEDITORMODEL_H

#include <QObject>
#include "article.h"

class textEditorModel : public QObject
{
    Q_OBJECT
public:
    explicit textEditorModel(QObject *parent = nullptr);

private:
    void saveArticle();
    void loadArticlesFromDb();

    int currentArticleIdx;
    //TODO this dummyIdx will changed to sqlite auto increment idx
    int dummyIdx;
    QList<Article> articles;

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
};

#endif // TEXTEDITORMODEL_H
