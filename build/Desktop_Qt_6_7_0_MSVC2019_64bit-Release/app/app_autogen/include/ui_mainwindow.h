/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QPushButton *allBtn;
    QPushButton *favBtn;
    QHBoxLayout *horizontalLayout;
    QPushButton *searchBtn;
    QLineEdit *searchInput;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *noteSpace;
    QWidget *menu;
    QGridLayout *gridLayout_2;
    QPushButton *addType;
    QPushButton *addBtn;
    QPushButton *saveAll;
    QSpacerItem *verticalSpacer;
    QPushButton *uploadBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 700);
        MainWindow->setMinimumSize(QSize(1000, 700));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 50));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName("gridLayout_3");
        allBtn = new QPushButton(widget);
        allBtn->setObjectName("allBtn");

        gridLayout_3->addWidget(allBtn, 0, 2, 1, 1);

        favBtn = new QPushButton(widget);
        favBtn->setObjectName("favBtn");

        gridLayout_3->addWidget(favBtn, 0, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        searchBtn = new QPushButton(widget);
        searchBtn->setObjectName("searchBtn");
        searchBtn->setMinimumSize(QSize(0, 30));
        searchBtn->setMaximumSize(QSize(16777215, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/search.png"), QSize(), QIcon::Normal, QIcon::On);
        searchBtn->setIcon(icon);

        horizontalLayout->addWidget(searchBtn);

        searchInput = new QLineEdit(widget);
        searchInput->setObjectName("searchInput");
        searchInput->setMinimumSize(QSize(0, 30));
        searchInput->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(searchInput);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);


        verticalLayout_3->addWidget(widget);

        scrollArea = new QScrollArea(widget_2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 858, 606));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        noteSpace = new QGridLayout();
        noteSpace->setObjectName("noteSpace");

        verticalLayout_2->addLayout(noteSpace);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        gridLayout->addWidget(widget_2, 0, 1, 1, 1);

        menu = new QWidget(centralwidget);
        menu->setObjectName("menu");
        menu->setMaximumSize(QSize(100, 16777215));
        gridLayout_2 = new QGridLayout(menu);
        gridLayout_2->setObjectName("gridLayout_2");
        addType = new QPushButton(menu);
        addType->setObjectName("addType");

        gridLayout_2->addWidget(addType, 1, 0, 1, 1);

        addBtn = new QPushButton(menu);
        addBtn->setObjectName("addBtn");

        gridLayout_2->addWidget(addBtn, 0, 0, 1, 1);

        saveAll = new QPushButton(menu);
        saveAll->setObjectName("saveAll");

        gridLayout_2->addWidget(saveAll, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 6, 0, 1, 1);

        uploadBtn = new QPushButton(menu);
        uploadBtn->setObjectName("uploadBtn");

        gridLayout_2->addWidget(uploadBtn, 5, 0, 1, 1);


        gridLayout->addWidget(menu, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        allBtn->setText(QCoreApplication::translate("MainWindow", "Wszystkie", nullptr));
        favBtn->setText(QCoreApplication::translate("MainWindow", "Ulubione", nullptr));
        searchBtn->setText(QString());
        addType->setText(QCoreApplication::translate("MainWindow", "Dodaj rodzaj", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        saveAll->setText(QCoreApplication::translate("MainWindow", "Zapisz (ALL)", nullptr));
        uploadBtn->setText(QCoreApplication::translate("MainWindow", "Wczytaj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
