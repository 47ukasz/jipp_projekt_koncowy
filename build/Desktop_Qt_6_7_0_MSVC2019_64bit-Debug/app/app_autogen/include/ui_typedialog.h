/********************************************************************************
** Form generated from reading UI file 'typedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TYPEDIALOG_H
#define UI_TYPEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TypeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *typeLabel;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *typeInput;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *TypeDialog)
    {
        if (TypeDialog->objectName().isEmpty())
            TypeDialog->setObjectName("TypeDialog");
        TypeDialog->resize(250, 110);
        TypeDialog->setMinimumSize(QSize(250, 110));
        TypeDialog->setMaximumSize(QSize(250, 110));
        verticalLayout = new QVBoxLayout(TypeDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        typeLabel = new QLabel(TypeDialog);
        typeLabel->setObjectName("typeLabel");

        horizontalLayout->addWidget(typeLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        typeInput = new QLineEdit(TypeDialog);
        typeInput->setObjectName("typeInput");

        horizontalLayout->addWidget(typeInput);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        addBtn = new QPushButton(TypeDialog);
        addBtn->setObjectName("addBtn");

        horizontalLayout_2->addWidget(addBtn);

        cancelBtn = new QPushButton(TypeDialog);
        cancelBtn->setObjectName("cancelBtn");

        horizontalLayout_2->addWidget(cancelBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(TypeDialog);

        QMetaObject::connectSlotsByName(TypeDialog);
    } // setupUi

    void retranslateUi(QDialog *TypeDialog)
    {
        TypeDialog->setWindowTitle(QCoreApplication::translate("TypeDialog", "Dialog", nullptr));
        typeLabel->setText(QCoreApplication::translate("TypeDialog", "Rodzaj", nullptr));
        addBtn->setText(QCoreApplication::translate("TypeDialog", "Dodaj", nullptr));
        cancelBtn->setText(QCoreApplication::translate("TypeDialog", "Anuluj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TypeDialog: public Ui_TypeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TYPEDIALOG_H
