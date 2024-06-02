#include "FileManager.h"

FileManager::FileManager() {
    m_DirPath = createDirectory();
}

void FileManager::saveToFile(QVector<Note *> &notesList)
{
    QString filePath = m_DirPath + "/" + "notatki-backup.txt";
    QString staredText;

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        for (auto note : notesList) {
            staredText = note->getData().stared() ? "Tak" : "Nie";
            out << "Tytul: " << note->getData().title() << "\nRodzaj: " << note->getData().type() << "\nPolubione: " << staredText << "\nTresc: " << note->getData().content() << "\n";
        }

        file.close();
    } else {
        qWarning("Nie można otworzyć pliku do zapisu.");
    }
}

void FileManager::saveOneToFile(Note *item)
{
    QString filePath = m_DirPath + "/" + item->getData().title() + "-backup.txt";
    QString staredText;

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        staredText = item->getData().stared() ? "Tak" : "Nie";
        out << "Tytul: " << item->getData().title() << "\nRodzaj: " << item->getData().type() << "\nPolubione: " << staredText << "\nTresc: " << item->getData().content() << "\n";

        file.close();
    } else {
        qWarning("Nie można otworzyć pliku do zapisu.");
    }
}

bool FileManager::uploadFile(QString filePath, Note * note)
{
    NoteData fileData;
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text) || !filePath.contains("-backup.txt")) {
        qDebug() << "Nie można otworzyć pliku:" << file.errorString();
        return false;
    }

    QTextStream in(&file);
    QStringList lineList = in.readAll().split("\n");
    QString value;

    for (int i = 0; i < lineList.length() - 1; i++) {
        value = lineList[i].split(":")[1];
        value = value.trimmed();

        switch(i) {
        case 0:
            fileData.setTitle(value);
            break;
        case 1:
            fileData.setType(value);
            break;
        case 2:
            fileData.setStared(value == "Tak" ? true : false);
            break;
        case 3:
            fileData.setContent(value);
            break;
        }
    }

    note->setData(fileData);

    file.close();
}

QString FileManager::createDirectory()
{
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString fullPath = desktopPath + "/" + "notatki_pobrane";
    QDir dir;

    if (!dir.exists(fullPath)) {
        if (dir.mkpath(fullPath)) {
            qDebug() << "Folder stworzony: " << fullPath;
        } else {
            qDebug() << "Blad tworzenia folderu: " << fullPath;
        }
    } else {
        qDebug() << "Folder istnieje: " << fullPath;
    }

    return fullPath;
}
