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

    w.show();
    return app.exec();
}
