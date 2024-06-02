#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QString>
#include <QStandardPaths>
#include <QDir>
#include <QVector>
#include "Note.h"
#include "NoteData.h"

class FileManager
{
public:
    FileManager();
    void saveToFile(QVector<Note*> & notesList);
    void saveOneToFile(Note * item);
    bool uploadFile(QString filePath, Note * note);
private:
    QString m_DirPath;
    QString createDirectory();
};

#endif // FILEMANAGER_H
