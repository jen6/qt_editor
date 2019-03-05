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

//TODO on title,content changed update modifiedTime
void textEditorModel::articleTitleChanged(const QString &title){
    qInfo("changed!Title");
    if(currentArticlePtr != nullptr) {
        currentArticlePtr->title = title;
    }
    //commit();
}
void textEditorModel::articleContentChanged(const QString &content){
    qInfo("changed!Content");
    if(currentArticlePtr != nullptr) {
        currentArticlePtr->content = content;
    }
    //commit();
}
void textEditorModel::articleOpen(int idx){
    for(auto &article : articles) {
        if(article.idx == idx) {
            if(article.content.size() == 0) {
                    //load content from sql
            }
            currentArticleIdx = idx;
            currentArticlePtr = &article;
            emit changeShowingArticle(article);
            break;
        }
    }
}

textEditorModel::~textEditorModel() {
}
