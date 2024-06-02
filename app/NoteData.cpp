#include "NoteData.h"

QString NoteData::title() const
{
    return m_title;
}

void NoteData::setTitle(const QString &newTitle)
{
    m_title = newTitle;
}

QString NoteData::type() const
{
    return m_type;
}

void NoteData::setType(const QString &newType)
{
    m_type = newType;
}

QString NoteData::content() const
{
    return m_content;
}

void NoteData::setContent(const QString &newContent)
{
    m_content = newContent;
}

bool NoteData::stared() const
{
    return m_stared;
}

void NoteData::setStared(bool newStared)
{
    m_stared = newStared;
}

NoteData::NoteData() {}
