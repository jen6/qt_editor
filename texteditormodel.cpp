#include "texteditormodel.h"

TextEditorModel::TextEditorModel(QObject *parent) : QObject(parent),
    currentArticleIdx(-1)
{
}

void TextEditorModel::addNewArticle(){
    Article article;
    article.modifiedTime = QDateTime::currentDateTime();
    article.title = QString("New Memo");
    article.content = "";
    article.abstractContent = "";
    db.addArticle(article);

    currentArticleIdx = article.idx;
    articles.push_front(article);
    emit articleAdded(articles[0]);
    currentArticlePtr = &articles[0];
    emit currentArticleChange(article);
}

//TODO on title,content changed update modifiedTime
void TextEditorModel::setArticleTitle(const QString &title){
    if(currentArticlePtr != nullptr) {
        currentArticlePtr->title = title;
        currentArticlePtr->modifiedTime = QDateTime::currentDateTime();
        db.updateArticle(*currentArticlePtr);
    }
}
void TextEditorModel::setArticleContent(const QString &content){
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
void TextEditorModel::openArticle(int idx){
    for(auto &article : articles) {
        if(article.idx == idx) {
            currentArticleIdx = idx;
            currentArticlePtr = &article;
            emit currentArticleChange(article);
            break;
        }
    }
}

void TextEditorModel::deleteArticle(int idx) {
   int i = 0;
   for(const auto &art : articles) {
      if(art.idx == idx) break;
      ++i;
   }
   articles.removeAt(i);
   db.deleteArticle(idx);
}

void TextEditorModel::loadArticlesFromDb() {
    db.loadArticles(articles);
    for(const auto& article : articles) {
        emit articleAdded(article);
    }
}

TextEditorModel::~TextEditorModel() {
}
