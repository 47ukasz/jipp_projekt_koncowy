#include "TypeDialog.h"
#include "ui_typedialog.h"

TypeDialog::TypeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TypeDialog)
{
    ui->setupUi(this);
    handleStyling();
}

TypeDialog::~TypeDialog()
{
    delete ui;
}

QString TypeDialog::getInputValue() const
{
    return inputValue;
}

void TypeDialog::setInputValue(const QString &newInputValue)
{
    inputValue = newInputValue;
}

void TypeDialog::on_addBtn_clicked()
{
    inputValue = ui->typeInput->text();


    if (!inputValue.length()) {
        ui->typeInput->setStyleSheet("QLineEdit {color: rgb(243, 243, 243); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px; border: 1px solid rgb(226, 24, 24);}");
    } else {
        accept();
    }
}


void TypeDialog::on_cancelBtn_clicked()
{
    reject();
}


void TypeDialog::on_typeInput_textChanged(const QString &arg1)
{
    if (arg1.length()) {
        ui->typeInput->setStyleSheet("QLineEdit {color: rgb(243, 243, 243); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px;}");
    }
}

void TypeDialog::handleStyling()
{
    setStyleSheet("QDialog {background-color: rgb(48, 56, 65);}");
    ui->addBtn->setStyleSheet("QPushButton {background-color: rgb(33, 133, 213); color: rgb(243, 243, 243); padding: 7px; font-weight: bold; margin-right: 10px; border-radius: 5px;}");
    ui->cancelBtn->setStyleSheet("QPushButton {background-color: rgb(226, 24, 24); color: rgb(243, 243, 243); padding: 7px; font-weight: bold; border-radius: 5px;}");
    ui->typeLabel->setStyleSheet("QLabel {color: rgb(33, 133, 213); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px; font-weight: bold;}");
    ui->typeInput->setStyleSheet("QLineEdit {color: rgb(243, 243, 243); background-color: rgb(58, 71, 80); padding: 5px; border-radius: 5px;}");
    setWindowTitle("Dodaj rodzaj");
    setWindowIcon(QIcon(":/icons/icons/app_logo.png"));
}

