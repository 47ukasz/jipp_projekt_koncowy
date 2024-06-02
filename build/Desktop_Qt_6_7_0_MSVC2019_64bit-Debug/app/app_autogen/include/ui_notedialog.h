/********************************************************************************
** Form generated from reading UI file 'notedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEDIALOG_H
#define UI_NOTEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NoteDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLineEdit *nameInput;
    QLabel *typeLabel;
    QComboBox *typeCombo;
    QVBoxLayout *verticalLayout_3;
    QLabel *contentLabel;
    QPlainTextEdit *contentInput;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *functionalBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *NoteDialog)
    {
        if (NoteDialog->objectName().isEmpty())
            NoteDialog->setObjectName("NoteDialog");
        NoteDialog->resize(376, 388);
        verticalLayout_4 = new QVBoxLayout(NoteDialog);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        nameLabel = new QLabel(NoteDialog);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setMinimumSize(QSize(0, 0));
        nameLabel->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(nameLabel);

        nameInput = new QLineEdit(NoteDialog);
        nameInput->setObjectName("nameInput");

        verticalLayout->addWidget(nameInput);


        verticalLayout_2->addLayout(verticalLayout);

        typeLabel = new QLabel(NoteDialog);
        typeLabel->setObjectName("typeLabel");
        typeLabel->setMinimumSize(QSize(0, 0));
        typeLabel->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(typeLabel);

        typeCombo = new QComboBox(NoteDialog);
        typeCombo->addItem(QString());
        typeCombo->addItem(QString());
        typeCombo->addItem(QString());
        typeCombo->addItem(QString());
        typeCombo->addItem(QString());
        typeCombo->setObjectName("typeCombo");

        verticalLayout_2->addWidget(typeCombo);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        contentLabel = new QLabel(NoteDialog);
        contentLabel->setObjectName("contentLabel");
        contentLabel->setMinimumSize(QSize(0, 0));
        contentLabel->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(contentLabel);

        contentInput = new QPlainTextEdit(NoteDialog);
        contentInput->setObjectName("contentInput");

        verticalLayout_3->addWidget(contentInput);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        functionalBtn = new QPushButton(NoteDialog);
        functionalBtn->setObjectName("functionalBtn");

        horizontalLayout_3->addWidget(functionalBtn);

        cancelBtn = new QPushButton(NoteDialog);
        cancelBtn->setObjectName("cancelBtn");

        horizontalLayout_3->addWidget(cancelBtn);


        verticalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(NoteDialog);

        QMetaObject::connectSlotsByName(NoteDialog);
    } // setupUi

    void retranslateUi(QDialog *NoteDialog)
    {
        NoteDialog->setWindowTitle(QCoreApplication::translate("NoteDialog", "Dialog", nullptr));
        nameLabel->setText(QCoreApplication::translate("NoteDialog", "Nazwa", nullptr));
        typeLabel->setText(QCoreApplication::translate("NoteDialog", "Rodzaj", nullptr));
        typeCombo->setItemText(0, QCoreApplication::translate("NoteDialog", "Praca", nullptr));
        typeCombo->setItemText(1, QCoreApplication::translate("NoteDialog", "Szko\305\202a", nullptr));
        typeCombo->setItemText(2, QCoreApplication::translate("NoteDialog", "Hobby", nullptr));
        typeCombo->setItemText(3, QCoreApplication::translate("NoteDialog", "Dom", nullptr));
        typeCombo->setItemText(4, QCoreApplication::translate("NoteDialog", "Zakupy", nullptr));

        contentLabel->setText(QCoreApplication::translate("NoteDialog", "Tre\305\233\304\207", nullptr));
        functionalBtn->setText(QCoreApplication::translate("NoteDialog", "Funkcja", nullptr));
        cancelBtn->setText(QCoreApplication::translate("NoteDialog", "Anuluj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoteDialog: public Ui_NoteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEDIALOG_H
