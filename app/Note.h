#ifndef NOTE_H
#define NOTE_H

#include <QWidget>
#include <QIcon>
#include <QPalette>
#include "NoteDialog.h"
#include "NoteData.h"
#include "Notify.h"

namespace Ui {
class Note;
}

class Note : public QWidget
{
    Q_OBJECT

public:
    explicit Note(QWidget *parent = nullptr);
    ~Note();

    NoteData getData() const;
    void setData(const NoteData &newData);
    int row() const;
    void setRow(int newRow);
    int column() const;
    void setColumn(int newColumn);
    void handleButtonClickable(bool stared_category);
    void handleStyling();
private:
    Ui::Note *ui;
    NoteData data;
    QWidget * m_parent;
    int m_row;
    int m_column;
    bool stared_category = false;
signals:
    void deleteNote(Note * note);
private slots:
    void on_editBtn_clicked();
    void on_deleteBtn_clicked();
    void on_starBtn_clicked();
    void on_saveBtn_clicked();
};

#endif // NOTE_H
