#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Lib lib;
    lib.hello();
    handleStyling();
    setWindowTitle("Fast Notes");
    setWindowIcon(QIcon(":/icons/icons/app_logo.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNoteToLayout(Note *item)
{
    Notify * notify = new Notify(this, "Dodano notatke");
    ui->noteSpace->addWidget(item, m_row, m_column);
    item->setRow(m_row);
    item->setColumn(m_column);
    m_layoutList.append(item);

    notify->show();

    if (m_column == 2) {
        m_column = 0;
        m_row = m_row + 1;
    } else {
        m_column += 1;
    }
}

void MainWindow::renderLayout()
{
    Note * lastItem = NULL;
    m_row = 0;
    m_column = 0;

    for (auto note : m_layoutList) {
        note->setColumn(m_column);
        note->setRow(m_row);
        ui->noteSpace->addWidget(note, note->row(), note->column());
        note->show();

        if (m_column == 2) {
            m_row++;
            m_column = 0;
        } else {
            m_column++;
        }
    }

    lastItem = m_layoutList[m_layoutList.length() - 1];

    if (lastItem->column() == 2) {
        m_column = 0;
        m_row = lastItem->row() + 1;
    } else {
        m_column = lastItem->column() + 1;
        m_row = lastItem->row();
    }
}



void MainWindow::reloadLayout(int index)
{
    Note * currentItem = NULL;
    Note * lastItem = NULL;
    int currentRow = 0;
    int currentCol = 0;

    for (int i = index; i < m_layoutList.length(); i++) {
        currentItem = m_layoutList[i];
        currentRow = currentItem->row();
        currentCol = currentItem->column();

        if (currentCol == 0) {
            currentItem->setColumn(2);
            currentItem->setRow(currentRow - 1);
        } else {
            currentItem->setColumn(currentCol - 1);
        }
        ui->noteSpace->removeWidget(currentItem);
        ui->noteSpace->addWidget(currentItem, currentItem->row(), currentItem->column());
    }

    lastItem = m_layoutList[m_layoutList.length() - 1];

    if (lastItem->column() == 2) {
        m_column = 0;
        m_row = lastItem->row() + 1;
    } else {
        m_column = lastItem->column() + 1;
        m_row = lastItem->row();
    }
}

void MainWindow::onDeleteLayoutNote(Note *item)
{
    Notify * notify = new Notify(this, "Usunieto notatke");
    int index = 0;

    notify->show();

    if (item == m_layoutList[0] && m_layoutList.length() == 1) {
        item->hide();
        ui->noteSpace->removeWidget(item);
        m_column = 0;
        m_row = 0;
        m_layoutList.erase(m_layoutList.begin());
        onDeleteVectorNote(item);
        return;
    }

    if (item == m_layoutList[m_layoutList.length() - 1]) {
        item->hide();
        ui->noteSpace->removeWidget(item);
        m_layoutList.erase(m_layoutList.end() - 1);
        m_column = item->column();
        m_row = item->row();
        onDeleteVectorNote(item);
        return;
    }

    QVector<Note *>::Iterator ptr;

    for (ptr = m_layoutList.begin(); ptr < m_layoutList.end(); ptr++) {
        if (*ptr == item) {
            index++;
            break;
        }
        index++;
    }

    reloadLayout(index);
    item->hide();
    m_layoutList.erase(ptr);
    onDeleteVectorNote(item);
    return;
}

void MainWindow::on_favBtn_clicked()
{
    m_favMode = true;

    ui->favBtn->setStyleSheet("QPushButton {background-color: rgb(33, 133, 213); border-radius: 5px; border: none; padding: 10px; color: rgb(243, 243, 243);}");
    ui->allBtn->setStyleSheet("QPushButton {background-color: rgb(58, 71, 80); border-radius: 5px; border: none; padding: 10px; color: rgb(243, 243, 243); margin-right: 10px;}");
    for (auto note : m_layoutList) {
        note->hide();
        ui->noteSpace->removeWidget(note);
    }

    m_layoutList.clear();

    for (auto note : m_notesList) {
        if (note->getData().stared()) {
            m_layoutList.append(note);
            note->handleButtonClickable(m_favMode);
        }
    }

    if (m_layoutList.length()) {
        renderLayout();
    }
}

void MainWindow::on_allBtn_clicked()
{
    m_favMode = false;

    ui->favBtn->setStyleSheet("QPushButton {background-color: rgb(58, 71, 80); border-radius: 5px; border: none; padding: 10px; color: rgb(243, 243, 243);}");
    ui->allBtn->setStyleSheet("QPushButton {background-color: rgb(33, 133, 213); border-radius: 5px; border: none; padding: 10px; color: rgb(243, 243, 243); margin-right: 10px;}");

    for (auto note : m_layoutList) {
        note->hide();
        note->handleButtonClickable(m_favMode);
        ui->noteSpace->removeWidget(note);
    }

    m_layoutList.clear();

    for (auto note : m_notesList) {
        m_layoutList.append(note);
    }

    if (m_layoutList.length()) {
        renderLayout();
    }
}

void MainWindow::onDeleteVectorNote(Note *item)
{
    QVector<Note *>::Iterator ptr;

    for (ptr = m_notesList.begin(); ptr < m_notesList.end(); ptr++) {
        if (*ptr == item) {
            m_notesList.erase(ptr);
            delete item;
            break;
        }
    }
}

void MainWindow::on_searchInput_textChanged(const QString &arg1)
{
    if (!m_notesList.length()) {
        return;
    }

    if (arg1 == "") {
        m_searchMode = false;
    } else {
        m_searchMode = true;
    }

    for (auto note : m_layoutList) {
        note->hide();
        ui->noteSpace->removeWidget(note);
    }

    m_layoutList.clear();

    if (m_favMode) {
        for (auto note : m_notesList) {
            if (note->getData().stared() && note->getData().title().contains(arg1)) {
                m_layoutList.append(note);
            }
        }
    } else {
        for (auto note : m_notesList) {
            if (note->getData().title().contains(arg1)) {
                m_layoutList.append(note);
            }
        }
    }

    if (m_layoutList.length()) {
        renderLayout();
    }
}

void MainWindow::on_saveAll_clicked()
{
    if (m_notesList.length()) {
        FileManager file_manager;
        file_manager.saveToFile(m_notesList);
        Notify * notify = new Notify(this, "Zapisano notatki");
        notify->show();
    } else {
        Notify * notify = new Notify(this, "Brak notatek");
        notify->show();
    }
}

void MainWindow::on_addBtn_clicked()
{
    NoteDialog * add_dialog = new NoteDialog(this, "Dodaj notatke");
    Note * note = new Note(this);
    int response;

    connect(add_dialog, SIGNAL(requestData(NoteDialog*)), this, SLOT(onRequestData(NoteDialog*)));
    add_dialog->loadData();
    response = add_dialog->exec();

    if (response) {
        note->setData(add_dialog->newNote());
        m_notesList.append(note);
        connect(note, SIGNAL(deleteNote(Note*)), this, SLOT(onDeleteLayoutNote(Note*)));

        if (!(m_searchMode ^ m_favMode)) {
            addNoteToLayout(note);
        }
    }

    delete add_dialog;
}

void MainWindow::on_addType_clicked()
{
    TypeDialog * type_dialog = new TypeDialog(this);
    int response;

    response = type_dialog->exec();

    if (response) {
        Notify * notify = new Notify(this, "Dodano rodzaj");
        notify->show();
        m_typeList.append(type_dialog->getInputValue());
    }

    delete type_dialog;
}

void MainWindow::onRequestData(NoteDialog *dialog)
{
    dialog->setTypeList(m_typeList);
}

void MainWindow::on_uploadBtn_clicked()
{
    FileManager fileManager;
    QString filePath = QFileDialog::getOpenFileName(this, "Wybierz plik", "");
    Note * note = new Note(this);

    if (filePath == "") {
        return;
    }

    if(!fileManager.uploadFile(filePath, note)) {
        delete note;
        return;
    }

    Notify * notify = new Notify(this, "Wczytano notatke");
    notify->show();

    m_notesList.append(note);
    connect(note, SIGNAL(deleteNote(Note*)), this, SLOT(onDeleteLayoutNote(Note*)));

    if (!(m_searchMode ^ m_favMode)) {
        addNoteToLayout(note);
    }
}

void MainWindow::handleStyling()
{
    ui->noteSpace->setSpacing(20);
    ui->searchBtn->setStyleSheet("QPushButton {background-color: rgb(48, 56, 65); border-top-left-radius: 5px; border-bottom-left-radius: 5px; padding: 5px;}");
    ui->searchInput->setStyleSheet("QLineEdit {background-color: rgb(48, 56, 65); border-top-right-radius: 5px; border-bottom-right-radius: 5px; color: rgb(243, 243, 243); padding: 5px;}");
    ui->centralwidget->setStyleSheet("QWidget {background-color: rgb(30, 35, 41);}");
    ui->allBtn->setStyleSheet("QPushButton {background-color: rgb(33, 133, 213); border-radius: 5px; border: none; padding: 10px; color: rgb(243, 243, 243); margin-right: 10px;}");
    ui->favBtn->setStyleSheet("QPushButton {background-color: rgb(58, 71, 80); border-radius: 5px; border: none; padding: 10px; color: rgb(243, 243, 243);}");
    ui->scrollArea->setStyleSheet(
        "QScrollArea {"
        "    border:none;"
        "    background: white;"
        "}"
        "QScrollBar:vertical {"
        "    background: rgb(58, 71, 80);" // tyl suwaka
        "    width: 16px;"
        "    margin: 22px 0 22px 0;"
        "    padding: 5px 3px;"
        "    border-radius: 5px;"
        "}"
        "QScrollBar::handle:vertical {"
        "    border-radius: 5px;"
        "    background: rgb(33, 133, 213);" // suwak
        "    min-height: 20px;"
        "}"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
        "    border: none;"
        "    background: none;"
        "    height: 0px;"
        "}"
        "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {"
        "    border: none;"
        "    background: none;"
        "}"
        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
        "    background: none;"
        "}"
        );
    ui->menu->setStyleSheet("QWidget {background-color: rgb(48, 56, 65); border-radius: 5px;} QPushButton {background-color: rgb(58, 71, 80); border-radius: 5px; border: none; padding: 5px; margin-bottom: 15px; color: rgb(243, 243, 243);}");
}
