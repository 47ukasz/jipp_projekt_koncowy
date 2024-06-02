#include "Note.h"
#include "FileManager.h"
#include "ui_note.h"

Note::Note(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Note)
{
    ui->setupUi(this);
    m_parent = parent;
    handleStyling();

    if(data.stared()) {
        QIcon icon(":/icons/icons/heart.png");
        ui->starBtn->setIcon(icon);
        data.setStared(true);
    } else {
        QIcon icon(":/icons/icons/heart_empty.png");
        ui->starBtn->setIcon(icon);
        data.setStared(false);
    }
}

Note::~Note()
{
    delete ui;
}

NoteData Note::getData() const
{
    return data;
}

void Note::setData(const NoteData &newData)
{
    data = newData;
    ui->titleLabel->setText(data.title());
    ui->typeLabel->setText(data.type());
    ui->contentLabel->setPlainText(data.content());
}

int Note::row() const
{
    return m_row;
}

void Note::setRow(int newRow)
{
    m_row = newRow;
}

int Note::column() const
{
    return m_column;
}

void Note::setColumn(int newColumn)
{
    m_column = newColumn;
}

void Note::handleButtonClickable(bool stared_category)
{
    if (stared_category) {
        ui->starBtn->setEnabled(false);
    } else {
        ui->starBtn->setEnabled(true);
    }
}

void Note::handleStyling()
{
    setAttribute(Qt::WA_StyledBackground, true);
    ui->starBtn->setStyleSheet("QPushButton {background-color: rgb(58, 71, 80); border: none; padding: 5px; border-radius: 5px;}");
    ui->saveBtn->setStyleSheet("QPushButton {background-color: rgb(58, 71, 80); border: none; padding: 5px; border-radius: 5px;}");
    ui->titleLabel->setMinimumSize(QSize(30, 30));
    ui->titleLabel->setStyleSheet("QLabel {color: rgb(243, 243, 243); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px;}");
    ui->contentLabel->setStyleSheet("QPlainTextEdit {background-color: rgb(58, 71, 80); color: rgb(243, 243, 243); padding: 5px; margin-top: 10px; margin-bottom: 10px;}");
    ui->typeLabel->setStyleSheet("QLabel {color: rgb(33, 133, 213); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px;}");
    ui->editBtn->setStyleSheet("QPushButton {background-color: rgb(33, 133, 213); color: rgb(243, 243, 243); padding: 7px; font-weight: bold; margin-right: 10px;}");
    ui->deleteBtn->setStyleSheet("QPushButton {background-color: rgb(226, 24, 24); color: rgb(243, 243, 243); padding: 7px; font-weight: bold}");
    setStyleSheet("QWidget {border-radius: 5px; background-color: rgb(48, 56, 65);}");
}

void Note::on_editBtn_clicked()
{
    NoteDialog * edit_dialog = new NoteDialog(m_parent, "Edytuj notatke");
    int response;
    edit_dialog->setNewNote(data);
    connect(edit_dialog, SIGNAL(requestData(NoteDialog*)), m_parent, SLOT(onRequestData(NoteDialog*)));
    edit_dialog->init();
    edit_dialog->loadData();
    response = edit_dialog->exec();

    if (response) {
        Notify * notify = new Notify(m_parent, "Edytowano notatke");
        notify->show();
        setData(edit_dialog->newNote());
    }

}

void Note::on_deleteBtn_clicked()
{
    emit deleteNote(this);
}


void Note::on_starBtn_clicked()
{
    if (!stared_category) {
        if(!data.stared()) {
            QIcon icon(":/icons/icons/heart.png");
            ui->starBtn->setIcon(icon);
            data.setStared(true);
        } else {
            QIcon icon(":/icons/icons/heart_empty.png");
            ui->starBtn->setIcon(icon);
            data.setStared(false);
        }
    }
}


void Note::on_saveBtn_clicked()
{
    FileManager file_manager;
    file_manager.saveOneToFile(this);
    Notify * notify = new Notify(m_parent, "Zapisano notatke");
    notify->show();
}

