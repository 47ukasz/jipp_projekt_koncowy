/********************************************************************************
** Form generated from reading UI file 'notify.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFY_H
#define UI_NOTIFY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notify
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *iconNotify;
    QLineEdit *textNotify;
    QPushButton *closeBtn;

    void setupUi(QWidget *Notify)
    {
        if (Notify->objectName().isEmpty())
            Notify->setObjectName("Notify");
        Notify->resize(200, 40);
        Notify->setMinimumSize(QSize(200, 0));
        Notify->setMaximumSize(QSize(250, 40));
        horizontalLayout_2 = new QHBoxLayout(Notify);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        iconNotify = new QLabel(Notify);
        iconNotify->setObjectName("iconNotify");
        iconNotify->setMaximumSize(QSize(16777215, 20));
        iconNotify->setPixmap(QPixmap(QString::fromUtf8(":/icons/icons/exclamation.png")));

        horizontalLayout->addWidget(iconNotify);

        textNotify = new QLineEdit(Notify);
        textNotify->setObjectName("textNotify");
        textNotify->setEnabled(false);
        textNotify->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(textNotify);


        horizontalLayout_2->addLayout(horizontalLayout);

        closeBtn = new QPushButton(Notify);
        closeBtn->setObjectName("closeBtn");
        closeBtn->setMaximumSize(QSize(16777215, 20));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/close.png"), QSize(), QIcon::Normal, QIcon::On);
        closeBtn->setIcon(icon);

        horizontalLayout_2->addWidget(closeBtn);


        retranslateUi(Notify);

        QMetaObject::connectSlotsByName(Notify);
    } // setupUi

    void retranslateUi(QWidget *Notify)
    {
        Notify->setWindowTitle(QCoreApplication::translate("Notify", "Form", nullptr));
        iconNotify->setText(QString());
        closeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Notify: public Ui_Notify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFY_H
