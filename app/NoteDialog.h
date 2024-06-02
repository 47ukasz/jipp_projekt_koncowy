#ifndef NOTEDIALOG_H
#define NOTEDIALOG_H

#include <QDialog>
#include "NoteData.h"
#include <QPoint>

namespace Ui {
class NoteDialog;
}

class NoteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NoteDialog(QWidget *parent = nullptr, QString dialogTitle = "");
    ~NoteDialog();

    NoteData newNote() const;
    void setNewNote(const NoteData &newNewNote);
    void init();

    QVector<QString> typeList() const;
    void setTypeList(const QVector<QString> &newTypeList);

    void loadData();
private slots:
    void on_functionalBtn_clicked();
    void on_contentInput_textChanged();
    void on_nameInput_textChanged(const QString &arg1);
    void on_cancelBtn_clicked();
    void handleStyling();
signals:
    void requestData(NoteDialog * dialog);
private:
    Ui::NoteDialog *ui;
    NoteData m_newNote;
    bool handleValidate(QString value);
    QVector<QString> m_typeList;

};

#endif // NOTEDIALOG_H
