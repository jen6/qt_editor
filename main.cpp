#include "mainwindow.h"
#include "texteditormodel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    textEditorModel m;

    QObject::connect(&w, &MainWindow::newArticleAdd, &m, &textEditorModel::newArticleAdd);
    QObject::connect(&m, &textEditorModel::addArticle, &w, &MainWindow::addArticle);
    QObject::connect(&w, &MainWindow::articleOpen, &m, &textEditorModel::articleOpen);
    QObject::connect(&m, &textEditorModel::changeShowingArticle, &w, &MainWindow::articleBufferChanged);
    QObject::connect(&w, &MainWindow::articleTitleChanged, &m, &textEditorModel::articleTitleChanged);
    QObject::connect(&w, &MainWindow::articleContentChanged, &m, &textEditorModel::articleContentChanged);

    w.show();
    return app.exec();
}
