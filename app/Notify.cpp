#include "Notify.h"
#include "ui_notify.h"

Notify::Notify(QWidget *parent, QString text)
    : QWidget(parent)
    , ui(new Ui::Notify)
{
    ui->setupUi(this);
    handleStyling();
    setPosition(parent, 250, 25);
    ui->textNotify->setText(text);
    QTimer::singleShot(3000, this, &QObject::deleteLater);
}

Notify::~Notify()
{
    delete ui;
}

void Notify::setPosition(QWidget *parent, int x, int y)
{
    int parentWidth = parent->width();

    this->move(parentWidth - this->width() - x, y);
}

void Notify::handleStyling()
{
    setAttribute(Qt::WA_StyledBackground, true);
    this->setStyleSheet("QWidget {background-color: rgb(48, 56, 65); border-radius: 5px;}");
    ui->textNotify->setStyleSheet("QLineEdit {color: rgb(243, 243, 243); margin-left: 10px;}");
}

void Notify::on_closeBtn_clicked()
{
    this->hide();
}

