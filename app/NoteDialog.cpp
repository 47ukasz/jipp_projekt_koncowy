#include "NoteDialog.h"
#include "ui_notedialog.h"

NoteDialog::NoteDialog(QWidget *parent, QString dialogTitle)
    : QDialog(parent)
    , ui(new Ui::NoteDialog)
{
    ui->setupUi(this);
    setWindowTitle(dialogTitle);
    setWindowIcon(QIcon(":/icons/icons/app_logo.png"));
    ui->functionalBtn->setText(dialogTitle);
    handleStyling();
}

NoteDialog::~NoteDialog()
{
    delete ui;
}

NoteData NoteDialog::newNote() const
{
    return m_newNote;
}

void NoteDialog::setNewNote(const NoteData &newNewNote)
{
    m_newNote = newNewNote;
}

void NoteDialog::init()
{
    ui->nameInput->setText(m_newNote.title());
    ui->contentInput->setPlainText(m_newNote.content());
    ui->typeCombo->setCurrentText(m_newNote.type());
}

void NoteDialog::on_functionalBtn_clicked()
{
    try {
        bool validateTitle = handleValidate(ui->nameInput->text());
        bool validateContent = handleValidate(ui->contentInput->toPlainText());

        if (!validateTitle && !validateContent) {
            throw 0;
        }

        if (!validateTitle) {
            throw 1;
        }

        if(!validateContent) {
            throw 2;
        }

        if (validateTitle && validateContent) {
            m_newNote.setTitle(ui->nameInput->text());
            m_newNote.setType(ui->typeCombo->currentText());
            m_newNote.setContent(ui->contentInput->toPlainText());
            accept();
        }

    } catch (const int num) {
        switch(num) {
            case 0:
                ui->nameInput->setStyleSheet("QLineEdit {color: rgb(243, 243, 243); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px; border: 1px solid rgb(226, 24, 24); margin-bottom: 10px;}");
                ui->contentInput->setStyleSheet("QPlainTextEdit {color: rgb(243, 243, 243); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px; border: 1px solid rgb(226, 24, 24); margin-bottom: 10px;}");
                break;
            case 1:
                ui->nameInput->setStyleSheet("QLineEdit {color: rgb(243, 243, 243); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px; border: 1px solid rgb(226, 24, 24); margin-bottom: 10px;}");
                break;
            case 2:
                ui->contentInput->setStyleSheet("QPlainTextEdit {color: rgb(243, 243, 243); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px; border: 1px solid rgb(226, 24, 24); margin-bottom: 10px;}");
                break;
            default:
                qInfo() << "Nierozpoznany typ wyjatku...";
                break;
        }
    }
}

void NoteDialog::on_contentInput_textChanged()
{
    ui->contentInput->setStyleSheet("QPlainTextEdit {color: rgb(243, 243, 243); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px; margin-bottom: 10px;}");
}


void NoteDialog::on_nameInput_textChanged(const QString &arg1)
{
    if (arg1.length()) {
        ui->nameInput->setStyleSheet("QLineEdit {color: rgb(243, 243, 243); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px; margin-bottom: 10px;}");
    }
}

bool NoteDialog::handleValidate(QString value)
{
    if (value.length()) {
        return true;
    }

    return false;
}

void NoteDialog::loadData()
{
    emit requestData(this);
    ui->typeCombo->clear();
    for (auto item : m_typeList) {
        ui->typeCombo->addItem(item);
    }
}

QVector<QString> NoteDialog::typeList() const
{
    return m_typeList;
}

void NoteDialog::setTypeList(const QVector<QString> &newTypeList)
{
    m_typeList = newTypeList;
}

void NoteDialog::on_cancelBtn_clicked()
{
    reject();
}

void NoteDialog::handleStyling()
{
    setStyleSheet("QDialog {background-color: rgb(48, 56, 65);}");
    ui->nameLabel->setStyleSheet("QLabel {color: rgb(33, 133, 213); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px; margin-bottom: 5px; font-weight: bold;}");
    ui->typeLabel->setStyleSheet("QLabel {color: rgb(33, 133, 213); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px; margin-bottom: 5px; font-weight: bold;}");
    ui->contentLabel->setStyleSheet("QLabel {color:rgb(33, 133, 213); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px; margin-bottom: 5px; font-weight: bold;}");
    ui->nameInput->setStyleSheet("QLineEdit {color: rgb(243, 243, 243); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px; margin-bottom: 10px;}");
    ui->contentInput->setStyleSheet("QPlainTextEdit {color: rgb(243, 243, 243); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px; margin-bottom: 10px;}");
    ui->functionalBtn->setStyleSheet("QPushButton {background-color: rgb(33, 133, 213); color: rgb(243, 243, 243); padding: 7px; font-weight: bold; margin-right: 10px; border-radius: 5px;}");
    ui->cancelBtn->setStyleSheet("QPushButton {background-color: rgb(226, 24, 24); color: rgb(243, 243, 243); padding: 7px; font-weight: bold; border-radius: 5px;}");

    QString styleSheetCombo =
        "QComboBox {"
        "    color: rgb(243, 243, 243);"
        "    background-color: rgb(58, 71, 80);"
        "    padding: 5px;"
        "    border-radius: 5px;"
        "margin-bottom: 10px;"
        "}"
        "QComboBox::drop-down {"
        "    subcontrol-origin: padding;"
        "    subcontrol-position: top right;"
        "    width: 25px;"
        "    border-top-right-radius: 3px;"
        "    border-bottom-right-radius: 3px;"
        "    background: rgb(33, 133, 213);"
        "}"
        "QComboBox::down-arrow {"
        "    image: url(:/icons/icons/angle-small-down.png);"
        "}"
        "QComboBox QAbstractItemView {"
        "    border: 1px solid #d9d9d9;"
        "    selection-background-color: rgb(33, 133, 213);"
        "    background: rgb(48, 56, 65);"
        "}"
        "QComboBox QAbstractItemView::item {"
        "    color: rgb(243, 243, 243);"
        "    height: 20px;"
        "}"
        "QComboBox QAbstractItemView::item:selected {"
        "    background: rgb(33, 133, 213);"
        "    color: rgb(243, 243, 243);"
        "}";

    ui->typeCombo->setStyleSheet(styleSheetCombo);
}

