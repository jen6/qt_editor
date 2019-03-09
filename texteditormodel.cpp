#include "texteditormodel.h"

textEditorModel::textEditorModel(QObject *parent) : QObject(parent),
    currentArticleIdx(-1)
{
}

void textEditorModel::newArticleAdd(){
    Article article;
    article.modifiedTime = QDateTime::currentDateTime();
    article.title = QString("New Memo");
    article.content = "";
    article.abstractContent = "";
    db.addArticle(article);

    currentArticleIdx = article.idx;
    articles.push_front(article);
    emit addArticle(articles[0]);
    currentArticlePtr = &articles[0];
    emit changeShowingArticle(article);
}

//TODO on title,content changed update modifiedTime
void textEditorModel::articleTitleChanged(const QString &title){
    if(currentArticlePtr != nullptr) {
        currentArticlePtr->title = title;
        currentArticlePtr->modifiedTime = QDateTime::currentDateTime();
        db.updateArticle(*currentArticlePtr);
    }
}
void textEditorModel::articleContentChanged(const QString &content){
    if(currentArticlePtr != nullptr) {
        currentArticlePtr->content = content;
        if(content.length() > abstractContentLength) {
            currentArticlePtr->abstractContent = content.mid(0, abstractContentLength);
        } else {
            currentArticlePtr->abstractContent = content;
        }
        currentArticlePtr->modifiedTime = QDateTime::currentDateTime();
        db.updateArticle(*currentArticlePtr);
    }
}
void textEditorModel::articleOpen(int idx){
    for(auto &article : articles) {
        if(article.idx == idx) {
            //if(article.content.size() == 0) {
            //        //load content from sql
            //}
            currentArticleIdx = idx;
            currentArticlePtr = &article;
            emit changeShowingArticle(article);
            break;
        }
    }
}

void textEditorModel::loadArticlesFromDb() {
    db.loadArticles(articles);
    for(const auto& article : articles) {
        emit addArticle(article);
    }
}

textEditorModel::~textEditorModel() {
}
