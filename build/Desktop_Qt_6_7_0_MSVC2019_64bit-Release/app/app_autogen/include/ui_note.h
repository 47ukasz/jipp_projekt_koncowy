/********************************************************************************
** Form generated from reading UI file 'note.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTE_H
#define UI_NOTE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Note
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *titleLabel;
    QLabel *typeLabel;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *saveBtn;
    QPushButton *starBtn;
    QPlainTextEdit *contentLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *editBtn;
    QPushButton *deleteBtn;

    void setupUi(QWidget *Note)
    {
        if (Note->objectName().isEmpty())
            Note->setObjectName("Note");
        Note->resize(290, 280);
        Note->setMinimumSize(QSize(145, 280));
        Note->setMaximumSize(QSize(290, 280));
        verticalLayout = new QVBoxLayout(Note);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        titleLabel = new QLabel(Note);
        titleLabel->setObjectName("titleLabel");
        QFont font;
        font.setBold(true);
        titleLabel->setFont(font);

        horizontalLayout->addWidget(titleLabel);

        typeLabel = new QLabel(Note);
        typeLabel->setObjectName("typeLabel");
        QFont font1;
        font1.setItalic(true);
        typeLabel->setFont(font1);

        horizontalLayout->addWidget(typeLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        saveBtn = new QPushButton(Note);
        saveBtn->setObjectName("saveBtn");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/download.png"), QSize(), QIcon::Normal, QIcon::On);
        saveBtn->setIcon(icon);

        horizontalLayout->addWidget(saveBtn);

        starBtn = new QPushButton(Note);
        starBtn->setObjectName("starBtn");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/star_empty_theme.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/icons/icons/heart_empty.png"), QSize(), QIcon::Normal, QIcon::On);
        starBtn->setIcon(icon1);
        starBtn->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(starBtn);


        verticalLayout->addLayout(horizontalLayout);

        contentLabel = new QPlainTextEdit(Note);
        contentLabel->setObjectName("contentLabel");
        contentLabel->setReadOnly(true);

        verticalLayout->addWidget(contentLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        editBtn = new QPushButton(Note);
        editBtn->setObjectName("editBtn");

        horizontalLayout_2->addWidget(editBtn);

        deleteBtn = new QPushButton(Note);
        deleteBtn->setObjectName("deleteBtn");

        horizontalLayout_2->addWidget(deleteBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Note);

        QMetaObject::connectSlotsByName(Note);
    } // setupUi

    void retranslateUi(QWidget *Note)
    {
        Note->setWindowTitle(QCoreApplication::translate("Note", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("Note", "Nazwa Notatki", nullptr));
        typeLabel->setText(QCoreApplication::translate("Note", "Typ Notatki", nullptr));
        saveBtn->setText(QString());
        starBtn->setText(QString());
        editBtn->setText(QCoreApplication::translate("Note", "Edytuj", nullptr));
        deleteBtn->setText(QCoreApplication::translate("Note", "Usu\305\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Note: public Ui_Note {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTE_H
