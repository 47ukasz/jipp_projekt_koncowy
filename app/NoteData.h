#ifndef NOTEDATA_H
#define NOTEDATA_H

#include <QString>

class NoteData
{
private:
    QString m_title;
    QString m_type;
    QString m_content;
    bool m_stared = false;
public:
    NoteData();
    QString title() const;
    void setTitle(const QString &newTitle);
    QString type() const;
    void setType(const QString &newType);
    QString content() const;
    void setContent(const QString &newContent);
    bool stared() const;
    void setStared(bool newStared);
};

#endif // NOTEDATA_H
