#include "texteditormodel.h"

textEditorModel::textEditorModel(QObject *parent) : QObject(parent),
    currentArticleIdx(-1), dummyIdx(0)
{

}

void textEditorModel::newArticleAdd(){
    Article article;
    article.modifiedTime = QDateTime::currentDateTime();
    article.title = QString("New Memo");
    article.content = "";
    article.abstractContent = "";
    article.idx = dummyIdx++;

    currentArticleIdx = article.idx;
    articles.push_front(article);
    emit addArticle(article);
    emit changeShowingArticle(article);
}

void textEditorModel::articleTitleChanged(const QString &title){

}
void textEditorModel::articleContentChanged(const QString &content){

}
void textEditorModel::articleOpen(int idx){

}
