#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QFileDialog>
#include "NoteDialog.h"
#include "FileManager.h"
#include "Note.h"
#include "TypeDialog.h"
#include "Notify.h"
#include "../lib/Lib.h"
#include "../lib/lib_global.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDeleteLayoutNote(Note * item);
    void on_addBtn_clicked();
    void on_favBtn_clicked();
    void on_allBtn_clicked();
    void on_searchInput_textChanged(const QString &arg1);
    void onRequestData(NoteDialog * dialog);
    void on_saveAll_clicked();
    void on_addType_clicked();

    void on_uploadBtn_clicked();

private:
    int m_row = 0;
    int m_column = 0;
    bool m_favMode = false;
    bool m_searchMode = false;
    QVector<Note *> m_notesList;
    QVector<Note *> m_layoutList;
    QVector<QString> m_typeList = {"Praca", "Dom", "Szkola", "Hobby", "Zakupy"};
    void onDeleteVectorNote(Note * item);
    void addNoteToLayout(Note * item);
    void reloadLayout(int index);
    void renderLayout();
    void handleStyling();

    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
