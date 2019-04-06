/********************************************************************************
** Form generated from reading UI file 'farey_series.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAREY_SERIES_H
#define UI_FAREY_SERIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Farey_SeriesClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Farey_SeriesClass)
    {
        if (Farey_SeriesClass->objectName().isEmpty())
            Farey_SeriesClass->setObjectName(QStringLiteral("Farey_SeriesClass"));
        Farey_SeriesClass->resize(589, 443);
        centralWidget = new QWidget(Farey_SeriesClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        Farey_SeriesClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Farey_SeriesClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 589, 26));
        Farey_SeriesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Farey_SeriesClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Farey_SeriesClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Farey_SeriesClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Farey_SeriesClass->setStatusBar(statusBar);

        retranslateUi(Farey_SeriesClass);

        QMetaObject::connectSlotsByName(Farey_SeriesClass);
    } // setupUi

    void retranslateUi(QMainWindow *Farey_SeriesClass)
    {
        Farey_SeriesClass->setWindowTitle(QApplication::translate("Farey_SeriesClass", "\346\263\225\351\233\267\345\272\217\345\210\227", 0));
        label->setText(QApplication::translate("Farey_SeriesClass", "\347\272\247\346\225\260\357\274\232", 0));
        pushButton->setText(QApplication::translate("Farey_SeriesClass", "\350\256\241\347\256\227", 0));
        pushButton_2->setText(QApplication::translate("Farey_SeriesClass", "\346\230\276\347\244\272", 0));
    } // retranslateUi

};

namespace Ui {
    class Farey_SeriesClass: public Ui_Farey_SeriesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAREY_SERIES_H
