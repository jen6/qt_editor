#ifndef TEXTEDITORMODEL_H
#define TEXTEDITORMODEL_H

#include <QObject>
#include <QTimer>
#include "article.h"
#include "database.h"

class TextEditorModel : public QObject
{
    Q_OBJECT
public:
    explicit TextEditorModel(QObject *parent = nullptr);
    virtual ~TextEditorModel();

private:
    void saveArticle();

    Article *currentArticlePtr = nullptr;
    Article currentArticle;
    int currentArticleIdx;
    QList<Article> articles;
    DataBase db;
    const int abstractContentLength = 20;

signals:
    void currentArticleChange(const Article& article);
    void articleListLoaded(const QList<Article>& articles);
    void articleUpdated(const Article& article);
    void articleAdded(const Article& article);

public slots:
    void addNewArticle();
    void setArticleTitle(const QString &title);
    void setArticleContent(const QString &content);
    void openArticle(int idx);
    void deleteArticle(int idx);
    void loadArticlesFromDb();
};

#endif // TEXTEDITORMODEL_H
