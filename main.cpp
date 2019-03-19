#include "mainwindow.h"
#include "texteditormodel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    TextEditorModel m;

    QObject::connect(&w, &MainWindow::mainWindowLoaded, &m, &TextEditorModel::loadArticlesFromDb);
    QObject::connect(&w, &MainWindow::newArticleAdd, &m, &TextEditorModel::addNewArticle);
    QObject::connect(&m, &TextEditorModel::articleAdded, &w, &MainWindow::addArticle);
    QObject::connect(&w, &MainWindow::articleOpen, &m, &TextEditorModel::openArticle);
    QObject::connect(&m, &TextEditorModel::currentArticleChange, &w, &MainWindow::articleBufferChanged);
    QObject::connect(&w, &MainWindow::articleTitleChanged, &m, &TextEditorModel::setArticleTitle);
    QObject::connect(&w, &MainWindow::articleContentChanged, &m, &TextEditorModel::setArticleContent);
    QObject::connect(&w, &MainWindow::articleDelete, &m, &TextEditorModel::deleteArticle);

    w.show();
    return app.exec();
}
