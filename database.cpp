#include "database.h"

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QStandardPaths>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlResult>
#include <QDateTime>

dataBase::dataBase(QObject *parent) : QObject(parent)
{
    auto locs = QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation);
    if (locs.length() == 0){
        throw std::runtime_error("Can't find AppDataLocatoin");
    }

    db = QSqlDatabase::addDatabase("QSQLITE");
    for (auto &loc : locs){
        loc.append("/editor.db");
        db.setDatabaseName(loc);
        if(!db.open()) {
            continue;
        }else {
            break;
        }

    }
    if(!db.open()) {
        std::string error = "Db not Opened! : ";
        error.append(db.lastError().text().toUtf8().data());
        throw std::runtime_error(error);
    }

    QSqlQuery query;
    query.prepare(
    "\
        CREATE TABLE IF NOT EXISTS editor (\
        idx INTEGER PRIMARY KEY AUTOINCREMENT,\
        title TEXT,\
        content TEXT,\
        abstract_content TEXT,\
        date, TEXT)"
     );
    query.exec();
}

void dataBase::loadArticles(QList<Article> &articles) {
    QSqlQuery query;
    bool excuteStatus = query.exec("\
    SELECT idx, title, abstract_content, date \
    FROM editor"
    );

    if(!excuteStatus) {
        throw std::runtime_error(query.lastError().text().toUtf8().data());
    }

    while(query.next()){
        Article art;
        art.idx = query.value(0).toInt();
        art.title = query.value(1).toString();
        art.abstractContent= query.value(2).toString();
        auto date = query.value(3).toString();
        art.modifiedTime = QDateTime::fromString(date, Qt::ISODateWithMs);
        articles.push_front(art);
    }
}
